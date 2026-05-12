#!/usr/bin/env bash
# bin/firmware_build_ci.sh — simulate the GitHub Actions firmware build locally.
#
# Mirrors the per-job behavior of .github/workflows/firmware_build.yml:
#
#   - Discovers boards via `bin/fp_build.sh -l`
#   - For each selected board, runs `bin/fp_build.sh -k <kb> -r -w`
#     (pairwise / all-pairs coverage; same flag CI uses)
#   - Reports per-board PASS/FAIL with a summary at the end
#   - Exits non-zero if any board failed
#
# Usage:
#   bin/firmware_build_ci.sh                # build every discoverable board
#   bin/firmware_build_ci.sh ffkb/rp/v1     # build a single board (CI matrix entry)
#   bin/firmware_build_ci.sh -n             # dry-run: show the qmk compile commands without running
#   LOG_DIR=/tmp/fp_ci bin/firmware_build_ci.sh   # override log directory (default: ${TMPDIR:-/tmp}/fp_ci_logs)
#
# The single-board form takes the same path you'd see from
# `bin/fp_build.sh -l | sed s~keyboards/fingerpunch/~~` (e.g. `pinkiesout/v3`,
# `ffkb/byomcu/v1`). Matching is exact, not substring.

set -u

DRY_RUN=0
while getopts ":n" opt; do
    case "$opt" in
        n) DRY_RUN=1 ;;
        *)
            echo "usage: $0 [-n] [<keyboard>]" >&2
            exit 2
            ;;
    esac
done
shift $((OPTIND - 1))

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
cd "$REPO_ROOT"

TARGET="${1:-}"
LOG_DIR="${LOG_DIR:-${TMPDIR:-/tmp}/fp_ci_logs}"
mkdir -p "$LOG_DIR"
SUMMARY="$LOG_DIR/SUMMARY.txt"
: > "$SUMMARY"

# Discover boards exactly the way CI does.
mapfile -t ALL_KBS < <(bin/fp_build.sh -l | sed 's|keyboards/fingerpunch/||')

# Filter to the requested board, if any. Match is exact (CI used to glob
# `*${{ matrix.keyboard }}*` which over-matched siblings like v3 / v3_1;
# we mirror the fixed-up exact behavior here).
BOARDS=()
if [[ -n "$TARGET" ]]; then
    for kb in "${ALL_KBS[@]}"; do
        if [[ "$kb" == "$TARGET" ]]; then
            BOARDS+=("$kb")
        fi
    done
    if [[ ${#BOARDS[@]} -eq 0 ]]; then
        echo "error: no discoverable board matches '$TARGET'" >&2
        echo "       run \`bin/fp_build.sh -l\` to see the full list" >&2
        exit 2
    fi
else
    BOARDS=("${ALL_KBS[@]}")
fi

if [[ $DRY_RUN -eq 1 ]]; then
    echo "DRY RUN: ${#BOARDS[@]} board(s) would be built with \`bin/fp_build.sh -k <kb> -r -w\`"
    for kb in "${BOARDS[@]}"; do
        n=$(bin/fp_build.sh -k "$kb" -w 2>/dev/null | grep -c '^qmk compile')
        printf "  %-40s pairwise=%3d\n" "$kb" "$n"
    done
    exit 0
fi

echo "Building ${#BOARDS[@]} board(s); logs in $LOG_DIR" | tee -a "$SUMMARY"
START=$(date +%s)
FAIL_COUNT=0
PASS_COUNT=0
for kb in "${BOARDS[@]}"; do
    slug="${kb//\//_}"
    log="$LOG_DIR/${slug}.log"
    n=$(bin/fp_build.sh -k "$kb" -w 2>/dev/null | grep -c '^qmk compile')
    t0=$(date +%s)
    echo "=== START $(date '+%H:%M:%S') $kb ($n builds) ===" | tee -a "$SUMMARY"
    bin/fp_build.sh -k "$kb" -r -w > "$log" 2>&1
    rc=$?
    t1=$(date +%s)
    dur=$((t1 - t0))
    if [[ $rc -eq 0 ]]; then
        echo "PASS  ${kb}  ${n} builds  ${dur}s" | tee -a "$SUMMARY"
        PASS_COUNT=$((PASS_COUNT + 1))
    else
        echo "FAIL  ${kb}  rc=${rc}  ${dur}s  see $log" | tee -a "$SUMMARY"
        FAIL_COUNT=$((FAIL_COUNT + 1))
    fi
done
TOTAL=$(($(date +%s) - START))
{
    echo ""
    echo "Total wall time: ${TOTAL}s"
    echo "PASS=$PASS_COUNT  FAIL=$FAIL_COUNT"
} | tee -a "$SUMMARY"

if [[ $FAIL_COUNT -gt 0 ]]; then
    exit 1
fi
exit 0
