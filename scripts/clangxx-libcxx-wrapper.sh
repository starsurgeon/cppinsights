#!/usr/bin/env bash
set -euo pipefail

CLANGXX_BIN="${CLANGXX_BIN:-/usr/bin/clang++-20}"
LIBCXX_HEADERS="${LIBCXX_HEADERS:-/usr/include/c++/v1}"
C_HEADERS="${C_HEADERS:-/usr/include}"
C_HEADERS_ARCH="${C_HEADERS_ARCH:-/usr/include/x86_64-linux-gnu}"
GCC_HEADERS="${GCC_HEADERS:-/usr/lib/gcc/x86_64-linux-gnu/13/include}"

extra=(
  -fexpansion-statements
  -freflection-latest
  -nostdinc++
  -isystem "$LIBCXX_HEADERS"
  -isystem "$C_HEADERS"
  -isystem "$C_HEADERS_ARCH"
  -isystem "$GCC_HEADERS"
)

exec "$CLANGXX_BIN" "${extra[@]}" "$@"
