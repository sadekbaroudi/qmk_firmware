#!/usr/bin/env python3
"""
fp_build.py — fingerpunch keyboard build matrix driver.

Replaces the old bin/fp_build.sh. The shell script is now a thin wrapper.

Reads a per-keyboard `fp_build.json` describing the build option matrix and
produces `qmk compile` invocations, either interactively, exhaustively, or
pinned via presets / `-s K=V` overrides. After a successful build the
resulting `.uf2` / `.hex` files are renamed to encode the chosen options.

Schema is defined at keyboards/fingerpunch/src/schemas/fp_build.jsonschema.
"""

from __future__ import annotations

import argparse
import json
import os
import re
import shlex
import subprocess
import sys
from dataclasses import dataclass, field
from pathlib import Path
from typing import Callable, Dict, Iterable, List, Optional, Tuple

REPO_ROOT = Path(__file__).resolve().parent.parent
FP_KB_DIR = REPO_ROOT / "keyboards" / "fingerpunch"
SCHEMA_PATH = FP_KB_DIR / "src" / "schemas" / "fp_build.jsonschema"


# ---------------------------------------------------------------------------
# Keyboard discovery (mirrors the historic bash logic)
# ---------------------------------------------------------------------------

_SUBVERSION_DIRS = (
    [f"v{i}" for i in range(10)]
    + [f"v{i}_{j}" for i in range(10) for j in range(10)]
    + [f"v{i}_ext" for i in range(10)]
    + [f"{i}x12" for i in (4, 5)]
    + ["byomcu", "rp2040zero", "xivik"]
)


def _has_build_json(p: Path) -> bool:
    return (p / "fp_build.json").is_file()


def discover_keyboards(root: Path = FP_KB_DIR) -> List[Path]:
    """Return all directories under `root` containing an `fp_build.json`.

    Mirrors the recursive walk in the original bash `get_valid_keyboards`,
    but generically: any directory that has its own fp_build.json is a
    valid build target, and we recurse into well-known controller-variant
    subdirectories (`byomcu`, `atmega`, `rp`, `stm`).
    """
    found: List[Path] = []

    def _walk(base: Path, recurse_variants: bool) -> None:
        if not base.is_dir():
            return
        for child in sorted(base.iterdir()):
            if not child.is_dir():
                continue
            if _has_build_json(child):
                found.append(child)
            for sub in _SUBVERSION_DIRS:
                if _has_build_json(child / sub):
                    found.append(child / sub)
            if recurse_variants:
                for variant in ("byomcu", "atmega", "rp", "stm"):
                    if (child / variant).is_dir():
                        _walk(child / variant, recurse_variants=False)

    _walk(root, recurse_variants=True)
    # de-dup while preserving order
    seen: set = set()
    uniq: List[Path] = []
    for p in found:
        if p not in seen:
            seen.add(p)
            uniq.append(p)
    return uniq


# ---------------------------------------------------------------------------
# Schema loading & validation
# ---------------------------------------------------------------------------

@dataclass
class Doc:
    path: Path
    presets: Dict[str, Dict[str, str]] = field(default_factory=dict)
    options: List[dict] = field(default_factory=list)


def _resolve_include(entry: dict, base_dir: Path, visiting: set) -> List[dict]:
    """Resolve an `$include` entry by loading the referenced fragment and
    returning its expanded `options` list.

    Fragment paths are resolved relative to `keyboards/fingerpunch/` so they
    are stable regardless of the depth of the including board's directory.
    Fragments themselves may contain further `$include` entries; cycles are
    detected and rejected.
    """
    rel = entry["$include"]
    if not isinstance(rel, str) or not rel:
        raise SystemExit(f"$include must be a non-empty string, got {entry!r}")
    frag_path = (FP_KB_DIR / rel).resolve()
    if frag_path in visiting:
        chain = " -> ".join(str(p.relative_to(REPO_ROOT)) for p in visiting) + f" -> {frag_path.relative_to(REPO_ROOT)}"
        raise SystemExit(f"$include cycle detected: {chain}")
    if not frag_path.is_file():
        raise SystemExit(f"$include target not found: {rel} (resolved to {frag_path})")
    raw = json.loads(frag_path.read_text())
    if not isinstance(raw, dict) or "options" not in raw:
        raise SystemExit(f"{frag_path}: fragment must be an object with `options`")
    return _expand_includes(raw["options"] or [], frag_path.parent, visiting | {frag_path})


