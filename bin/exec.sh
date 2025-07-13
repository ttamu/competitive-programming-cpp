#!/bin/bash

# $1: Source file to compile and run (e.g., src/atcoder/abc111/d.cpp or src/main.cpp)
# $2: Optional input file path (e.g., data/in.txt)

SRC_FILE="$1"
INPUT_FILE="$2"

# Compile the C++ code
g++ -std=c++23 -I. "$SRC_FILE" -o main

# Check if compilation was successful
if [ $? -ne 0 ]; then
    echo "Compilation failed." >&2
    exit 1
fi

# Run the compiled program
if [ -n "$INPUT_FILE" ]; then
    # Use the specified input file
    ./main < "$INPUT_FILE" > data/out.txt
else
    # Use standard input
    ./main > data/out.txt
fi

# Display the output
cat data/out.txt

# Optional: Run tests (commented out for now)
#oj t -d tests -c "./main"