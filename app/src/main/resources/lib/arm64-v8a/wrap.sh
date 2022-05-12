#!/system/bin/sh
HERE="$(cd "$(dirname "$0")" && pwd)"
echo "Running app in $HERE"
$HERE/libstrace.so "$@"