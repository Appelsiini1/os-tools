/*
 * Käyttöjärjestelmät ja systeemiohjelmointi
 * Harjoitustyö osa 1/?
 * Syksy 2019
 * Rami Saarivuori
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {
	if (argc == 1) {
		printf("my-grep: searchterm [file ...]\n");
		exit(0);
	};
	char buffer[150], *cp;
	if (argc == 2) {
		fgets(buffer, 150, stdin);
		cp = strstr(buffer, argv[1]);
		if (cp == NULL) {
			exit(0);
		} else {
			printf("%s", buffer);
			exit(0);
	};};

	FILE *fp;
	char* buff = NULL;
	size_t n;
	ssize_t a;
	for (int i=2;i<argc;i++) {
		fp = fopen(argv[i], "r");
		if (fp == NULL) {
			printf("my-grep: cannot find file %s", argv[i]);
		};
		a = getline(&buff, &n, fp);
		while (a >= 0) {
			cp = strstr(buff, argv[1]);
			if (cp != NULL) {
				printf("%s", buff);
			};
			a = getline(&buff, &n, fp);
		};};
		fclose(fp);
		return 0;
	}
