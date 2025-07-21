#!/usr/bin/env bash

# run.sh — Run the compiled program

set -e  # Exit on error

BINARY="./build/devbuddy"

# Build if binary doesn't exist
if [ ! -f "$BINARY" ]; then
    echo "🧱 No build found. Running build first..."
    ./build.sh
fi

echo "🚀 Running the program..."
"$BINARY"
