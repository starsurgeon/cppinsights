#!/usr/bin/env bash
set -euo pipefail
CLANGXX_BIN="${CLANGXX_BIN:-/home/amue/clang-p2996-bin/bin/clang++}"
exec "$CLANGXX_BIN" -fexpansion-statements -freflection-latest "$@"
