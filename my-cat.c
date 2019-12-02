/*
 * Käyttöjärjestelmät ja systeemiohjelmointi
 * Harjoitustyö osa 1/6
 * Syksy 2019
 * Rami Saarivuori & Aarne Savolainen
 * my-cat, tulostaa tiedoston sisällön näytölle
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
	if (argc == 1) { //Jos argumentteja ei ole annettu, lopetetaan
		exit(0);
	};
	FILE *fp;
	char s[50]; //lukubufferi
	for (int i=0;i<(argc-1);i++) { //silmukka jotta voidaan tulostaa useampi tiedosto, jos annettu. argc-1, koska ensimmäinen on ohjelma oma nimi
		fp = fopen(argv[i+1], "r");

		if (fp == NULL) {
			printf("Cannot open file %s\n", argv[i+1]); //Jos ei voida avata tiedostoa syystä tai toisesta, tulostetaan virheilmoitus ja lopetetaan. 
			exit(1);
		};
		while (s != NULL) { //tulostus
		if (fgets(s, 50, fp) != NULL ) { //luetaan 50 merkkiä kerrallaan tiedostosta
			printf("%s", s);
		} else { //jos päästään tiedoston loppuun (fgets = NULL) lopetetaan silmukka
			break;
		};
	};
};
	fclose(fp); //suljetaan tiedosto
	
	return 0;
}
