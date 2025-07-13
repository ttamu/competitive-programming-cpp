#!/bin/bash

# --- Configuration ---
TARGET_EXEC_SCRIPT="bin/exec.sh"
DEFAULT_FILE="src/main.cpp"
INPUT_FILE_PATH="data/in.txt"

# --- Usage Function ---
show_usage() {
  echo "Usage: make run [f=<problem_file>] [in=1]" >&2
  echo "Example: make run                               (runs src/main.cpp with stdin)" >&2
  echo "Example: make run in=1                           (runs src/main.cpp with data/in.txt)" >&2
  echo "Example: make run f=atcoder/abc111/d.cpp         (runs specified file with stdin)" >&2
  echo "Example: make run f=atcoder/abc111/d.cpp in=1  (runs specified file with data/in.txt)" >&2
}

# --- Argument Parsing ---
# $1: file to run (from make f=...)
# $2: in flag (from make in=...)

FILE_TO_RUN_ARG="$1"
INPUT_FLAG_ARG="$2"

# Determine FILE_TO_RUN, prepending src/ if necessary
FILE_TO_RUN=""
if [ -z "$FILE_TO_RUN_ARG" ]; then
    FILE_TO_RUN="$DEFAULT_FILE"
elif [[ "$FILE_TO_RUN_ARG" == src/* ]]; then
    FILE_TO_RUN="$FILE_TO_RUN_ARG"
else
    FILE_TO_RUN="src/$FILE_TO_RUN_ARG"
fi

# --- Pre-flight Checks and Usage Display ---
# Check if the target file exists
if [ ! -f "$FILE_TO_RUN" ]; then
    echo "Error: File not found: $FILE_TO_RUN" >&2
    show_usage
    exit 1
fi

# Check if data/in.txt exists when 'in' flag is set
if [ -n "$INPUT_FLAG_ARG" ] && [ ! -f "$INPUT_FILE_PATH" ]; then
    echo "Error: 'in=1' specified, but input file '$INPUT_FILE_PATH' not found." >&2
    show_usage
    exit 1
fi

# --- Determine Input Source and Echo Message ---
EXEC_ARGS="$FILE_TO_RUN"
if [ -n "$INPUT_FLAG_ARG" ]; then
    EXEC_ARGS="$EXEC_ARGS $INPUT_FILE_PATH"
    echo "Running $FILE_TO_RUN with $INPUT_FILE_PATH..."
else
    echo "Running $FILE_TO_RUN with stdin..."
fi

# --- Execute in Docker ---
docker run \
  -i \
  --rm \
  -v "$(pwd)":/work \
  -w /work \
  procon-env \
  bash "${TARGET_EXEC_SCRIPT}" $EXEC_ARGS