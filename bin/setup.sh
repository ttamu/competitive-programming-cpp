#!/bin/bash

# Help message for the script
if [[ "$1" == "-h" || "$1" == "--help" ]]; then
  echo "Usage: $0 <directory_path>"
  echo "e.g., $0 atcoder/abc359"
  exit 0
fi

# Check if an argument is provided
if [ -z "$1" ]; then
  echo "Error: No directory path provided." >&2
  echo "Usage: $0 <directory_path>" >&2
  exit 1
fi

CONTEST_DIR="src/$1"

# Create the directory
mkdir -p "$CONTEST_DIR"
if [ $? -ne 0 ]; then
    echo "Error: Failed to create directory '$CONTEST_DIR'." >&2
    exit 1
fi

# Create files from a.cpp to g.cpp
for char in {a..g}; do
  cat "src/main.cpp" > "${CONTEST_DIR}/${char}.cpp"
done

echo "Successfully created directory and files in '$CONTEST_DIR'."
