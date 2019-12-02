/*
 * Käyttöjärjestelmät ja systeemiohjelmointi
 * Harjoitustyö osa 5/6
 * Syksy 2019
 * Rami Saarivuori & Aarne Savolainen
 * Basic shell: wish
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void parser (char *);
char* concat(const char *, const char *);

int main(int argc, char * argv[]) {
	
	if (argc == 2) { //batch mode
		printf("Tiedosto");
	} else {
		char* buff = NULL; //lukupuskuri
		size_t n;
		ssize_t a; //merkkien määrä
		while (1) { //interactive mode
			printf("wish> ");
			a = getline(&buff, &n, stdin);
			if (a==0) { //jos mitään ei annettu, palataan silmukan alkuun
			} else {
				parser(buff); //muussa tapauksessa heitetään syöte parserille
			};
		};
	};
};

void parser(char strings[]) {
	char *com, delim[2] = " "; //strtok:in kanssa käytettävät muuttujat, token ja parsittava merkki (välilyönti)
	char stop[5] = "exit", change[3] = "cd", polku[5] = "path"; //sisäänrakennetut komennot exit, cd, path
	com = strtok(strings, delim);
	if (com == stop) { //exit
		exit(0);
	};
	if (com == change) {//cd
		
	};
	if (com == polku) {//path
		
	} else {//komentoa ei tunnistettu
		printf("Command not recognized\n");
	}
}

char* concat(const char *s1, const char *s2) //merkkijonojen yhdistämiseen tarkoitettu funktio
{ //https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
    if (char *result = malloc(strlen(s1) + strlen(s2) + 1)==NULL) { // +1 for the null-terminator
		printf("Memory allocation failed\n");
		exit(1);
	};
    strcpy(result, s1);
    strcat(result, s2);
    return result; //tulos
}
