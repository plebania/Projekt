#include <stdio.h>
#include <stdlib.h>
#include "wielomiany.h"

int main(){
	
	struct wielomian *wielomian_1= init_wielomian(2);
	printf("%d <- stopien\nssss", wielomian_1->stopien);

	wypisz_wielomian(wielomian_1);

	for(int i=2; i>=0; i--){
		wielomian_1->wsp[i]= (double)i + .5;
		//printf("%lf[%lf]\t", wielomian_1->wsp[i], (double)i + .5);
	}

	//printf("%d <- stopien\n", wielomian_1->stopien);

	struct wielomian *wielomian_2= init_wielomian(3);

	for(int i=3; i>=0; i--){
		wielomian_2->wsp[i]= (double)i * 2 + .5;
		//printf("%lf\t", (double)i *2 + .5);
	}

	wypisz_wielomian(wielomian_1);
	wypisz_wielomian(wielomian_2);

	struct wielomian *wielomian_dod= add_wielomian(wielomian_1, wielomian_2);
	
	wypisz_wielomian(wielomian_dod);

	struct wielomian *wielomian_sub= sub_wielomian(wielomian_dod, wielomian_1);

	printf("wiel_add - wiel_1 = wielomian_sub= ");
	wypisz_wielomian(wielomian_sub);
	printf("wiel_2 = ");
	wypisz_wielomian(wielomian_2);

	struct wielomian *wielomian_mul_1x2= mul_wielomian(wielomian_1, wielomian_2);

	wypisz_wielomian(wielomian_mul_1x2);
	
	struct wielomian *pochodna_wiel_mul= pochodna_wielomianu(wielomian_mul_1x2);

	wypisz_wielomian(pochodna_wiel_mul);

	for(int i= 1; i<5; i++){
		struct wielomian *pochodna_wiel_n= nta_pochodna_wielomianu(wielomian_mul_1x2, i);
		printf("%d. pochodna wiel= ", i);
		wypisz_wielomian(pochodna_wiel_n);
	}

	
	
	return 0;
}
