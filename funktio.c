#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "funktio.h"
#include "tietorakenne.h"
#include "tiedosto.h"
#define MAX_LINE 20

int syotteentarkistus(char s[]) {
	int x =0;
	for (x=0; x<strlen(s); x++) {
		int testaus = s[x];
		if (!isdigit(testaus)) {
			return 0;
		}
	}
	return 1;
}


int printtaus(char s[], float x, float y) {
    char buffer[20];
    sprintf(buffer, " %s %.2fl", s, x);
    int i = 20-strlen(buffer);
    printf("\nSyötetty:%s", buffer);
    printf("%*s\n", i, " ");
    tilapaistiedosto(s, x, y, 1);
    return 0;
}

void *syottamista(Alkio* pAlku, Alkio2* tAlku) {
	int valinta_int_2;
    	while(1) {
   		char *valinta_tarkistus_2 = malloc(sizeof(char)*128);
printf("Syötä uusi pullo tai tölkki.\n\n1) pullo 0.33l\n2) pullo 0.50l\n3) pullo 1.50l\n4) tölkki 0.33l\n5) tölkki 0.50l\n6) kossupullo 0.75l\n7) maitopurkki 1.00l\n8) Lopeta syöttö ja tulosta kuitti.\n--> ");
scanf("%s", valinta_tarkistus_2);
		if (syotteentarkistus(valinta_tarkistus_2) == 0) {
			printf("\nVäärä valinta!\n");
			free(valinta_tarkistus_2);
		}
		else {
            		valinta_int_2 = atoi(valinta_tarkistus_2);
			free(valinta_tarkistus_2);

   		 	switch (valinta_int_2) {
       			 case 8:
   			 	tulostetaan(tAlku);
   			 	printf("\nPULLONPALAUTUSAUTOMAATTI\n");
           			 	return tAlku;
       		 	default:
           		 	if (valinta_int_2 >0 && valinta_int_2 <8) {
               			 tAlku = pullonpalautus(pAlku, tAlku, valinta_int_2);
           		 	}
           		 	else {
               			 printf("\nVäärä valinta!\n");
           			 }
   	 		}
    	}
	}
    return 0;
}