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
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

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
			if (a==0) { //jos mitään ei annettu, palataan silmukan alkuun
			} else {
				parser(buff); //muussa tapauksessa heitetään syöte parserille
			};
		};
	};
};

void parser(char strings[]) {
	char *com, delim[2] = " "; //strtok:in kanssa käytettävät muuttujat, token ja parsittava merkki (välilyönti)
	const char stop[6] = "exit", change[4] = "cd", polku[6] = "path"; //sisäänrakennetut komennot exit, cd, path
	
	/* Tämä koodin pätkä: https://cboard.cprogramming.com/c-programming/70320-how-remove-newline-string.html */
	/* ****** */
	int len = strlen(strings); //rivinvaihto pois lopusta
	if ( strings[len-1] == '\n' ) {
		strings[len-1] = 0;
	}
	/* ****** */
	com = strtok(strings, delim);
	if (strcmp(com,stop) == 0) { //exit
		exit(0);
	} else if (strcmp(change, com) == 0) {//cd
		char *com2; //väliaikainen muuttuja useamman argumentin tarkistuksen vuoksi
		if ((com = strtok(NULL, delim)) == NULL) { //jos argumentteja ei annettu, palataan
			printf("No arguments given\n");
			com2 = NULL; 
		} else {
			com2 = com; //asetetaan väliaikainen muuttuja ensimmäiseksi argumentiksi, jotta voidaan tarkistaa onko argumentteja useampia
		}
		
		if ((com = strtok(NULL, delim)) != NULL) { //useampien argumenttien tarkistus
			printf("Too many arguments given!\n");
		} else if (com2 != NULL) { // ei useampia argumentteja, yritetään vaihtaa kansiota
			if (chdir(com2) != 0) {
				printf("Error changing directories\n"); //jos epäonnistuu, tulostetaan virheilmoitus
			}
		}
	} else if (strcmp(com, polku) == 0) {//path
		
	} else {//komentoa ei tunnistettu, yritetään suorittaa
		/* fork(), execv() ja wait() komentojen toteutuksessa käytetty apuna kurssikirjan lukua.
		 * (http://pages.cs.wisc.edu/~remzi/OSTEP/cpu-api.pdf) 
		 */
		char *myargs, *file;
		char delim2[2] = ">";
		char **passed_args;
		if ((passed_args = malloc(2* sizeof(char))) == NULL) {
			printf("Memory allocation failed\n");
			exit(1);
		};
		int i=1;
		
		if ((myargs = strtok(NULL, delim2)) !=NULL){
			file = strtok(NULL, delim2);
		};
		file = file;
		passed_args[0] = strdup(com);
		while ((com = strtok(myargs, delim)) != NULL) {
			if ((passed_args = (char **) realloc(passed_args, sizeof(passed_args)+sizeof(char))) == NULL) {
				printf("Memory allocation failed\n");
				exit(1);
			}
			passed_args[i] = strdup(com);
		}
		passed_args[i+1] = NULL;
		
		if (fork() == 0) {
					
		//Tähän koodinpätkää otettu mallia täältä: https://stackoverflow.com/questions/2605130/redirecting-exec-output-to-a-buffer-or-file
		/* ****** */
		if (file != NULL) {
			int redir = open(file, O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);
			
			dup2(redir, 1);
			
			close(redir);
		}
		
		/* ****** */
		
		char* path_var;
		for (int i=0;i<x;i++) {
			
			path_var = concat(com, path);
		
			execv(path_var, passed_args);
		}
		
		
		
	}
	free(passed_args);
	
	
	
}

char* concat(const char *s1, const char *s2) //merkkijonojen yhdistämiseen tarkoitettu funktio
{ //https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
	char *result;
    if ((result = malloc(strlen(s1) + strlen(s2) + 1))==NULL) { // +1 for the null-terminator
		printf("Memory allocation failed");
		exit(1);
	};
    strcpy(result, s1);
    strcat(result, s2);
    return result; //tulos
};
