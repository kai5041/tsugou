#!/bin/sh
set -e

./build.sh
sudo cp ./build/tsu /usr/local/bin/tsu
echo "Tsugou installed successfully. Use 'tsu' for more."