def _expand_includes(options: List[dict], base_dir: Path, visiting: set) -> List[dict]:
    """Walk an options list, splicing any `$include` entries with the resolved
    fragment options. Recurses into `group.options` so includes work at any
    depth."""
    out: List[dict] = []
    for entry in options:
        if not isinstance(entry, dict):
            out.append(entry)
            continue
        if "$include" in entry:
            out.extend(_resolve_include(entry, base_dir, visiting))
            continue
        if entry.get("type") == "group" and isinstance(entry.get("options"), list):
            entry = dict(entry)
            entry["options"] = _expand_includes(entry["options"], base_dir, visiting)
        out.append(entry)
    return out


def load_doc(json_path: Path) -> Doc:
    raw = json.loads(json_path.read_text())
    if isinstance(raw, list):
        raise SystemExit(
            f"{json_path}: legacy top-level array is no longer supported. "
            "Wrap entries in an object: {{\"options\": [...]}}"
        )
    if not isinstance(raw, dict) or "options" not in raw:
        raise SystemExit(f"{json_path}: missing required `options` key")
    options = _expand_includes(raw["options"] or [], json_path.parent, {json_path.resolve()})
    return Doc(
        path=json_path,
        presets=raw.get("presets", {}) or {},
        options=options,
    )


def validate_all(root: Path = FP_KB_DIR) -> int:
    """Validate every fp_build.json under `root` against the schema.

    Uses jsonschema if available; falls back to a structural sanity check.
    Returns process exit code (0 on success).
    """
    files = sorted(root.rglob("fp_build.json"))
    if not files:
        print("no fp_build.json files found", file=sys.stderr)
        return 1

    schema = json.loads(SCHEMA_PATH.read_text())
    try:
        import jsonschema  # type: ignore

        validator = jsonschema.Draft7Validator(schema)
    except ImportError:
        validator = None
        print(
            "warning: python `jsonschema` package not installed; "
            "performing structural checks only.",
            file=sys.stderr,
        )

    errors: List[Tuple[Path, str]] = []
    for f in files:
        try:
            doc = load_doc(f)
        except SystemExit as e:
            errors.append((f, str(e)))
            continue
        if validator is not None:
            for err in validator.iter_errors({"options": doc.options, "presets": doc.presets}):
                loc = "/".join(str(p) for p in err.absolute_path) or "<root>"
                errors.append((f, f"{loc}: {err.message}"))
        # structural cross-checks beyond jsonschema reach
        errors.extend(_structural_checks(f, doc))

    if errors:
        for f, msg in errors:
            print(f"{f.relative_to(REPO_ROOT)}: {msg}", file=sys.stderr)
        print(f"\n{len(errors)} validation error(s) across {len(files)} file(s).", file=sys.stderr)
        return 1
    print(f"OK: {len(files)} fp_build.json file(s) validated.")
    return 0


def _structural_checks(path: Path, doc: Doc) -> List[Tuple[Path, str]]:
    errs: List[Tuple[Path, str]] = []

    def walk(opts: List[dict], where: str) -> None:
        seen_names: set = set()
        for i, entry in enumerate(opts):
            loc = f"{where}[{i}]"
            t = entry.get("type")
            if t == "single" or t == "value":
                name = entry.get("name", "")
                if name in seen_names:
                    errs.append((path, f"{loc}: duplicate name `{name}` at this level"))
                seen_names.add(name)
                if t == "value":
                    vals = entry.get("values")
                    default = entry.get("default")
                    if vals and default is not None and default not in vals:
                        errs.append((path, f"{loc}: default `{default}` not in values {vals}"))
            elif t == "one-of":
                names = entry.get("names", [])
                dupes = [n for n in names if names.count(n) > 1]
                if dupes:
                    errs.append((path, f"{loc}: duplicate entries in names: {sorted(set(dupes))}"))
                default = entry.get("default")
                if default is not None and default != "none" and default not in names:
                    errs.append((path, f"{loc}: default `{default}` not in names {names}"))
            elif t == "group":
                walk(entry.get("options", []), f"{loc}.options")
            else:
                errs.append((path, f"{loc}: unknown type `{t}`"))

    walk(doc.options, "options")
    return errs


