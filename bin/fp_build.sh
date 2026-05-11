#!/bin/bash
# Thin wrapper around bin/fp_build.py for backward compatibility.
#
# The fingerpunch build matrix logic now lives in bin/fp_build.py. This script
# simply forwards every argument to the Python entrypoint so the historical
# `bin/fp_build.sh -k ... -m ... -i -r` invocations keep working.
#
# Run `bin/fp_build.py -h` for the full set of options, including the new
# -s K=V (override), -p <preset>, -x (exhaustive) and -V (validate) flags.

set -e

SCRIPT_DIR="$( cd -- "$(dirname -- "${BASH_SOURCE[0]}")" >/dev/null 2>&1 ; pwd -P )"
exec python3 "${SCRIPT_DIR}/fp_build.py" "$@"
