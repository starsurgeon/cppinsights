#!/usr/bin/env bash
set -euo pipefail

INSIGHTS_BIN="${INSIGHTS_BIN:-/opt/cppinsights/build/bin/insights}"
LIBCXX_HEADERS="${LIBCXX_HEADERS:-/usr/include/c++/v1}"
C_HEADERS="${C_HEADERS:-/usr/include}"
C_HEADERS_ARCH="${C_HEADERS_ARCH:-/usr/include/x86_64-linux-gnu}"
GCC_HEADERS="${GCC_HEADERS:-/usr/lib/gcc/x86_64-linux-gnu/13/include}"

extra=(
  -nostdinc++
  -isystem "$LIBCXX_HEADERS"
  -isystem "$C_HEADERS"
  -isystem "$C_HEADERS_ARCH"
  -isystem "$GCC_HEADERS"
)

args=()
inserted=0
for arg in "$@"; do
  if [[ "$arg" == "--" && $inserted -eq 0 ]]; then
    args+=("$arg")
    args+=("${extra[@]}")
    inserted=1
  else
    args+=("$arg")
  fi
done

if [[ $inserted -eq 0 ]]; then
  args+=("--")
  args+=("${extra[@]}")
fi

exec "$INSIGHTS_BIN" "${args[@]}"
