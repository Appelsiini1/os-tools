/*
 * Käyttöjärjestelmät ja systeemiohjelmointi
 * Harjoitustyö osa 1/?
 * Syksy 2019
 * Rami Saarivuori
*/
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) { 
	if (argc == 1) {
		exit(0);
	};
	FILE *fp;
	char s[50];
	for (int i=0;i<(argc-1);i++) {
		fp = fopen(argv[i+1], "r");

		if (fp == NULL) {
			printf("Cannot open file %s\n", argv[i+1]);
			exit(1);
		};
		while (s != NULL) {
		if (fgets(s, 50, fp) != NULL ) {
			printf("%s", s);
		} else {
			break;
		};
	};
};
	fclose(fp);
	
	return 0;
}
