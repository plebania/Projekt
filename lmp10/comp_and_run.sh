#!/bin/bash	
cd gaus	
make -B	
cd ..	
make -B	czebyszkiewicz
./czebyszewik -s spl -p test/dane.1 -g myplot -f 5.1 -t 5.7  -n 300
make -B	sklejane
./sklejane -s spl -p test/dane.1 -g myplot -f 5.1 -t 5.7  -n 300
