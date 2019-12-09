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

typedef struct path_t {
	char *dir;
	struct path_t *next;
} path, *pathPtr;

void parser (char *, pathPtr *);
char* concat(const char *, const char *);
void newPathF (char *, pathPtr *);
void freeMemory(pathPtr *);

int main(int argc, char *argv[]) {
	char defaultPath[] = "path /bin/";
	pathPtr paths = NULL;
	newPathF(defaultPath, &paths);
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
			
			/* Itse tiedoston luku */
			while (line_size >= 0) {
				line_count++;
				
				line_size = getline(&line_buf, &line_buf_size, fp);
				
				parser(line_buf, &paths);
			}
			
			/* Lopetetaan ohjelmasuoritus tiedoston lukemisen jälkeen */
			free(line_buf);
			line_buf = NULL;
			
			fclose(fp);
	} else {
		char* buff = NULL; //lukupuskuri
		size_t n;
		ssize_t a; //merkkien määrä
		while (1) { //interactive mode
			printf("wish> ");
			a = getline(&buff, &n, stdin);
			if (a==0) { //jos mitään ei annettu, palataan silmukan alkuun
			} else {
				parser(buff, &paths); //muussa tapauksessa heitetään syöte parserille
			};
		};	
	}
	
	freeMemory(&paths);
	
}

void parser(char strings[], pathPtr *paths) {
	char *com, delim[2] = " "; //strtok:in kanssa käytettävät muuttujat, token ja parsittava merkki (välilyönti)
	const char stop[6] = "exit", change[4] = "cd", polku[6] = "path"; //sisäänrakennetut komennot exit, cd, path	
	char strings2[strlen(strings)];
	strcpy(strings2, strings);
	
	/* Tämä koodin pätkä: https://cboard.cprogramming.com/c-programming/70320-how-remove-newline-string.html */
	/* ****** */
	int len = strlen(strings); //rivinvaihto pois lopusta
	if ( strings[len-1] == '\n' ) {
		strings[len-1] = 0;
	}
	/* ****** */
	com = strtok(strings, delim);
	if (strcmp(com,stop) == 0) { //exit
		freeMemory(paths);
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
		newPathF(strings2, paths);
	} else {//komentoa ei tunnistettu
		printf("Command not recognized\n");
	}
}

char* concat(const char *s1, const char *s2) //merkkijonojen yhdistämiseen tarkoitettu funktio
{ //https://stackoverflow.com/questions/8465006/how-do-i-concatenate-two-strings-in-c
	char *result;
    if ((result = malloc(strlen(s1) + strlen(s2) + 1))==NULL) { // +1 for the null-terminator
		printf("Memory allocation failed\n");
		exit(1);
	};
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}

void newPathF(char newPaths[], pathPtr *pFirst) {
	char *newPath, delim2[2] = " ";
	struct path_t *ptr, *pLast;
	
	newPath = strtok(newPaths, delim2);

	
	if ((newPath = strtok(NULL, delim2)) == NULL) { // Polkua ei annettu argumenttina
		printf("Luodaan tyhjä polkulista\n");
		
		if ((*pFirst) != NULL) {
			ptr = (*pFirst);
			while (ptr != NULL) {
				(*pFirst) = ptr->next; // Tyhjennetään olemassa oleva linkitetty lista
				free(ptr);
				ptr = (*pFirst);
			}
		}
		
		if(!(*pFirst)) {
			if (!(*pFirst = (pathPtr)malloc(sizeof(path)))) { // Alustus
				perror("Memory allocation error\n");
				exit(1);
			}
			
			(*pFirst)->dir = NULL;
			(*pFirst)->next = NULL;
		}	
	} else { // Polku annettu
		printf("Luodaan uusi polkulista\n");

		if((*pFirst) != NULL) {
			ptr = (*pFirst);
			while (ptr != NULL) {
				(*pFirst) = ptr->next; // Tyhjennetään olemassa oleva linkitetty lista
				free(ptr);
				ptr = (*pFirst);
			}
		}
		
		if(!(*pFirst)) {
			if (!(*pFirst = (pathPtr)malloc(sizeof(path)))) { // Alustus
				perror("Memory allocation error\n");
				exit(1);
			}
			
			(*pFirst)->dir = NULL;
			(*pFirst)->next = NULL;
		}
		
		(*pFirst)->dir = newPath;
		(*pFirst)->next = NULL;
		
		ptr = (*pFirst);
		pLast = ptr;
				
		while ((newPath = strtok(NULL, delim2)) != NULL) {
			if(!(ptr = (pathPtr)malloc(sizeof(path)))) {
				perror("Memory allocation error");
				exit(1);
			}
		
			ptr->dir = newPath;
			ptr->next = NULL;
			
			pLast->next = ptr;
			pLast = ptr;
		}
				
		ptr = (*pFirst);
		printf("Polut:\n");
		while (ptr != NULL) {
			printf("%s\n", ptr->dir);
			ptr = ptr->next;
		}
		
	}
	
}

void freeMemory(pathPtr *pFirst) {
	struct path_t *ptr;
	
	ptr = (*pFirst);
	while (ptr != NULL) {
		(*pFirst) = ptr->next; // Tyhjennetään olemassa oleva linkitetty lista
		free(ptr);
		ptr = (*pFirst);
	}
}
