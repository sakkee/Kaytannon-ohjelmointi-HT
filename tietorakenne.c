#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "tietorakenne.h"
#include "funktio.h"
#include <time.h>

//Palautettavan pullon tiedot, nimi, koko, hinta (tiedostonluku)



//Lisätään määrää listaan palautettavan pullon mukaan
void *pullonpalautus(Alkio *pAlku, Alkio2 *tAlku, int valinta) {
	int i=0;
	Alkio *temp;
	temp = pAlku;
	//Etsii halutun syötettävän pullon tiedot
	while (i<valinta-1) {
    	temp = temp->pSeuraava;
    	i++;
    	}
	Alkio2* pNew, *tmp;
	pNew = (Alkio2*)malloc(sizeof(Alkio2));
	//Jos palautettuja pulloja löytyy, niin
	if (tAlku != NULL) {
        	tmp = tAlku;
        	while (tmp->pSeuraava != NULL) {
        	if (tmp->koko == temp->koko && tmp->hinta == temp->hinta) {
            	tmp->maara++;
            	printtaus(tmp->nimi, tmp->koko, tmp->hinta);
            	return tAlku;
        	}
        	else {
            	tmp = tmp->pSeuraava;
        	}
        	}
    	if (tmp->koko == temp->koko && tmp->hinta == temp->hinta) {
        	tmp->maara++;
        	printtaus(tmp->nimi, tmp->koko, tmp->hinta);
        	return tAlku;
    	}
    	strcpy(pNew->nimi, temp->nimi);
        	pNew->koko = temp->koko;
        	pNew->hinta = temp->hinta;
        	pNew->maara = 1;
        	pNew->pSeuraava = NULL;
    	tmp->pSeuraava = pNew;
    	printtaus(pNew->nimi, pNew->koko, tmp->hinta);
    	return tAlku;
	}
    	else {
        	strcpy(pNew->nimi, temp->nimi);
        	pNew->koko = temp->koko;
        	pNew->hinta = temp->hinta;
        	pNew->maara = 1;
        	pNew->pSeuraava = NULL;
    	tAlku = pNew;
    	printtaus(pNew->nimi, pNew->koko, temp->hinta);
    	return tAlku;
    	}
	return tAlku;
}
//Lisätään uuden pullon tiedot (tiedostonluku)
void *lisataan(Alkio *pAlku, char tNimi[12], float koko, float hinta) {
    	Alkio* pNew, *temp;
    	pNew = (Alkio*)malloc(sizeof(Alkio));
    	strcpy(pNew->nimi, tNimi);
    	pNew->koko = koko;
    	pNew->hinta = hinta;
    	pNew->pSeuraava = NULL;
    
    	if (pAlku != NULL) {
        	temp = pAlku;
        	while (temp->pSeuraava != NULL) {
                	temp = temp->pSeuraava;
        	}
        	temp->pSeuraava = pNew;
    	}
    	else {
        	pAlku = pNew;
    	}
    	return pAlku;
}
//Tulostusfunktio, voidaan hiota lopulta kuitin tulostukseksi
void *tulostetaan(Alkio2* tAlku) {
    	Alkio2* ptr, *petri;
    	petri = tAlku;
	int y=0;
	while (petri!=NULL) {
    	y += petri->maara;
    	petri= petri->pSeuraava;
	}
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    printf("Kuitti %d.%d.%d %d:%d\n", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900, tm.tm_hour, tm.tm_min); //TIMESTAMPIT TOIMII NYT
	printf("\nPalautetut pullot ja tölkit yhteensä %d kappaletta.\n\n", y);
	float z = 0;
	ptr=tAlku;
    	while (ptr!=NULL) {
    	char buffer[20];
    	sprintf(buffer, "%s %.2fl", ptr->nimi, ptr->koko);
    	int i = 20-strlen(buffer);
    	printf("%s", buffer);
    	printf("%*s", i, " ");
    	printf("\t%10s %d x %.2f = %.2f€\n", "pantit", ptr->maara, ptr->hinta, ptr->maara*ptr->hinta);
    	z += ptr->maara*ptr->hinta;
        	ptr = ptr->pSeuraava;
    	}
	printf("\n\nPantit yhteensä %.2f€\n\n", z);
	return 0;
}