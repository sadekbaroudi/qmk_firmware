# `fp_build` — fingerpunch build matrix tool

`bin/fp_build.py` (with `bin/fp_build.sh` as a thin wrapper) drives builds
for every keyboard under `keyboards/fingerpunch/`. Each board has an
`fp_build.json` describing its configurable options. The tool reads that
file and produces one or many `qmk compile` invocations, optionally
running them and renaming the resulting `.uf2` / `.hex` artifacts to
encode the chosen options.

> The shell script and the Python script accept identical arguments.
> The examples below use `bin/fp_build.sh` for parity with CI/historical
> usage, but `python3 bin/fp_build.py …` works the same.

---

## Quick start

```bash
# Print the build command(s) for one keyboard with default options.
bin/fp_build.sh -k ffkb/rp/v1

# Walk through every option interactively (defaults shown in [brackets]).
bin/fp_build.sh -k ffkb/rp/v1 -i

# Build a known-good preset and run it.
bin/fp_build.sh -k ffkb/rp/v1 -p fully-loaded -r

# Override specific options non-interactively.
bin/fp_build.sh -k ffkb/rp/v1 -s CIRQUE_ENABLE=yes -s CIRQUE_DRIVER=i2c -r

# Build every viable combination.
bin/fp_build.sh -k ffkb/rp/v1 -x -r

# Pairwise (all-pairs) cover — every two-flag interaction built at least
# once, but with the matrix size collapsed (often 10-50x smaller).
# **CI uses this**, so every supported flag pair is exercised on every push.
bin/fp_build.sh -k ffkb/rp/v1 -w -r

# Validate every fp_build.json in the repo against the schema.
bin/fp_build.sh -V

# List all discoverable keyboards.
bin/fp_build.sh -l
```

---

## CLI reference

