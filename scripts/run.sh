#!/bin/bash

CONTAINER_NAME="procon-cpp"

if ! docker ps -q -f name="$CONTAINER_NAME" | grep -q .; then
    echo "Error: Container not running. Run 'make up' first." >&2
    exit 1
fi

if [ -z "$1" ]; then
    SRC_FILE="src/main.cpp"
else
    SRC_FILE="src/bin/$1.cpp"
fi

if [ ! -f "$SRC_FILE" ]; then
    echo "Error: $SRC_FILE not found." >&2
    exit 1
fi

docker exec -i "$CONTAINER_NAME" bash -c "g++ -std=c++23 -Ilib '$SRC_FILE' -o main && ./main"
