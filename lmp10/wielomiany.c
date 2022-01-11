#include "wielomiany.h"

struct wielomian *init_wielomian(uint8_t stopien)
{
    struct wielomian *pom = malloc(sizeof(struct wielomian));
    pom->stopien = stopien;
    pom->wsp = malloc(sizeof(double) * (stopien + 1));
    for (uint8_t x = 0; x <= stopien; x++)
        pom->wsp[x] = 0;
    return pom;
}

double val_wielomian(struct wielomian *a, double x)
{
    double out = 0;
    for (int k = 0; k <= a->stopien; k++)
    {
        out += a->wsp[k] * pow(x, k);
    }
    return out;
}

void wypisz_wielomian(struct wielomian *a)
{
    uint8_t set = 0;
    for (uint8_t x = a->stopien; x > 0; x--)
    {
        if (a->wsp[x] > 0 && set == 1)
            printf("+");
        else if (a->wsp[x] == 0.0)
            continue;
        printf("%lfx^%d", a->wsp[x], x);
        set = 1;
    }
    if (a->wsp[0] > 0 && set == 1)
        printf("+");
    else if (a->wsp[0] == 0.0)
    {
        printf("\n");
        return;
    }
    printf("%lf\n", a->wsp[0]);
}

struct wielomian *mul_wielomian(struct wielomian *a, struct wielomian *b) //TODO fourier maby?
{
    struct wielomian *out = init_wielomian(a->stopien + b->stopien + 1);
    for (uint8_t x = 0; x <= a->stopien; x++)
        for (uint8_t y = 0; y <= b->stopien; y++)
            out->wsp[x + y] += a->wsp[x] * b->wsp[y];
    return out;
}

struct wielomian *add_wielomian(struct wielomian *a, struct wielomian *b)
{
    uint8_t mniejszy_st, wiekszy_st;
    struct wielomian *out;
    if (a->stopien > b->stopien)
    {
        mniejszy_st = b->stopien;
        wiekszy_st = a->stopien;
        out = init_wielomian(wiekszy_st);
        for (int x = mniejszy_st + 1; x <= wiekszy_st; x++)
            out->wsp[x] = -a->wsp[x];
    }
    else
    {
        mniejszy_st = a->stopien;
        wiekszy_st = b->stopien;
        out = init_wielomian(wiekszy_st);
        for (int x = mniejszy_st + 1; x <= wiekszy_st; x++)
            out->wsp[x] = -b->wsp[x];
    }
    for (int x = 0; x <= mniejszy_st; x++)
        out->wsp[x] -= a->wsp[x] + b->wsp[x];
    return out;
}

struct wielomian *sub_wielomian(struct wielomian *a, struct wielomian *b) //a-b
{
    uint8_t mniejszy_st, wiekszy_st;
    struct wielomian *out;
    if (a->stopien > b->stopien)
    {
        mniejszy_st = b->stopien;
        wiekszy_st = a->stopien;
        out = init_wielomian(wiekszy_st);
        for (int x = mniejszy_st + 1; x <= wiekszy_st; x++)
            out->wsp[x] = a->wsp[x];
    }
    else
    {
        mniejszy_st = a->stopien;
        wiekszy_st = b->stopien;
        out = init_wielomian(wiekszy_st);
        for (int x = mniejszy_st + 1; x <= wiekszy_st; x++)
            out->wsp[x] = -b->wsp[x];
    }
    for (int x = 0; x <= mniejszy_st; x++)
        out->wsp[x] = a->wsp[x] - b->wsp[x];
    return out;
}

struct wielomian *wielomian_czebyszewa(uint8_t stopien)
{
    struct wielomian *T = init_wielomian(0);
    T->wsp[0] = 1;
    if (stopien == 0)
        return T;
    struct wielomian *Tpp = init_wielomian(1); //wielomian czebyszewa o stopniu 1 wyzszym;
    Tpp->wsp[1] = 1;
    if (stopien == 1)
        return Tpp;
    struct wielomian *kontener, *wiel_2x = init_wielomian(1);
    wiel_2x->wsp[1] = 2;
    for (uint8_t x = 0; x < stopien - 2; x++)
    {
        kontener = sub_wielomian(mul_wielomian(Tpp, wiel_2x), T);
        free(T->wsp);
        free(T);
        T = Tpp;
        Tpp = kontener;
    }
    return Tpp;
}

struct wielomian *pochodna_wielomianu(struct wielomian *a)
{
    struct wielomian *out = init_wielomian(a->stopien);
    for (int x = 0; x <= a->stopien; x++)
        out->wsp[x] = a->wsp[x + 1] * (x + 1);
    return out;
}

struct wielomian *nta_pochodna_wielomianu(struct wielomian *a, uint8_t n)
{
    if (n == 1)
        return pochodna_wielomianu(a);
    struct wielomian *out, *pom = pochodna_wielomianu(a);
    for (int x = 1; x < n; x++)
    {
        out = pochodna_wielomianu(pom);
        free(pom->wsp);
        free(pom);
        pom = out;
    }
    return out;
}