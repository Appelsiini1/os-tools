/*
 * Käyttöjärjestelmät ja systeemiohjelmointi
 * Harjoitustyö osa 1/?
 * Syksy 2019
 * Rami Saarivuori & Aarne Savolainen
 * my-grep, hakee tiedostoista hakusanaa
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	if (argc == 1) { //jos argumentteja ei ole annettu, tulostetaan käyttöohje ja lopetetaan
		printf("my-grep: searchterm [file ...]\n");
		exit(0);
	};
	char buffer[250], *cp; //lukubufferi ja hakumuuttuja
	if (argc == 2) { //vain hakusana
		fgets(buffer, 250, stdin); //koska vain hakusana, luetaan stdin streamistä
		cp = strstr(buffer, argv[1]); //haetaan annettua hakusanaa ja tulos tallennetaan muuttujaan
		if (cp == NULL) { //jos hakusanaa ei löydä annetusta merkkijonosta, lopetetaan
			exit(0);
		} else { //hakusana löytyi, tulostetaan koko bufferi
			printf("%s", buffer);
			exit(0);
	};};

	FILE *fp;
	char* buff = NULL; //Lukubufferi
	size_t n; 
	ssize_t a; //tähän tallennetaan merkkien määrä jonka getline() antaa
	for (int i=2;i<argc;i++) { //useampi tiedosto, joten silmukka
		fp = fopen(argv[i], "r"); //avataan tiedosto
		if (fp == NULL) { //avaus epäonnistui, tulostetaan virheilmoitus ja lopetetaan
			printf("my-grep: cannot find file %s", argv[i]);
			exit(1);
		};
		a = getline(&buff, &n, fp); //haetaan tiedostosta ensimmäinen rivi
		while (a >= 0) { //silmukka kunnes rivilllä ei ole enää merkkejä (tiedoston loppu)
			cp = strstr(buff, argv[1]); //haetaan vastaavuutta hakusanalle
			if (cp != NULL) {
				printf("%s", buff);
			};
			a = getline(&buff, &n, fp); //haetaan seuraava rivi
		};};
		fclose(fp);
		return 0;
	}
