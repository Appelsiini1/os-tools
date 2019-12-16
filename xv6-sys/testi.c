/*
 * Käyttöjärjestelmät ja systeemiohjelmointi
 * Harjoitustyö osa 6/6
 * Syksy 2019
 * Rami Saarivuori & Aarne Savolainen
 * testaa getcount systeemikutsun
*/

#include "types.h"
#include "stat.h"
#include "user.h"

int main(void) {
	printf(0, "Read: %d\n", getcount(0,0));
	
	printf(0, "Change to exit: %d\n", getcount(0, 2));
	
	printf(0, "Reset counter: %d\n", getcount(1, 0));
	
	exit();
}
