#!/usr/bin/env bash
set -euo pipefail
INSIGHTS_BIN="/opt/cppinsights/build/bin/insights"
extra=("--extra-arg=-fexpansion-statements")
args=()
inserted=false
for arg in "$@"; do
  if [[ "$arg" == "--" && "$inserted" == "false" ]]; then
    args+=("${extra[@]}")
    inserted=true
  fi
  args+=("$arg")
done
if [[ "$inserted" == "false" ]]; then
  args+=("${extra[@]}")
fi
exec "$INSIGHTS_BIN" "${args[@]}"
