#!/bin/bash

SRC_INPUT=${1:-main.cpp}

# Prepend "src/" if it's not already there
if [[ $SRC_INPUT == src/* ]]; then
    SRC="$SRC_INPUT"
else
    SRC="src/$SRC_INPUT"
fi

g++ -std=c++23 -I. "$SRC" -o main

if [ -n "$2" ]; then
    ./main < "$2" > data/out.txt
else
    ./main > data/out.txt
fi
cat data/out.txt
#oj t -d tests -c "./main"

