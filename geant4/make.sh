#!/bin/bash

if [ -d "build" ]; then
  echo "deleting folder ./build"
  rm -r build
fi

mkdir build
cd build
cmake ..
make -j20

echo "Done!"