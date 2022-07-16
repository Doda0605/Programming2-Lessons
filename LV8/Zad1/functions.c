#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "datatype.h"
#include "header.h"

static int brojKupaca = 0;

void kreiranjeDatoteke(const char* const imeDatoteke) {
	FILE* pF = fopen(imeDatoteke, "wb");
	if (pF == NULL) {
		perror("Kreiranje datoteke clanovi.bin");
		exit(EXIT_FAILURE);
	}
	fwrite(&brojKupaca, sizeof(int), 1, pF);
	fclose(pF);
}


int izbornik(const char* const imeDatoteke) {
	printf("====================");
	printf("Odaberite jednu od ponudenih opcija:");
	printf("====================\n");
	printf("\t\t\t1. Dodavanje novih članova u datoteku clanovi.bin.\n");
	printf("\t\t\t2. Čitanje članova iz datoteke clanovi.bin.\n");
	printf("\t\t\t3. Ispisivanje podataka o svim korisnicima\n");
	printf("\t\t\t4. Pretraži korisnika po ID-u i njegovo ispisivanje\n");
	printf("\t\t\t5. Završetak programa. \n");
	printf("======================================\
	======================================\n");
	int uvijet = 0;
	static CLAN* poljeKupaca = NULL;
	static CLAN* pronadeniKupac = NULL;
	
	scanf("%d", &uvijet);
	switch (uvijet) {
	case 1:
		dodajKupca(imeDatoteke);
		break;
	case 2:
		if (poljeKupaca != NULL) {
			free(poljeKupaca);
			poljeKupaca = NULL;
		}
		poljeKupaca = (CLAN*)ucitavanjeKupaca(imeDatoteke);
		if (poljeKupaca == NULL) {
			exit(EXIT_FAILURE);
		}
		break;
	
	case 3:
		ispisivanjeKupaca(poljeKupaca);
		break;
	case 4:
		pronadeniKupac = (CLAN*)pretrazivanjeKupaca(poljeKupaca);
		break;
	case 5:
		uvijet = izlazIzPrograma(poljeKupaca);
		break;
	default:
		uvijet = 0;
	}
	return uvijet;
}