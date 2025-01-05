#!/bin/bash
set -e  # Stop execution on error

mkdir -p build && cd build
cmake -G Ninja ..
ninja -j$(nproc)
cd ..
./build/tsu $@
