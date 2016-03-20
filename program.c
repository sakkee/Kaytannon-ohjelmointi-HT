#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "tietorakenne.h"
#include "tiedosto.h"
#include "funktio.h"



int main(void) {
    Alkio *pAlku = NULL;
    Alkio2 *tAlku = NULL;
    pAlku = lue(); //Listassa on tiedostossa luettujen pullojen tiedot
    tilapaistiedosto(0,0,0,0); //Tyhjennetään tilapaistiedosto.txt ja lisätään otsikko
    int valinta_int = 1;
    printf("\nPULLONPALAUTUSAUTOMAATTI\n");
    do {
   		char *valinta_tarkistus = malloc(sizeof(char)*128);

            printf("\nAutomaatti on valmis ottamaan vastaan pullot ja tölkit.\n\n1) Aloita palautus\n0) Lopeta\n\nValitse: ");
            scanf("%s", valinta_tarkistus);
		if (syotteentarkistus(valinta_tarkistus)==0) {
			printf("\nVäärä valinta!\n");
			free(valinta_tarkistus);
		}
		else {
		
            valinta_int = atoi(valinta_tarkistus); //Muutetaan char-input int:ksi
	free(valinta_tarkistus);

   		 switch (valinta_int) {
       			 case 1:
           		 tAlku = syottamista(pAlku, tAlku);
          			 break;
   		 case 0:
   			 break;
       		 default:
           		 printf("\nVäärä valinta!\n");
           		 break;
   	 }
}
    } while(valinta_int !=0);
    printf("Suljetaan pullonpalautusautomaatti.\n");
    tiedostoonkirjoitus(tAlku);
    	exit(0);
   	 
}