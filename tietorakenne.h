#ifndef tietorakenne_h
#define tietorakenne_h
typedef struct alkio {
    char nimi[12];
    	float koko;
    	float hinta;
   	struct alkio *pSeuraava;
} Alkio;
typedef struct alkio2 {
    char nimi[12];
    	float koko;
    	float hinta;
    int maara;
    struct alkio2 *pSeuraava;
} Alkio2;
void *pullonpalautus(Alkio *pAlku, Alkio2 *tAlku, int valinta);
void *lisataan(Alkio* ppAlku, char tNimi[12], float koko, float hinta);
void *tulostetaan(Alkio2* tAlku);
#endif