# Copilot working agreement for `qmk_firmware` (sadekbaroudi fork)

This is a **personal fork of QMK firmware** maintained for the
fingerpunch keyboard family. Treat it as a vendor fork: upstream QMK
files are read-only background, and almost all real work happens in a
small, well-defined slice of the tree.

## Hard rules

### Files you may modify

You may **only** create, edit, or delete files inside these paths:

| Path                                       | Why                                                                                              |
| ------------------------------------------ | ------------------------------------------------------------------------------------------------ |
| `keyboards/fingerpunch/`                   | All fingerpunch boards, the shared `src/` library, build matrix JSON, and helper scripts live here. |
| `users/sadekbaroudi/`                      | The owner's QMK userspace (custom keycodes, combos, tap dances, audio helpers, etc.).            |
| `bin/fp_build.sh` and `bin/fp_build.py`    | The build matrix tool. Both must stay in sync (the shell script is a thin wrapper).              |
| `bin/fp_build.md`                          | Documentation for the build tool.                                                                |
| `.github/workflows/firmware_build.yml`     | CI workflow that builds every fingerpunch board on every push.                                   |
| `.github/copilot-instructions.md`          | This file.                                                                                       |

### Files you must **not** touch unless explicitly asked

- Anything else under `keyboards/` — every other directory is an
  upstream QMK keyboard.
- Anything under `users/` other than `sadekbaroudi/`.
- Anything under `quantum/`, `tmk_core/`, `platforms/`, `drivers/`,
  `lib/`, `tests/`, `data/`, etc. These are upstream QMK code; modifying
  them creates merge pain.
- Build artifacts at the repo root (`*.uf2`, `*.hex`, `*.bin`).
- Any file produced by `make`, `qmk compile`, or QMK's submodules.

If a task seems to require touching upstream QMK files, **stop and ask
the user first**. Almost always, the right fix lives in
`keyboards/fingerpunch/src/` or `users/sadekbaroudi/` instead.

---

## The build tool: `bin/fp_build.py` (+ `fp_build.sh` wrapper)

`bin/fp_build.sh` is a one-line wrapper that `exec`s `bin/fp_build.py`.
**Always make functional changes in `fp_build.py`**; the shell script
exists only for legacy callers (CI, muscle memory). Same flag set on
both.

What it does:

1. Discovers fingerpunch keyboards (any directory under
   `keyboards/fingerpunch/` that contains an `fp_build.json`).
2. Walks each board's `fp_build.json` to enumerate or prompt for build
   options, applying `presets`, `-s K=V` overrides, and
   `depends_on` / `conflicts_with` predicates.
3. Renders one or more `qmk compile -kb <kb> -km <km> -e KEY=VALUE …`
   commands. With `-r`, runs them and renames the resulting
   `.uf2`/`.hex` files to encode the chosen options.

**Schema**: every `fp_build.json` is validated against
[`keyboards/fingerpunch/src/schemas/fp_build.jsonschema`](../keyboards/fingerpunch/src/schemas/fp_build.jsonschema).
The schema source-of-truth lives there; edit it whenever you add a new
entry type or field.

**Full user-facing docs**: [`bin/fp_build.md`](../bin/fp_build.md).
Read it before answering questions about flags, schema entries, or
preset mechanics.

**Validate after any JSON or schema change**:

```bash
python3 bin/fp_build.py -V
```

This must pass before committing.

**CI invariant**: `.github/workflows/firmware_build.yml` calls the tool
with `-x` (exhaustive) so every option × value combination is built on
every push. If you change CI invocation, preserve the exhaustive matrix
unless explicitly told otherwise.

---

## Repository layout (high level)

The only directories you should expect to modify or reason about deeply:

### `keyboards/fingerpunch/`

The fingerpunch keyboard family. Top-level structure:

