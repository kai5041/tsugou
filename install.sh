#!/bin/bash

set -e  # Stop execution on error

echo "WORK IN PROGRESS"

mkdir -p build && cd build
cmake -G Ninja .. -Wno-dev
