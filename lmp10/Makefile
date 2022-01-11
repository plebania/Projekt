aprox: main.o splines.o points.o aproksymator_na_bazie.o gaus/libge.a
	$(CC) -o aprox  main.o splines.o points.o aproksymator_na_bazie.o -L gaus -l ge

intrp: main.o splines.o points.o interpolator.o gaus/libge.a
	$(CC) -o intrp  main.o splines.o points.o interpolator.o -L gaus -l ge

prosta: main.o splines.o points.o prosta.o
	$(CC) -o prosta  main.o splines.o points.o prosta.o	

aproksymator_na_bazie.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c aproksymator_na_bazie.c

interpolator.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c interpolator.c

baza_wielomianow_czebyszewa.o: makespl.h points.h gaus/piv_ge_solver.h
	$(CC) -I gaus -c baza_wielomianow_czebyszewa.c

czebyszewik: main.o splines.o points.o baza_wielomianow_czebyszewa.o wielomiany.o gaus/libge.a
	$(CC) -o czebyszewik main.o splines.o points.o baza_wielomianow_czebyszewa.o wielomiany.o -L gaus -l ge -lm

.PHONY: clean

clean:
	-rm *.o aprox intrp prosta