# ---------------------------------------------------------------------------
# Walk: produces (build_args, filename_suffix) for each viable combination
# ---------------------------------------------------------------------------

@dataclass
class BuildPlan:
    env: List[Tuple[str, str]] = field(default_factory=list)  # [(K, V), ...]
    fname_tokens: List[str] = field(default_factory=list)     # ['cirque', 'i2c', ...]

    def with_env(self, k: str, v: str) -> "BuildPlan":
        return BuildPlan(env=self.env + [(k, v)], fname_tokens=list(self.fname_tokens))

    def with_token(self, t: Optional[str]) -> "BuildPlan":
        if not t:
            return self
        return BuildPlan(env=list(self.env), fname_tokens=self.fname_tokens + [t])

    def context(self) -> Dict[str, str]:
        return dict(self.env)


def _deps_satisfied(entry: dict, ctx: Dict[str, str]) -> bool:
    deps = entry.get("depends_on")
    if deps:
        # `depends_on` accepts two forms:
        #   - dict: AND-map. Every K=V pair must match the current context.
        #   - list of dicts: OR-of-ANDs. The entry is satisfied if any one of
        #     the dicts has all of its K=V pairs match the current context.
        if isinstance(deps, list):
            if not any(_and_map_matches(d, ctx) for d in deps):
                return False
        else:
            if not _and_map_matches(deps, ctx):
                return False
    conflicts = entry.get("conflicts_with") or []
    for k in conflicts:
        if ctx.get(k, "no") not in ("", "no"):
            return False
    return True


def _and_map_matches(deps: Dict[str, str], ctx: Dict[str, str]) -> bool:
    for k, v in deps.items():
        if ctx.get(k, "no") != v:
            return False
    return True


def _single_token(entry: dict) -> str:
    if "filename_token" in entry:
        return entry["filename_token"]
    name = entry["name"].lower()
    if name.endswith("_enable"):
        name = name[: -len("_enable")]
    return name


def _one_of_token(entry: dict, name: str) -> str:
    tokens = entry.get("filename_tokens") or {}
    if name in tokens:
        return tokens[name]
    n = name.lower()
    if n.endswith("_enable"):
        n = n[: -len("_enable")]
    return n


def _value_token(entry: dict, value: str) -> str:
    template = entry.get("filename_token", "{value}")
    return template.replace("{value}", value)


def _group_token(entry: dict) -> str:
    return entry.get("filename_token", entry["name"])


def _group_emit(entry: dict, plan: BuildPlan) -> BuildPlan:
    """Apply a group's enable-side effects (env + filename token + context flag)."""
    if "enable_flag" in entry:
        plan = plan.with_env(entry["enable_flag"], "yes")
    # group name is also exposed as a context flag for `depends_on`
    plan = plan.with_env(f"_GROUP_{entry['name'].upper()}", "yes")
    plan = plan.with_token(_group_token(entry))
    return plan


# Mode=interactive: prompt for each entry and return the single chosen plan.
# Mode=combinatorial: enumerate all viable plans and yield them.

def walk_interactive(
    options: List[dict],
    plan: BuildPlan,
    overrides: Dict[str, str],
    ask: Callable[[str, List[str]], str],
) -> BuildPlan:
    for entry in options:
        if not _deps_satisfied(entry, plan.context()):
            continue
        t = entry["type"]
        if t == "single":
            choice = _resolve_single(entry, overrides, ask)
            if choice == "yes":
                plan = plan.with_env(entry["name"], "yes").with_token(_single_token(entry))
        elif t == "one-of":
            choice = _resolve_one_of(entry, overrides, ask)
            if choice and choice != "none":
                plan = plan.with_env(choice, "yes").with_token(_one_of_token(entry, choice))
                subs = (entry.get("sub_options") or {}).get(choice)
                if subs:
                    plan = walk_interactive(subs, plan, overrides, ask)
        elif t == "value":
            choice = _resolve_value(entry, overrides, ask)
            plan = _emit_value(entry, choice, plan)
        elif t == "group":
            on = _resolve_group_enable(entry, overrides, ask)
            if on == "yes":
                plan = _group_emit(entry, plan)
                plan = walk_interactive(entry.get("options", []), plan, overrides, ask)
        else:
            raise SystemExit(f"unknown entry type: {t!r}")
    return plan


