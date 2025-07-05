#!/bin/bash

TARGET_SCRIPT="bin/exec.sh"

docker run \
  -i \
  --rm \
  --name procon-runner \
  -e USE_IN_TXT="${USE_IN_TXT}" \
  -v "$(pwd)":/work \
  -w /work \
  procon-env \
  bash "${TARGET_SCRIPT}" "$@"