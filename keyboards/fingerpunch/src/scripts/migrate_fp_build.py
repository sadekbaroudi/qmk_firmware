#!/usr/bin/env python3
"""Bulk-migrate keyboards/fingerpunch/**/fp_build.json from the legacy
top-level-array form to the new object form.

Transformations:
- Wrap [...] in {"options": [...]}.
- Replace {"type": "convert-to", "name": X} with a value entry for CONVERT_TO.
- De-duplicate `names` arrays in `one-of` entries.
- Drop stray `name` keys on `one-of` entries (they were ignored by the old
  script and rejected by the new schema).

This script is idempotent. Run from the repo root:
    python3 keyboards/fingerpunch/src/scripts/migrate_fp_build.py
"""
from __future__ import annotations

import json
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[4]  # repo root
FP = ROOT / "keyboards" / "fingerpunch"


def _migrate_entry(entry: dict) -> dict:
    t = entry.get("type")
    if t == "convert-to":
        return {
            "type": "value",
            "name": "CONVERT_TO",
            "user_input": f"Build with CONVERT_TO={entry['name']}?",
            "values": [entry["name"]],
            "default": entry["name"],
        }
    if t == "one-of":
        # de-duplicate names while preserving order
        names = entry.get("names", [])
        seen, deduped = set(), []
        for n in names:
            if n not in seen:
                seen.add(n)
                deduped.append(n)
        new = dict(entry)
        new["names"] = deduped
        # drop stray `name` (vulpes_majora bug)
        new.pop("name", None)
        return new
    return entry


def migrate_file(path: Path) -> bool:
    raw = json.loads(path.read_text())
    if isinstance(raw, dict) and "options" in raw:
        return False  # already migrated
    if not isinstance(raw, list):
        print(f"  ! {path}: unexpected top-level type {type(raw).__name__}", file=sys.stderr)
        return False
    new_doc = {"options": [_migrate_entry(e) for e in raw]}
    path.write_text(json.dumps(new_doc, indent=4) + "\n")
    return True


def main() -> int:
    files = sorted(FP.rglob("fp_build.json"))
    changed = 0
    for f in files:
        if migrate_file(f):
            print(f"  migrated: {f.relative_to(ROOT)}")
            changed += 1
    print(f"\n{changed}/{len(files)} files migrated.")
    return 0


if __name__ == "__main__":
    sys.exit(main())
