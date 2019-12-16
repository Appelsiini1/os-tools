/*
 * Käyttöjärjestelmät ja systeemiohjelmointi
 * Harjoitustyö osa 4/6
 * Syksy 2019
 * Rami Saarivuori & Aarne Savolainen
 * my-unzip, RLE purkutyökalu
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	if (argc == 1) { /* Jos ei argumentteja, tulostaa ohjelman käytön */
		printf("my-unzip: file1 [file2] ... \n");
		exit(0);
	};
	
	char buff2[1];
	int buff1;
	for (int i=1;i<argc;i++) { /* Käy tiedostot läpi */
		FILE *fp = fopen(argv[i], "r");
		
		if (fp == NULL) {
			printf("Cannot open file %s\n", argv[i]);
			exit(1);
		};
		int b;
		
		fread(&buff1, sizeof(int), 1, fp); /* Lukee numeron tiedostosta */
		b = fread(buff2, 1, 1, fp); /* Lukee kirjaimen tiedostosta */
		while (b != 0) {
			
			for (int a=0;a<=buff1;a++) { /* Kirjoittaa kirjaimen luvun osoittaman määrän verran */
				printf("%c", buff2[0]);
			}
			fread(&buff1, sizeof(int), 1, fp);
			b = fread(&buff2, 1, 1, fp);
		}
		fclose(fp);
	}
	printf("\n");
	return 0;
}