def walk_combinatorial(
    options: List[dict],
    plan: BuildPlan,
    overrides: Dict[str, str],
    exhaustive: bool,
) -> Iterable[BuildPlan]:
    if not options:
        yield plan
        return
    entry, rest = options[0], options[1:]
    if not _deps_satisfied(entry, plan.context()):
        yield from walk_combinatorial(rest, plan, overrides, exhaustive)
        return
    t = entry["type"]

    def _expand(child_plans: Iterable[BuildPlan]) -> Iterable[BuildPlan]:
        for cp in child_plans:
            yield from walk_combinatorial(rest, cp, overrides, exhaustive)

    name = entry.get("name") or entry.get("names", [""])[0]
    forced = overrides.get(name) if t in ("single", "value") else None
    if t == "single":
        choices: List[str]
        if forced is not None:
            choices = [forced]
        elif "default" in entry and not exhaustive:
            choices = [entry["default"]]
        else:
            choices = ["yes", "no"]
        for c in choices:
            cp = plan
            if c == "yes":
                cp = cp.with_env(entry["name"], "yes").with_token(_single_token(entry))
            yield from _expand([cp])

    elif t == "one-of":
        names = entry["names"]
        forced_choice = None
        for n in names:
            if overrides.get(n) == "yes":
                forced_choice = n
                break
        choices: List[str]
        if forced_choice is not None:
            choices = [forced_choice]
        elif "default" in entry and not exhaustive:
            choices = [entry["default"]]
        else:
            choices = ["none"] + list(names)
        sub_options_map = entry.get("sub_options") or {}
        for c in choices:
            cp = plan
            if c != "none":
                cp = cp.with_env(c, "yes").with_token(_one_of_token(entry, c))
                subs = sub_options_map.get(c)
                if subs:
                    # Expand the chosen name's sub-options before continuing with `rest`.
                    for sub_plan in walk_combinatorial(subs, cp, overrides, exhaustive):
                        yield from walk_combinatorial(rest, sub_plan, overrides, exhaustive)
                    continue
            yield from _expand([cp])

    elif t == "value":
        if forced is not None:
            values = [forced]
        elif "default" in entry and not exhaustive:
            values = [entry["default"]]
        else:
            values = entry.get("values") or [entry.get("default")]
            if values == [None]:
                raise SystemExit(
                    f"value entry `{entry.get('name')}` has no values and no default; "
                    "cannot enumerate combinatorially. Provide -s or a default."
                )
        for v in values:
            cp = _emit_value(entry, v, plan)
            yield from _expand([cp])

    elif t == "group":
        # The group's enable_flag (or _GROUP_<name>) participates in overrides too.
        forced_on = None
        if entry.get("enable_flag") and overrides.get(entry["enable_flag"]) is not None:
            forced_on = overrides[entry["enable_flag"]]
        states: List[str]
        if forced_on is not None:
            states = [forced_on]
        elif "default" in entry and not exhaustive:
            states = [entry["default"]]
        else:
            states = ["yes", "no"]
        for state in states:
            if state == "yes":
                cp = _group_emit(entry, plan)
                # enumerate sub-options, then continue with rest
                for sub_plan in walk_combinatorial(entry.get("options", []), cp, overrides, exhaustive):
                    yield from walk_combinatorial(rest, sub_plan, overrides, exhaustive)
            else:
                yield from walk_combinatorial(rest, plan, overrides, exhaustive)
    else:
        raise SystemExit(f"unknown entry type: {t!r}")


def _emit_value(entry: dict, value: str, plan: BuildPlan) -> BuildPlan:
    if value is None:
        return plan
    name = entry["name"]
    emit = entry.get("emit_when_default", True) or value != entry.get("default")
    new_plan = plan.with_env(name, value) if emit else plan
    # When the `-e NAME=value` flag is suppressed (emit_when_default=false and
    # the chosen value equals the default), suppress the filename token too —
    # the value is the implicit baseline, so it should not appear in the
    # rendered filename suffix either.
    if emit:
        new_plan = new_plan.with_token(_value_token(entry, value))
    return new_plan


