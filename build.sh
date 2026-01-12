#!/bin/sh
set -e

mkdir -p build
g++ -o ./build/tsu -Iinclude -Wall -O3 src/*.cpp
