#!/bin/bash
cd gaus
make -B
cd ..
make -B clean
./aprox