# ---------------------------------------------------------------------------
# Pairwise (all-pairs) reduction
# ---------------------------------------------------------------------------

def _plan_signature(plan: BuildPlan, keys: List[str]) -> Tuple[str, ...]:
    """Project a plan onto its (sorted) value for each key, defaulting absent
    keys to the sentinel `"<unset>"`. Used as the input to pairwise covering."""
    ctx = plan.context()
    return tuple(ctx.get(k, "<unset>") for k in keys)


def pairwise_reduce(plans: List[BuildPlan]) -> List[BuildPlan]:
    """Greedily pick a subset of `plans` so that every (key_i=value, key_j=value)
    pair observed in the full set appears in at least one selected plan.

    This is the standard greedy set-cover approximation for all-pairs (a.k.a.
    pairwise / 2-way combinatorial coverage). For typical fingerpunch matrices
    (≤ 1000 plans, ≤ 20 keys) it's well under a second and produces a covering
    within a small constant factor of optimal.

    Internal `_GROUP_*` env keys are excluded from the projection so the group
    marker doesn't artificially partition the search space.
    """
    if len(plans) <= 1:
        return list(plans)

    # Union of every env key that ever appears, excluding internal markers.
    key_set: set = set()
    for p in plans:
        for k, _ in p.env:
            if not k.startswith("_GROUP_"):
                key_set.add(k)
    keys = sorted(key_set)
    if len(keys) < 2:
        # No pairs to cover; one plan is sufficient.
        return plans[:1]

    sigs: List[Tuple[str, ...]] = [_plan_signature(p, keys) for p in plans]

    # Build the universe of pairs that actually occur in the full plan set.
    # A pair is ((i, value_i), (j, value_j)) with i < j.
    all_pairs: set = set()
    for sig in sigs:
        for i in range(len(keys)):
            for j in range(i + 1, len(keys)):
                all_pairs.add(((i, sig[i]), (j, sig[j])))

    # Greedy: repeatedly pick the plan that covers the most uncovered pairs.
    selected: List[int] = []
    uncovered = set(all_pairs)
    plan_pairs: List[set] = []
    for sig in sigs:
        ps: set = set()
        for i in range(len(keys)):
            for j in range(i + 1, len(keys)):
                ps.add(((i, sig[i]), (j, sig[j])))
        plan_pairs.append(ps)

    while uncovered:
        best_idx = -1
        best_gain = -1
        for idx, ps in enumerate(plan_pairs):
            if idx in selected:
                continue
            gain = len(ps & uncovered)
            if gain > best_gain:
                best_gain = gain
                best_idx = idx
        if best_idx < 0 or best_gain <= 0:
            break  # nothing further reduces uncovered (shouldn't happen by construction)
        selected.append(best_idx)
        uncovered -= plan_pairs[best_idx]

    return [plans[i] for i in selected]


# ---------------------------------------------------------------------------
# Interactive prompt resolvers
# ---------------------------------------------------------------------------

def _resolve_single(entry: dict, overrides: Dict[str, str], ask) -> str:
    if entry["name"] in overrides:
        return overrides[entry["name"]]
    default = entry.get("default")
    suffix = f" [{default}]" if default else ""
    return ask(f"{entry['user_input']} (yes/no){suffix}: ", ["yes", "no"], default)


def _resolve_one_of(entry: dict, overrides: Dict[str, str], ask) -> str:
    names = entry["names"]
    for n in names:
        if overrides.get(n) == "yes":
            return n
    default = entry.get("default")
    default_idx: Optional[int] = None
    if default == "none":
        default_idx = 0
    elif default in names:
        default_idx = names.index(default) + 1
    menu = "\n".join(["  0) none"] + [f"  {i+1}) {n}" for i, n in enumerate(names)])
    suffix = f" [{default_idx}]" if default_idx is not None else ""
    raw = ask(
        f"{entry['user_input']}\n{menu}\nchoice{suffix}: ",
        [str(i) for i in range(len(names) + 1)],
        str(default_idx) if default_idx is not None else None,
    )
    idx = int(raw)
    return "none" if idx == 0 else names[idx - 1]


