#!/bin/bash

# Help message for the script
if [[ "$1" == "-h" || "$1" == "--help" ]]; then
  echo "Usage: $0 <contest-problem_string>"
  echo "e.g., $0 abc359-d  (creates d.cpp)"
  echo "e.g., $0 abc359     (creates a.cpp ... g.cpp)"
  exit 0
fi

# Check if an argument is provided
if [ -z "$1" ]; then
  echo "Error: No contest string provided." >&2
  echo "Usage: $0 <contest-problem_string>" >&2
  exit 1
fi

CONTEST_STRING="$1"
CONTEST_NAME=$(echo "$CONTEST_STRING" | cut -d'-' -f1)
PROBLEM_LETTER=$(echo "$CONTEST_STRING" | cut -d'-' -f2)

CONTEST_DIR="src/atcoder/$CONTEST_NAME"

# Create the directory
mkdir -p "$CONTEST_DIR"
if [ $? -ne 0 ]; then
    echo "Error: Failed to create directory '$CONTEST_DIR'." >&2
    exit 1
fi

# Create files
if [ "$CONTEST_NAME" == "$PROBLEM_LETTER" ]; then
  # No problem letter provided, create a-g
  for char in {a..g}; do
    cat "src/template.cpp" > "${CONTEST_DIR}/${char}.cpp"
  done
  echo "Successfully created files a-g in '$CONTEST_DIR'."
else
  # Problem letter provided, create specific file
  cat "src/template.cpp" > "${CONTEST_DIR}/${PROBLEM_LETTER}.cpp"
  echo "Successfully created file ${PROBLEM_LETTER}.cpp in '$CONTEST_DIR'."
fi