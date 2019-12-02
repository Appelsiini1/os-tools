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
char concat(const char *, const char *);

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
			if (a==0) {
			} else {
				parser(buff);
			};
		};
	};
};

void parser(char *strings[]) {
	char *com, delim[2] = " ", char stop[5] = "exit", char change[3] = "cd", char polku[5] = "path";
	com = strtok(strings, delim);
	if (com == stop) {
		exit(0);
	};
	if (com == change) {
		
	};
	if (com == polku) {
		
	} else {
		printf("Command not recognized");
	}
}

char* concat(const char *s1, const char *s2)
{
    if (char *result = malloc(strlen(s1) + strlen(s2) + 1)==NULL) { // +1 for the null-terminator
		printf("Memory allocation failed");
		exit(1);
	};
    strcpy(result, s1);
    strcat(result, s2);
    return result;
}
