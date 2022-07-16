#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"

int main(void) {
	int uvijet = 1;
	char imeDatoteke[20] = { '\0' };
	
	printf("Unesite ime datoteke s kojom se treba raditi!\n");
	scanf("%19[^\n]", imeDatoteke);
	FILE* pF = fopen(imeDatoteke, "rb");
	if (pF == NULL) {
		perror("Datoteka ne postoji. Kreiranje datoteke clanovi.bin");
		kreiranjeDatoteke(imeDatoteke);
	}
	else {
		fclose(pF);
	}
	while (uvijet) {
		uvijet = izbornik(imeDatoteke);
	}
	printf("Zavrsetak programa!\n");
	
	return 0;
}