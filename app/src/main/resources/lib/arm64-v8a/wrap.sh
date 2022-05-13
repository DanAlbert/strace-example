#!/system/bin/sh
HERE="$(cd "$(dirname "$0")" && pwd)"

echo "Running $@ in $HERE"
$HERE/libstrace.so -f -e "futex" "$@"