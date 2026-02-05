#!/usr/bin/env bash
set -euo pipefail
exec /opt/p2996/bin/clang++ -fexpansion-statements -freflection-latest "$@"