| Subpath                                  | Purpose                                                                                                                                |
| ---------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------- |
| `<board>/` (e.g. `ffkb/`, `rockon/`, `pinkiesout/`) | One folder per board. Most boards have version subdirectories (`v1/`, `v2/`, `v3_1/`, etc.) and/or controller variants (`atmega/`, `byomcu/`, `rp/`, `stm/`). The leaf directory contains `keyboard.json`, `config.h`, `rules.mk`, `fp_build.json`, and a `keymaps/` directory. |
| `personal/`                              | Sadek's personal / WIP boards (`baboon38`, `ximi`, `testamatta`, etc.). Same structure as top-level boards. **Excluded from `bin/fp_build.sh -l` discovery** to keep CI scope sane; still buildable via `-k personal/<name>`. |
| `src/`                                   | Shared library code included by every fingerpunch board's `rules.mk`. `fp.c`/`fp.h`, `fp_audio.*`, `fp_haptic.*`, `fp_pointing.*`, `fp_rgb_*.{c,h}`, `fp_encoder.*`, `display/`, `vik/` (the VIK connector module — driver selection for cirque/azoteq/displays/etc.), `rgb_matrix_effects/`. |
| `src/schemas/`                           | JSON Schema definitions, currently `fp_build.jsonschema`.                                                                              |
| `src/scripts/`                           | One-off maintenance scripts. `migrate_fp_build.py` handles the legacy → new schema migration and is idempotent.                        |
| `src/vik/`                               | Implementation of the [VIK connector spec](https://github.com/sadekbaroudi/vik). Boards opt in with `VIK_ENABLE = yes`. Driver selection for cirque (SPI vs I2C), azoteq, ILI9341, etc., flows through `rules.vik.{pre,main,right,post}.mk` and `config.vik.{pre,post}.h`. |
| `images/`                                | Marketing / documentation images for the boards.                                                                                       |
| `README.md`, `FIRMWARE.md`, `FP_LIBRARY_SUPPORT.md` | User-facing documentation. Update when adding/removing user-visible behavior in `src/`.                                       |

**Per-board files of interest**:

- `keyboard.json` — QMK board manifest (matrix, pins, features).
- `config.h` — preprocessor defines for the build.
- `rules.mk` — Make-time feature toggles. Often includes
  `keyboards/fingerpunch/src/rules.mk` to pull in the shared library.
- `fp_build.json` — build matrix definition consumed by `fp_build.py`.
  Schema-validated.
- `keymaps/<name>/` — keymap implementations (e.g. `default/`,
  `sadekbaroudi/`).

### `users/sadekbaroudi/`

The owner's QMK userspace, included by any keymap that sets
`USER_NAME = sadekbaroudi` (or by default in this fork). Contains:

| File                            | Purpose                                                                                          |
| ------------------------------- | ------------------------------------------------------------------------------------------------ |
| `sadekbaroudi.{c,h}`            | Userspace entrypoint. Common keymap helpers, layer state, OS handling.                           |
| `process_records.{c,h}`         | Custom keycode handling for the `process_record_user` hook.                                      |
| `combos.{c,h}`                  | Combo definitions.                                                                               |
| `tapdances.{c,h}`               | Tap dance definitions.                                                                           |
| `casemodes.{c,h}`               | Snake_case / camelCase / etc. helpers.                                                           |
| `audio_userspace.{c,h}`         | Audio sequences (alerts, mode changes).                                                          |
| `wrappers.h`                    | Layout wrapper macros used across keymaps.                                                       |
| `config.h`, `rules.mk`          | Userspace-wide configuration and Make rules.                                                     |

When adding userspace behavior, prefer extending these files over
adding new ones.

### `bin/`

| File              | Purpose                                                                                          |
| ----------------- | ------------------------------------------------------------------------------------------------ |
| `fp_build.py`     | The build matrix engine. Edit here for any behavioral change.                                    |
| `fp_build.sh`     | Thin shell wrapper. **Do not duplicate logic here.**                                             |
| `fp_build.md`     | User-facing documentation. Keep in sync with the schema and CLI surface.                         |
| Other files       | Upstream QMK helpers — do not modify.                                                            |

### `.github/`

| File                                    | Purpose                                                                                          |
| --------------------------------------- | ------------------------------------------------------------------------------------------------ |
| `workflows/firmware_build.yml`          | The CI matrix. One job per discovered keyboard, each invoked with `-x` for exhaustive coverage. |
| `copilot-instructions.md`               | This file.                                                                                       |
| Anything else                           | Treat as upstream — leave alone.                                                                 |

---

## Working conventions

### Editing `fp_build.json` files

- Use the schema features: `default`, `depends_on`, `conflicts_with`,
  `presets`, and `group` for cohesive features. Avoid inventing parallel
  boolean flags (e.g. `FP_TRACKBALL_BOTH`, `FP_CIRQUE_LEFT_ONLY`) when a
  `group` + `value` would express the same intent more naturally.
- `ffkb/rp/v1/fp_build.json` is the **canonical example** of the new
  schema. Mirror its style when migrating other boards.
- After every edit: `python3 bin/fp_build.py -V` must pass.
- Smoke-test interactively at least once: `bin/fp_build.sh -k <kb> -i`.

### Editing `keyboards/fingerpunch/src/`

- Changes here affect **every fingerpunch board**. Be conservative.
- VIK changes (`src/vik/`) affect every board with `VIK_ENABLE = yes` —
  add new behavior behind opt-in flags or feature defines so existing
  boards keep their current behavior unless explicitly upgraded.
- Document new build options in
  [`keyboards/fingerpunch/README.md`](../keyboards/fingerpunch/README.md)
  (the table near the top lists every supported build flag).

### Editing `users/sadekbaroudi/`

- These changes only affect Sadek's keymaps. Lower blast radius than
  `src/` changes, but still keep the surface area small and avoid
  introducing dependencies that only one board needs.

### Editing CI

- Preserve `-x` on the build invocation.
- Preserve the `-l` listing path; the matrix construction depends on it.
- Bump the QMK CLI container hash deliberately, never as a side effect.

### Things you generally **shouldn't** do

- Add new top-level Markdown files documenting a change (the user will
  ask if they want one).
- Bump submodule revisions (`lib/chibios`, `lib/lufa`, etc.) without
  being asked.
- Run `qmk compile` directly in chat — the user will trigger builds.
  Use `bin/fp_build.sh -k <kb>` (without `-r`) to *show* what would be
  built.
- Touch `Doxyfile`, `doxygen-todo`, `.clang-format`, `.editorconfig`,
  etc. unless the user is explicitly working on tooling.

---

## Useful commands

```bash
# List discoverable boards.
bin/fp_build.sh -l

# Validate every fp_build.json.
python3 bin/fp_build.py -V

# Show the build matrix for one board (no compile).
bin/fp_build.sh -k ffkb/rp/v1
bin/fp_build.sh -k ffkb/rp/v1 -x          # full matrix

# Interactive walkthrough.
bin/fp_build.sh -k ffkb/rp/v1 -i

# Apply a preset and pin one override.
bin/fp_build.sh -k ffkb/rp/v1 -p fully-loaded -s CIRQUE_DRIVER=i2c

# Migrate any legacy fp_build.json files (idempotent).
python3 keyboards/fingerpunch/src/scripts/migrate_fp_build.py
```

For deeper details on any of the above, read
[`bin/fp_build.md`](../bin/fp_build.md) first.
