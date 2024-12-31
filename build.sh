#!/bin/bash

if [ ! -d "build" ]; then
  mkdir build
fi
cd build || exit

cmake ..
if [ $? -eq 0 ]; then
  make
  if [ $? -eq 0 ]; then
    cp prm ~/bin
  else
    echo "Make failed"
    exit 1
  fi
else
  echo "CMake configuration failed"
  exit 1
fi
