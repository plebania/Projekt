#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include "./wielomiany.h"

/* UWAGA: liczbę używanych f. bazowych można ustawić przez wartość
          zmiennej środowiskowej APPROX_BASE_SIZE
*/

/*
 * Funkcje bazowe: n - liczba funkcji a,b - granice przedzialu aproksymacji i
 * - numer funkcji x - wspolrzedna dla ktorej obliczana jest wartosc funkcji
 */

double fi(double a, double b, int n, int i, double x)
{
    struct wielomian *pom = wielomian_czebyszewa(i);
    double out = val_wielomian(pom, x);
    free(pom->wsp);
    free(pom);
    return out;
}

/* Pierwsza pochodna fi */
double
dfi(double a, double b, int n, int i, double x)
{
    struct wielomian *pom = wielomian_czebyszewa(i), *pom1;
    pom1 = pochodna_wielomianu(pom);
    free(pom->wsp);
    free(pom);
    double out = val_wielomian(pom1, x);
    free(pom1->wsp);
    free(pom1);
    return out;
}

/* Druga pochodna fi */
double
d2fi(double a, double b, int n, int i, double x)
{
    struct wielomian *pom = wielomian_czebyszewa(i), *pom1;
    pom1 = nta_pochodna_wielomianu(pom, 2);
    free(pom->wsp);
    free(pom);
    double out = val_wielomian(pom1, x);
    free(pom1->wsp);
    free(pom1);
    return out;
}

/* Trzecia pochodna fi */
double
d3fi(double a, double b, int n, int i, double x)
{
    struct wielomian *pom = wielomian_czebyszewa(i), *pom1;

    pom1 = nta_pochodna_wielomianu(pom, 3);
    free(pom->wsp);
    free(pom);
    double out = val_wielomian(pom1, x);
    free(pom1->wsp);
    free(pom1);
    return out;
}

/* Pomocnicza f. do rysowania bazy */
double
xfi(double a, double b, int n, int i, FILE *out)
{
    double h = (b - a) / (n - 1);
    double h3 = h * h * h;
    int hi[5] = {i - 2, i - 1, i, i + 1, i + 2};
    double hx[5];
    int j;

    for (j = 0; j < 5; j++)
        hx[j] = a + h * hi[j];

    fprintf(out, "# nb=%d, i=%d: hi=[", n, i);
    for (j = 0; j < 5; j++)
        fprintf(out, " %d", hi[j]);
    fprintf(out, "] hx=[");
    for (j = 0; j < 5; j++)
        fprintf(out, " %g", hx[j]);
    fprintf(out, "]\n");
}