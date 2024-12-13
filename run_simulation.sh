#!/bin/bash

if [ $# == 0 ];then
    echo "Please specify number of events!";
    exit
fi

if [ ! -d "root" ]; then
    mkdir root
fi

cd geant4
./make.sh
cd build
./geant4 $1 60
cd ../..

root -l g4coin.C
root -l g4anticompton.C
root -l g4reso.C
root -l g4hist.C

echo "Done!"