#!/usr/bin/env bash

set -e  # Stop on error

BINARY="./build/devbuddy"

# If binary doesn't exist, build it
if [ ! -f "$BINARY" ]; then
    echo "🧱 No build found. Building project..."
    mkdir -p build
    cd build
    cmake ..
    make
    cd ..
fi

echo "🚀 Running the program..."
"$BINARY"
