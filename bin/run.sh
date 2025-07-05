#!/bin/bash

TARGET_SCRIPT="bin/exec.sh"

docker run \
  --rm \
  --name procon-runner \
  -v "$(pwd)":/work \
  -w /work \
  procon-env \
  bash "${TARGET_SCRIPT}" "$@"