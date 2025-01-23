#!/bin/bash
set -e  # Stop execution on error

mkdir -p build && cd build
cmake -G Ninja .. -Wno-dev
ninja -j$(nproc)
cd ..
./build/tsu $@