def _resolve_value(entry: dict, overrides: Dict[str, str], ask) -> str:
    if entry["name"] in overrides:
        return overrides[entry["name"]]
    default = entry.get("default")
    values = entry.get("values")
    suffix = f" [{default}]" if default else ""
    if values:
        return ask(f"{entry['user_input']} ({'/'.join(values)}){suffix}: ", values, default)
    return ask(f"{entry['user_input']}{suffix}: ", None, default)


def _resolve_group_enable(entry: dict, overrides: Dict[str, str], ask) -> str:
    if entry.get("enable_flag") and entry["enable_flag"] in overrides:
        return overrides[entry["enable_flag"]]
    default = entry.get("default")
    suffix = f" [{default}]" if default else ""
    return ask(f"{entry['user_input']} (yes/no){suffix}: ", ["yes", "no"], default)


def _ask(prompt: str, allowed: Optional[List[str]], default: Optional[str] = None) -> str:
    while True:
        ans = input(prompt).strip()
        if ans == "" and default is not None:
            return default
        if ans in ("y", "yes") and allowed and "yes" in allowed:
            return "yes"
        if ans in ("n", "no") and allowed and "no" in allowed:
            return "no"
        if allowed is None or ans in allowed:
            return ans
        print(f"  invalid choice: {ans!r}; expected one of: {', '.join(allowed)}")


# ---------------------------------------------------------------------------
# Build command + filename rendering
# ---------------------------------------------------------------------------

def render_command(kb: str, km: str, plan: BuildPlan) -> List[str]:
    cmd = ["qmk", "compile", "-kb", kb, "-km", km]
    for k, v in plan.env:
        if k.startswith("_GROUP_"):
            continue  # internal-only context flag
        cmd.extend(["-e", f"{k}={v}"])
    return cmd


def render_filename(kb: str, km: str, plan: BuildPlan) -> Tuple[str, str]:
    """Return (qmk_default_basename, target_basename) without extension."""
    qmk_base = f"{kb.replace('/', '_')}_{km}"
    target = qmk_base
    convert_to = next((v for k, v in plan.env if k == "CONVERT_TO"), None)
    if convert_to:
        qmk_base += f"_{convert_to}"
        target += f"_{convert_to}"
    for tok in plan.fname_tokens:
        if tok:
            target += f"_{tok.lower()}"
    return qmk_base, target


# ---------------------------------------------------------------------------
# Build runner
# ---------------------------------------------------------------------------

def run_build(cmd: List[str], cwd: Path) -> Tuple[int, str]:
    proc = subprocess.run(cmd, cwd=cwd, capture_output=True, text=True)
    return proc.returncode, proc.stdout + proc.stderr


def rename_artifacts(qmk_base: str, target_base: str, suffix: str = "") -> None:
    if suffix:
        target_base = f"{target_base}_{suffix}"
    for ext in ("hex", "uf2"):
        src = REPO_ROOT / f"{qmk_base}.{ext}"
        dst = REPO_ROOT / f"{target_base}.{ext}"
        if not src.exists():
            continue
        if src == dst:
            print(f"  skip rename ({ext}): already named {dst.name}")
            continue
        print(f"  rename {src.name} -> {dst.name}")
        src.rename(dst)


def execute(cmd: List[str], target_base: str, qmk_base: str) -> None:
    print("  $", " ".join(shlex.quote(a) for a in cmd))
    code, output = run_build(cmd, REPO_ROOT)
    print(output)
    suffix = ""
    if code != 0:
        if "The firmware is too large" in output or "will not fit in region" in output:
            suffix = "FIRMWARE_SIZE_CHECK_FAILED"
        else:
            print(f"build failed with exit status {code}", file=sys.stderr)
            sys.exit(code)
    rename_artifacts(qmk_base, target_base, suffix)


# ---------------------------------------------------------------------------
# Top-level orchestration
# ---------------------------------------------------------------------------

