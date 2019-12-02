/*
 * Käyttöjärjestelmät ja systeemiohjelmointi
 * Harjoitustyö osa 3/6
 * Syksy 2019
 * Rami Saarivuori & Aarne Savolainen
 * my-zip, RLE pakkaustyökalu
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char * argv[]) {
	if (argc == 1) {
		printf("my-zip: file1 [file2] ... \n");
		exit(0);
	};
	
	int n = 0;
	char buff1[2], buff2[2];
	for (int i=1;i<(argc);i++){
		FILE *fp = fopen(argv[i], "r");
		if (fp == NULL) {
			printf("Cannot open file %s\n", argv[i]);
			exit(1);
		};
		
		buff1[0] = getc(fp);
		buff2[0] = buff1[0];
		while (buff1[0] != -1) {
			if (buff2[0] == buff1[0]) {
				n++;
				buff1[0] = getc(fp);
			} else {
				fwrite(&n, sizeof(n), 1, stdout);
				fwrite(&buff2, 1, 1, stdout);
				n = 0;
				buff1[0] = getc(fp);
				buff2[0] = buff1[0];
			}
			if (buff1[0] == -1){
				break;
			};
		}
	fclose(fp);
	}
	printf("\n");
	return (0);
}
