#ifndef WIELOMIANY_H
#define WIELOMIANY_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h> //wygodniejsze typy
#include <math.h>
struct wielomian
{
    uint8_t stopien;
    double *wsp; //wspolczynniki przy potegach zmiennej
};

struct wielomian *init_wielomian(uint8_t stopien);
double val_wielomian(struct wielomian *a, double x);
void wypisz_wielomian(struct wielomian *a);

struct wielomian *mul_wielomian(struct wielomian *a, struct wielomian *b);
struct wielomian *add_wielomian(struct wielomian *a, struct wielomian *b);
struct wielomian *sub_wielomian(struct wielomian *a, struct wielomian *b); //a-b
struct wielomian *wielomian_czebyszewa(uint8_t stopien);
struct wielomian *pochodna_wielomianu(struct wielomian *a);
struct wielomian *nta_pochodna_wielomianu(struct wielomian *a, uint8_t n);
#endif
