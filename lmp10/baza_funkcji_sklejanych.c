
#include <stdio.h>

double fi(double a, double b, int n, int i, double x)
{
    double h = (b - a) / (n - 1);
    double h3 = h * h * h;
    int hi[5] = {i - 2, i - 1, i, i + 1, i + 2};
    double hx[5];
    int j;

    for (j = 0; j < 5; j++)
        hx[j] = a + h * hi[j];

    if ((x < hx[0]) || (x > hx[4]))
        return 0;
    else if (x >= hx[0] && x <= hx[1])
        return 1 / h3 * (x - hx[0]) * (x - hx[0]) * (x - hx[0]);
    else if (x > hx[1] && x <= hx[2])
        return 1 / h3 * (h3 + 3 * h * h * (x - hx[1]) + 3 * h * (x - hx[1]) * (x - hx[1]) - 3 * (x - hx[1]) * (x - hx[1]) * (x - hx[1]));
    else if (x > hx[2] && x <= hx[3])
        return 1 / h3 * (h3 + 3 * h * h * (hx[3] - x) + 3 * h * (hx[3] - x) * (hx[3] - x) - 3 * (hx[3] - x) * (hx[3] - x) * (hx[3] - x));
    else /* if (x > hx[3]) && (x <= hx[4]) */
        return 1 / h3 * (hx[4] - x) * (hx[4] - x) * (hx[4] - x);
}

/* Pierwsza pochodna fi */
double
dfi(double a, double b, int n, int i, double x)
{
    double h = (b - a) / (n - 1);
    double h3 = h * h * h;
    int hi[5] = {i - 2, i - 1, i, i + 1, i + 2};
    double hx[5];
    int j;

    for (j = 0; j < 5; j++)
        hx[j] = a + h * hi[j];

    if ((x < hx[0]) || (x > hx[4]))
        return 0;
    else if (x >= hx[0] && x <= hx[1])
        return 3 / h3 * (x - hx[0]) * (x - hx[0]);
    else if (x > hx[1] && x <= hx[2])
        return 1 / h3 * (3 * h * h + 6 * h * (x - hx[1]) - 9 * (x - hx[1]) * (x - hx[1]));
    else if (x > hx[2] && x <= hx[3])
        return 1 / h3 * (-3 * h * h - 6 * h * (hx[3] - x) + 9 * (hx[3] - x) * (hx[3] - x));
    else /* if (x > hx[3]) && (x <= hx[4]) */
        return -3 / h3 * (hx[4] - x) * (hx[4] - x);
}

/* Druga pochodna fi */
double
d2fi(double a, double b, int n, int i, double x)
{
    double h = (b - a) / (n - 1);
    double h3 = h * h * h;
    int hi[5] = {i - 2, i - 1, i, i + 1, i + 2};
    double hx[5];
    int j;

    for (j = 0; j < 5; j++)
        hx[j] = a + h * hi[j];

    if ((x < hx[0]) || (x > hx[4]))
        return 0;
    else if (x >= hx[0] && x <= hx[1])
        return 6 / h3 * (x - hx[0]);
    else if (x > hx[1] && x <= hx[2])
        return 1 / h3 * (6 * h - 18 * (x - hx[1]));
    else if (x > hx[2] && x <= hx[3])
        return 1 / h3 * (6 * h - 18 * (hx[3] - x));
    else /* if (x > hx[3]) && (x <= hx[4]) */
        return 6 / h3 * (hx[4] - x);
}

/* Trzecia pochodna fi */
double
d3fi(double a, double b, int n, int i, double x)
{
    double h = (b - a) / (n - 1);
    double h3 = h * h * h;
    int hi[5] = {i - 2, i - 1, i, i + 1, i + 2};
    double hx[5];
    int j;

    for (j = 0; j < 5; j++)
        hx[j] = a + h * hi[j];

    if ((x < hx[0]) || (x > hx[4]))
        return 0;
    else if (x >= hx[0] && x <= hx[1])
        return 6 / h3;
    else if (x > hx[1] && x <= hx[2])
        return -18 / h3;
    else if (x > hx[2] && x <= hx[3])
        return 18 / h3;
    else /* if (x > hx[3]) && (x <= hx[4]) */
        return -6 / h3;
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