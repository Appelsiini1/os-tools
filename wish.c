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

int main(int argc, char *argv[]) {
	if ( argc > 2 ) { /* Liikaa argumentteja */
		printf("Too many arguments. There should be at most one argument.\n");
		exit(1);
	} else if ( argc == 2 ) { /*Bash mode, luetaan tekstitiedostosta käskyt */
		char *line_buf = NULL;
		size_t line_buf_size = 0;
		int line_count = 0;
		ssize_t line_size;



		FILE *fp = fopen(argv[1], "r");
			
			if (fp == NULL) {
				printf("Error: cannot open file %s\n", argv[1]);
				exit(1);
			}
			
			printf("Reading file %s\n", argv[1]);
			
			line_size = getline(&line_buf, &line_buf_size, fp);
			while (line_size >= 0) {
				line_count++;
				
				line_size = getline(&line_buf, &line_buf_size, fp);
			}
			
			free(line_buf);
			line_buf = NULL;
			
			fclose(fp);
			exit(0);
	} else {
		char* buff = NULL; //lukupuskuri
		size_t n;
		ssize_t a; //merkkien määrä
		while (1) { //interactive mode
			printf("wish> ");
			a = getline(&buff, &n, stdin);
			if (a==0) {
			} else {
				parser(buff);
			};
		};	
	}
	
}

void parser(char strings[]) {
	char *com, delim[2] = " "; //strtok:in kanssa käytettävät muuttujat, token ja parsittava merkki (välilyönti)
	char stop[5] = "exit", change[3] = "cd", polku[5] = "path"; //sisäänrakennetut komennot exit, cd, path
	if (com == stop) { //exit
		exit(0);
	};
	if (com == change) { //cd
		
	};
	if (com == polku) { //path
		
	} else { //komentoa ei tunnistettu
		printf("Command not recognized");
	}
}

char* concat(const char *s1, const char *s2) //merkkijonojen yhdistämiseen tarkoitettu funktio
{ //https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
	char *result;
    if ((*result = malloc(strlen(s1) + strlen(s2) + 1))==NULL) { // +1 for the null-terminator
		printf("Memory allocation failed");
		exit(1);
	};
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