| Flag                | Description                                                                                                    |
| ------------------- | -------------------------------------------------------------------------------------------------------------- |
| `-l`, `--list`      | Print every discoverable keyboard path, one per line, then exit.                                               |
| `-k <kb>`           | Keyboard subdirectory under `keyboards/fingerpunch/` (e.g. `ffkb/rp/v1`). If omitted, every keyboard is built. |
| `-m <km>`           | Keymap. Defaults to `default`.                                                                                 |
| `-c <ctrl>`         | Shorthand for `-s CONVERT_TO=<ctrl>` (e.g. `-c stemcell`).                                                     |
| `-i`, `--interactive` | Prompt for every option. Defaults are surfaced inline; press Enter to accept.                                |
| `-r`, `--run`       | Actually run the `qmk compile` command(s). Without `-r`, the tool only prints them.                           |
| `-s K=V`            | Pin option `K` to value `V` non-interactively. Repeatable.                                                     |
| `-p <preset>`       | Apply a named preset (defined in the board's `fp_build.json`) before any `-s` overrides.                       |
| `-e "K=V K2=V2"`    | Legacy compatibility for the original shell script. Equivalent to one or more `-s K=V` flags.                  |
| `-x`, `--exhaustive`| Enumerate **every** option × value combination, even when an option declares a `default`.                      |
| `-w`, `--pairwise`  | Reduce the exhaustive matrix to a pairwise (all-pairs) cover: every `(flag_a=value, flag_b=value)` interaction is built at least once. Implies `-x` for enumeration scope. **Used by CI.**     |
| `-V`, `--validate`  | Validate every `fp_build.json` under `keyboards/fingerpunch/` against the schema and exit.                     |
| `-h`, `--help`      | Show usage.                                                                                                    |

### Override precedence

Lowest → highest:

1. `default` declared on each option in `fp_build.json`.
2. Values from a preset selected with `-p`.
3. `-s K=V` overrides on the command line.
4. Interactive prompts (`-i`).

In `-i` mode every option is still prompted, but values pinned by 1–3
appear as the suggested default. Empty input accepts whatever the
default would be.

---

## Build modes

The tool has two operating modes selected automatically by the flags:

### Combinatorial (default)

Walks the option tree and enumerates valid combinations. Each
combination becomes one `qmk compile` invocation.

- Without `-x`, options that declare a `default` contribute only that
  one value to the matrix. This keeps the casual `bin/fp_build.sh -k <kb>`
  invocation small and predictable.
- With `-x`, every option is fully enumerated.
- With `-w`, the tool starts from the exhaustive set, then greedily
  selects the smallest subset of builds that still contains every
  observed `(flag_a=value, flag_b=value)` pair (the standard "all-pairs"
  / pairwise testing technique). Three-way and higher interactions are
  not guaranteed; pin those via `presets` if you care about them.
  **CI uses `-w`** so every two-flag interaction is exercised without
  the O(N!) blow-up of a full cartesian product.
- `depends_on` and `conflicts_with` predicates prune the matrix in all
  modes.

### Interactive (`-i`)

Walks the option tree and prompts the user once per applicable option.

- The default value (or whichever value `-p` / `-s` pinned) appears in
  square brackets in the prompt: `Do you have a cirque? (yes/no) [no]:`.
- Empty input accepts the bracketed value.
- Sub-options inside a `group` are skipped automatically when the parent
  group is `no`.
- Options whose `depends_on` is not satisfied by the current context are
  skipped without a prompt.

### Filename suffix

Successful builds rename the QMK output files to encode the chosen
options. For example, the `fully-loaded` preset on `ffkb/rp/v1` produces:

```
fingerpunch_ffkb_rp_v1_default_cirque_spi_rgb_matrix_fp_ec11_audio_haptic.uf2
```

If a build fails because the firmware would be too large for the MCU
flash, the suffix `_FIRMWARE_SIZE_CHECK_FAILED` is appended so the
oversized binary is preserved for debugging without aborting the matrix.

---

## `fp_build.json` schema

Schema definition: [`keyboards/fingerpunch/src/schemas/fp_build.jsonschema`](../keyboards/fingerpunch/src/schemas/fp_build.jsonschema).

Every `fp_build.json` is an object with two top-level keys:

```jsonc
{
    "$schema": "../../../src/schemas/fp_build.jsonschema",
    "presets": { /* optional named bundles */ },
    "options": [ /* required: ordered list of option entries */ ]
}
```

### Common fields

Every entry below supports these optional fields:

- **`depends_on`** — Predicate that must be satisfied for the entry to
  apply. Accepts either form:
  - **`{ "FLAG": "value", ... }`** — single AND-map. The entry is only
    considered when every named flag in the current build context
    resolves to its required value. Use `"yes"` / `"no"` for boolean
    flags.
  - **`[ { ... }, { ... } ]`** — list of AND-maps (OR-of-ANDs). The
    entry is considered when **any one** of the maps fully matches.
    Useful for "either of these combinations" predicates without
    enumerating every cross-product. Example: only ask
    `FP_SPLIT_BUILD` when the user picked different pointing devices
    on each half:
    ```jsonc
    "depends_on": [
        { "FP_POINTING_LEFT": "trackball", "FP_POINTING_RIGHT": "cirque" },
        { "FP_POINTING_LEFT": "cirque",    "FP_POINTING_RIGHT": "trackball" }
    ]
    ```
- **`conflicts_with`** — `["FLAG", ...]`. The entry is skipped if any
  listed flag is currently set to a non-`no` value.
- **`filename_token`** — Override the suffix appended to the output
  filename when this entry is enabled. For `value` entries, `{value}` in
  the template expands to the chosen value.

### Entry types

#### `single` — boolean yes/no

```jsonc
{
    "type": "single",
    "name": "AUDIO_ENABLE",
    "user_input": "Do you have an audio buzzer?",
    "default": "no"
}
```

Emits `-e AUDIO_ENABLE=yes` (or `=no`) on the `qmk compile` line.
Filename token defaults to lowercase `name` with `_enable` stripped
(here: `audio`).

#### `one-of` — pick zero or one

```jsonc
{
    "type": "one-of",
    "names": ["RGBLIGHT_ENABLE", "RGB_MATRIX_ENABLE"],
    "user_input": "No RGB, RGB light, RGB matrix?",
    "default": "none"
}
```

Mutually exclusive selection. The user picks `none` (no flag emitted) or
exactly one of `names`. `default` may be `"none"` or any value from
`names`. The interactive prompt presents a numbered menu starting at `0`
for `none`.

**Per-name sub-options** (optional): each name may declare its own
sub-option list via `sub_options`. The sub-options are walked only when
that specific name is chosen, and the chosen name is set in the build
context so sub-options can reference it in `depends_on`. This lets you
model "pick A or B, but if you pick A also tell me the A-specific
config" without a parallel `group` + `conflicts_with` triple.

```jsonc
{
    "type": "one-of",
    "names": ["CIRQUE_ENABLE", "FP_TRACKBALL_ENABLE"],
    "user_input": "Pointing device?",
    "default": "none",
    "sub_options": {
        "CIRQUE_ENABLE": [
            {
                "type": "value",
                "name": "CIRQUE_DRIVER",
                "values": ["spi", "i2c"],
                "default": "spi",
                "user_input": "Which cirque bus?"
            }
        ]
    }
}
```

In exhaustive mode, sub-options multiply only into the branch that
selects them, so the trackball branch above contributes 1 plan while
the cirque branch contributes `|CIRQUE_DRIVER values|` plans.

#### `value` — free-form or enumerated value

```jsonc
{
    "type": "value",
    "name": "CIRQUE_DRIVER",
    "values": ["spi", "i2c"],
    "default": "spi",
    "user_input": "Which cirque bus?"
}
```

Emits `-e CIRQUE_DRIVER=<value>`.

- `values` (optional) restricts allowed values. **Combinatorial mode
  requires this list** so the matrix can be enumerated; without it,
  only `-i` and `-s` modes work for this entry.
- `emit_when_default` (optional, default `true`): when `false`, the
  `-e NAME=value` is omitted from the build command if the chosen value
  equals `default` (useful when the value is implicit in the keyboard's
  own `rules.mk`).

#### `group` — gated set of sub-questions

```jsonc
{
    "type": "group",
    "name": "cirque",
    "enable_flag": "CIRQUE_ENABLE",
    "user_input": "Do you have a cirque?",
    "default": "no",
    "conflicts_with": ["FP_TRACKBALL_ENABLE"],
    "options": [
        {
            "type": "value",
            "name": "CIRQUE_DRIVER",
            "values": ["spi", "i2c"],
            "default": "spi",
            "user_input": "Which cirque bus?"
        }
    ]
}
```

A group asks one yes/no question first, and only descends into its
`options` when enabled. When enabled it emits `-e <enable_flag>=yes`
(if `enable_flag` is set) plus everything its children produce.

`group.name` (lowercase) doubles as a context flag: `_GROUP_<NAME>=yes`
is set internally so other entries can refer to it via `depends_on`.

#### `$include` — splice in a shared fragment

```jsonc
{ "$include": "src/fp_build_fragments/vik.json" }
```

Replaces itself at load time with the `options` list from the referenced
fragment file. The path is resolved relative to
`keyboards/fingerpunch/`. Fragment files themselves must be valid
`fp_build.json`-shaped objects (`{ "options": [...] }`); their
`presets` (if any) are ignored.

Fragments may include other fragments. Cycles are detected and
rejected at load time.

This exists so canonical option groups can live in one place. The
`src/fp_build_fragments/vik.json` fragment, for example, defines the
canonical VIK module `one-of` (with `VIK_CIRQUE` carrying a
SPI/I2C sub-option) and is included from every VIK-enabled board's
`fp_build.json`. Adding a new VIK module is a one-line edit in the
fragment instead of touching every consuming board.

### Presets

```jsonc
"presets": {
    "default":        { "RGB_MATRIX_ENABLE": "yes" },
    "fully-loaded":   {
        "CIRQUE_ENABLE":     "yes",
        "CIRQUE_DRIVER":     "spi",
        "RGB_MATRIX_ENABLE": "yes",
        "FP_EC11":           "yes",
        "AUDIO_ENABLE":      "yes",
        "HAPTIC_ENABLE":     "yes"
    }
}
```

Selected via `-p <name>`. A preset is just a flat map from option name to
value. For `single` and `group` use `"yes"`/`"no"`; for `one-of` use the
chosen flag name (one of `names`); for `value` use the value string.

`-s K=V` overrides on the command line take precedence over preset
values.

---

## Working example: `ffkb/rp/v1`

```bash
$ cat keyboards/fingerpunch/ffkb/rp/v1/fp_build.json
```

Try the following invocations against it to see the schema in action:

```bash
# 1. Bare minimum (no options set).
bin/fp_build.sh -k ffkb/rp/v1
#   qmk compile -kb fingerpunch/ffkb/rp/v1 -km default

# 2. Apply the "default" preset.
bin/fp_build.sh -k ffkb/rp/v1 -p default
#   qmk compile -kb ... -e RGB_MATRIX_ENABLE=yes

# 3. Apply the "fully-loaded" preset.
bin/fp_build.sh -k ffkb/rp/v1 -p fully-loaded
#   qmk compile -kb ... -e CIRQUE_ENABLE=yes -e CIRQUE_DRIVER=spi
#                       -e RGB_MATRIX_ENABLE=yes -e FP_EC11=yes
#                       -e AUDIO_ENABLE=yes -e HAPTIC_ENABLE=yes

# 4. Pin individual options. Override wins over the preset.
bin/fp_build.sh -k ffkb/rp/v1 -p fully-loaded -s CIRQUE_DRIVER=i2c

# 5. Walk every option interactively. Press Enter at each prompt to
#    accept the value shown in [brackets].
bin/fp_build.sh -k ffkb/rp/v1 -i

# 6. Build the full matrix (everything CI builds for this board).
bin/fp_build.sh -k ffkb/rp/v1 -x | grep -c '^qmk compile'
# 144
```

---

## Adding a new option to a board

1. Edit the board's `fp_build.json`.
2. Append a new entry of the appropriate type, with a `user_input`
   description and a `default` value if there is a sensible one.
3. If the new option is mutually exclusive with another option, set
   `conflicts_with` on both entries.
4. If it only makes sense when another flag is enabled, set
   `depends_on`.
5. Validate: `bin/fp_build.sh -V`
6. Smoke test: `bin/fp_build.sh -k <kb> -i` and walk through the prompt.

---

## Migrating a legacy `fp_build.json`

Existing files in legacy form (top-level array) can be migrated in bulk:

```bash
python3 keyboards/fingerpunch/src/scripts/migrate_fp_build.py
```

This script:

- Wraps the legacy `[ ... ]` in `{ "options": [ ... ] }`.
- Converts old `convert-to` entries into `value` entries on `CONVERT_TO`.
- De-duplicates entries inside `one-of.names`.
- Drops a stray `name` key on `one-of` entries (was ignored by the old
  bash script and is rejected by the new schema).

It is idempotent — running it twice is a no-op on already-migrated files.

---

## CI integration

`.github/workflows/firmware_build.yml` builds every keyboard with `-w`
(pairwise / all-pairs coverage) so every two-flag interaction is
exercised on every push without blowing up to the full cartesian
product. The workflow delegates per-board work to
[`bin/firmware_build_ci.sh`](firmware_build_ci.sh), which is the single
source of truth for the build invocation:

```bash
# Reproduce CI locally, one board at a time:
bin/firmware_build_ci.sh ffkb/rp/v1

# Or the whole matrix in series (takes a while):
bin/firmware_build_ci.sh

# Dry-run: list which boards would build, and how many pairwise commands each:
bin/firmware_build_ci.sh -n
```

`-w` reduces the build count by 5-25x on typical fingerpunch boards.
Three-way interactions worth pinning can be added to a board's
`presets` block — presets always build.
