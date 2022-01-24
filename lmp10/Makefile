sklejane: main.o splines.o points.o baza_funkcji_sklejanych.o aproksymator_na_bazie.o gaus/libge.a
	$(CC) -Wall -Wextra -pedantic -o sklejane  main.o splines.o points.o baza_funkcji_sklejanych.o aproksymator_na_bazie.o -L gaus -l ge -lm

czebyszew: main.o splines.o points.o baza_wielomianow_czebyszewa.o aproksymator_na_bazie.o wielomiany.o gaus/libge.a
	$(CC) -g -Wall -Wextra -pedantic -o czebyszew main.o splines.o points.o baza_wielomianow_czebyszewa.o aproksymator_na_bazie.o wielomiany.o -L gaus -l ge -lm

trygonometryczne: main.o splines.o points.o baza_funkcji_trygonometrycznych.o aproksymator_na_bazie.o gaus/libge.a
	$(CC) -g -Wall -Wextra -pedantic -o trygonometryczne main.o splines.o points.o baza_funkcji_trygonometrycznych.o aproksymator_na_bazie.o -L gaus -l ge -lm


intrp: main.o splines.o points.o interpolator.o gaus/libge.a
	$(CC) -Wall -Wextra -pedantic -o intrp  main.o splines.o points.o interpolator.o -L gaus -l ge

prosta: main.o splines.o points.o prosta.o
	$(CC) -Wall -Wextra -pedantic -o prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie.o: makespl.h points.h baza.h gaus/piv_ge_solver.h
	$(CC) -Wall -Wextra -pedantic -I gaus -c aproksymator_na_bazie.c

interpolator.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -Wall -Wextra -pedantic -I gaus -c interpolator.c

#baza_wielomianow_czebyszewa.o: makespl.h points.h gaus/piv_ge_solver.h
#	$(CC) -Wall -Wextra -pedantic -I gaus -c baza_wielomianow_czebyszewa.c

#baza_funkcji_sklejanych.o: makespl.h points.h gaus/piv_ge_solver.h
#	$(CC) -Wall -Wextra -pedantic -I gaus -c baza_funkcji_sklejanych.c

.PHONY: clean

clean:
	-rm *.o czebyszew sklejane prosta
