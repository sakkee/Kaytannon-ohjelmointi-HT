#include <stdio.h>
#include "tiedosto.h"
#include "tietorakenne.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

//Luetaan tiedosto
void *lue () {
	Alkio *pAlku = NULL;
	char muisti[256];
	FILE* tiedosto;
	tiedosto = fopen("tuotetiedosto.txt", "r"); //Avataan tiedosto
	while (fgets(muisti, sizeof(muisti)-1, tiedosto) != NULL) { //Kun rivinluku onnistuu niin...
        	char *memory;
        	memory = strtok(muisti, " "); //rivi memoryyn, " "-merkillä
        	char nimi[12];
        	strcpy(nimi, memory);
        	memory = strtok(NULL, " "); //memory on nyt rivin toinen alkio
        	float koko = atof(memory);
        	memory = strtok(NULL, " "); //memory on nyt rivin kolmas alkio
        	memory[strcspn ( memory, "\n" )] = '\0';
        	float hinta = atof(memory);
        	pAlku = lisataan(pAlku, nimi, koko, hinta); //lisätään saadut tiedot linkitettyyn listaan
    	}
    	return pAlku;
}
int tilapaistiedosto(char s[], float x, float y, int valinta) {    
	FILE* tiedosto;
	//Jos valinta==0, niin ajetaan ensimmäistä kertaa eli lisätään otsikko
   	 if (valinta==0) {
   		 tiedosto = fopen("tilapaistiedosto.txt", "w");
   	 	fprintf(tiedosto, "Tilapäinen lokitiedosto\n\n");
    		fclose(tiedosto);
    	}
	//Jos ei ajeta, eli otsikko on jo, silloin appendataan
   	 else {
    		tiedosto=fopen("tilapaistiedosto.txt", "a");
		time_t t = time(NULL);
		struct tm tm = *localtime(&t);
		fprintf(tiedosto, "%d.%d.%d %d:%d:%s-%.2fl:%.2f€.\n", tm.tm_mday, (tm.tm_mon + 1), (tm.tm_year + 1900), tm.tm_hour, tm.tm_min, s, x, y); //TÄSSÄ NYT TIMESTAMPIT
		fclose(tiedosto);
   	 }
	return 0; 
    
}
void *tiedostoonkirjoitus(Alkio2 *tAlku) {
	FILE* tiedosto;
	tiedosto = fopen("lokitiedosto.txt", "a");
	Alkio2 *ptr = NULL;
	ptr = tAlku;
	int palautukset = 0;
	float eurot = 0;
	while (ptr!=NULL) {
    	palautukset+=ptr->maara;
    	eurot+=ptr->maara*ptr->hinta;
    	ptr=ptr->pSeuraava;
	}
	time_t t = time(NULL);
	struct tm tm = *localtime(&t);
	fprintf(tiedosto, "%d.%d.%d %d:%d - Palautukset %d kpl. Pantit %.2f€.\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min, palautukset, eurot); //TIMESTAMPIT PITÄISI TOIMIA
	fclose(tiedosto);
	return 0;
}