def parse_overrides(env_strings: List[str], set_pairs: List[str], convert_to: Optional[str]) -> Dict[str, str]:
    out: Dict[str, str] = {}
    for raw in env_strings:
        for tok in raw.split():
            if "=" not in tok:
                raise SystemExit(f"-e value `{tok}` is not K=V")
            k, v = tok.split("=", 1)
            out[k] = v
    for tok in set_pairs:
        if "=" not in tok:
            raise SystemExit(f"-s value `{tok}` is not K=V")
        k, v = tok.split("=", 1)
        out[k] = v
    if convert_to:
        out["CONVERT_TO"] = convert_to
    return out


def build_one(kb_path: Path, args, overrides: Dict[str, str]) -> None:
    doc = load_doc(kb_path / "fp_build.json")

    # Apply preset first; CLI overrides win.
    base: Dict[str, str] = {}
    if args.preset:
        if args.preset not in doc.presets:
            raise SystemExit(
                f"{kb_path}: preset `{args.preset}` not defined. "
                f"available: {list(doc.presets) or '<none>'}"
            )
        base.update(doc.presets[args.preset])
    base.update(overrides)

    kb_name = str(kb_path.relative_to(REPO_ROOT / "keyboards"))

    initial = BuildPlan()
    if args.interactive:
        plan = walk_interactive(doc.options, initial, base, _ask)
        plans = [plan]
    else:
        plans = list(walk_combinatorial(doc.options, initial, base, exhaustive=args.exhaustive))
        if args.pairwise:
            plans = pairwise_reduce(plans)

    for p in plans:
        cmd = render_command(kb_name, args.keymap, p)
        qmk_base, target_base = render_filename(kb_name, args.keymap, p)
        print(" ".join(shlex.quote(a) for a in cmd))
        if args.run:
            execute(cmd, target_base, qmk_base)


def main(argv: Optional[List[str]] = None) -> int:
    parser = argparse.ArgumentParser(
        prog="fp_build",
        description="Build fingerpunch keyboards from an fp_build.json matrix.",
    )
    parser.add_argument("-l", "--list", action="store_true", help="list valid keyboards and exit")
    parser.add_argument("-k", "--keyboard", help="keyboard subdirectory under keyboards/fingerpunch/")
    parser.add_argument("-m", "--keymap", default="default", help="keymap (default: default)")
    parser.add_argument("-c", "--convert-to", help="shorthand for -s CONVERT_TO=<value>")
    parser.add_argument("-i", "--interactive", action="store_true", help="prompt for each option")
    parser.add_argument("-r", "--run", action="store_true", help="actually run the qmk compile commands")
    parser.add_argument("-e", "--env", action="append", default=[],
                        help="space-separated K=V pairs (legacy compatibility)")
    parser.add_argument("-s", "--set", action="append", default=[],
                        help="K=V override (repeatable, pins an option non-interactively)")
    parser.add_argument("-p", "--preset", help="apply a named preset from the JSON before overrides")
    parser.add_argument("-x", "--exhaustive", action="store_true",
                        help="enumerate every option even when a default is provided")
    parser.add_argument("-w", "--pairwise", action="store_true",
                        help="reduce the exhaustive matrix to a pairwise (all-pairs) cover; "
                             "every (flag_a=value, flag_b=value) pair is built at least once. "
                             "Implies -x for enumeration scope.")
    parser.add_argument("-V", "--validate", action="store_true",
                        help="validate every fp_build.json under keyboards/fingerpunch/ and exit")
    args = parser.parse_args(argv)

    if args.pairwise:
        # Pairwise reduces the full exhaustive matrix, so force enumeration scope.
        args.exhaustive = True
    if args.pairwise and args.interactive:
        parser.error("-w/--pairwise cannot be combined with -i/--interactive")

    if args.validate:
        return validate_all()

    if args.list:
        for p in discover_keyboards():
            print(p.relative_to(REPO_ROOT))
        return 0

    overrides = parse_overrides(args.env, args.set, args.convert_to)

    if args.keyboard:
        kb_path = FP_KB_DIR / args.keyboard
        if not _has_build_json(kb_path):
            print(f"{kb_path} has no fp_build.json", file=sys.stderr)
            return 2
        targets = [kb_path]
    else:
        targets = discover_keyboards()

    for t in targets:
        print(f"# {t.relative_to(REPO_ROOT)}")
        build_one(t, args, overrides)
    return 0


if __name__ == "__main__":
    sys.exit(main())
