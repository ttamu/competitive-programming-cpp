#!/bin/bash

if [[ $# -lt 1 ]]; then
    echo "Usage: $0 <problem-id | contest/task | full-URL>"
    exit 1
fi

SPEC="$1"
TEST_DIR="tests"

if [[ "$SPEC" =~ ^https?:// ]]; then
    URL="$SPEC"
elif [[ "$SPEC" =~ ^[0-9]+$ ]]; then
    URL="https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=${SPEC}"
elif [[ "$SPEC" =~ ^[A-Za-z0-9_-]+/[A-Za-z0-9_-]+$ ]]; then
    contest="${SPEC%/*}"
    task="${SPEC#*/}"
    URL="https://atcoder.jp/contests/${contest}/tasks/${contest}_${task}"
else
    echo "Error: invalid problem spec → $SPEC"
    exit 1
fi

rm -rf "${TEST_DIR}"
oj download "${URL}" -d "${TEST_DIR}"
echo "Downloaded samples to ${TEST_DIR}/"