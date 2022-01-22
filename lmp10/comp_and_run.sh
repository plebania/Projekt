#!/bin/bash	
cd gaus	
make -B	
cd ..	
make -B	czebyszew
./czebyszew -s spl -p test/dane_tan.1 -g czebyszew_plot -f 5.1 -t 5.7  -n 300
make -B	sklejane
./sklejane -s spl -p test/dane_tan.1 -g sklejane_plot -f 5.1 -t 5.7  -n 300
gnuplot -persist <<-EOFMarker
    plot 'test/dane.1', 'czebyszew_plot', 'sklejane_plot'
EOFMarker
