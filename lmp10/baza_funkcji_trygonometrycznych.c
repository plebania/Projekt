#include "baza.h"

#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <math.h>

/* UWAGA: liczbę używanych f. bazowych można ustawić przez wartość
          zmiennej środowiskowej APPROX_BASE_SIZE
*/

/*
 * Funkcje bazowe: n - liczba funkcji a,b - granice przedzialu aproksymacji i
 * - numer funkcji x - wspolrzedna dla ktorej obliczana jest wartosc funkcji
 */

double fi(double a, double b, int n, int i, double x)
{
    int pom = i / 2;
    double pom1 = pom + 1;
    if (i == 0)
        return 1;
    if (i % 2)
        return sin(pom1 * x);
    return cos(pom1 * x);
}

/* Pierwsza pochodna fi */
double
dfi(double a, double b, int n, int i, double x)
{
    int pom = i / 2;
    double pom1 = pom + 1;
    if (i == 0)
        return 0;
    if (i % 2)
        return cos(pom1 * x) * pom1;
    return -sin(pom1 * x) * pom1;
}

/* Druga pochodna fi */
double
d2fi(double a, double b, int n, int i, double x)
{
    int pom = i / 2;
    double pom1 = pom + 1;
    if (i == 0)
        return 0;
    if (i % 2)
        return -sin(pom1 * x) * pom1 * pom1;
    return -cos(pom1 * x) * pom1 * pom1;
}

/* Trzecia pochodna fi */
double
d3fi(double a, double b, int n, int i, double x)
{
    int pom = i / 2;
    double pom1 = pom + 1;
    if (i == 0)
        return 0;
    if (i % 2)
        return -cos(pom1 * x) * pom1 * pom1 * pom1;
    return sin(pom1 * x) * pom1 * pom1 * pom1;
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