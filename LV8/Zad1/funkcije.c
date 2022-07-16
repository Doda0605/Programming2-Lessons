#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datatype.h"
#include "header.h"


static int brojKupaca = 0;

void dodajKupca(const char* const imeDatoteke) {
	FILE* pF = fopen(imeDatoteke, "rb+");
	if (pF == NULL) {
		perror("Dodavanje clanova u datoteke clanovi.bin");
		exit(EXIT_FAILURE);
	}
	fread(&brojKupaca, sizeof(int), 1, pF);
	printf("brojKupaca: %d\n", brojKupaca);
	CLAN temp = { 0 };
	temp.id = brojKupaca;
	
	printf("Unesite ime clana!\n");
	getchar();
	scanf("%19[^\n]", temp.ime);
	printf("Unesite prezime clana!\n");
	getchar();
	scanf("%19[^\n]", temp.prezime);
	printf("Unesite adresu clana!\n");
	getchar();
	scanf("%29[^\n]", temp.adresa);
	printf("Unesite broj mobitela clana!\n");
	getchar();
	scanf("%d", &temp.brojmob);
	printf("Unesite broj filmova!\n");
	getchar();
	scanf("%d", &temp.brojfilm);
	fseek(pF, sizeof(CLAN) * brojKupaca, SEEK_CUR);
	fwrite(&temp, sizeof(CLAN), 1, pF);
	rewind(pF);
	brojKupaca++;
	fwrite(&brojKupaca, sizeof(int), 1, pF);
	fclose(pF);
}

void* ucitavanjeKupaca(const char* const imeDatoteke) {
	FILE* pF = fopen(imeDatoteke, "rb");
	if (pF == NULL) {
		perror("Ucitavanje studenata iz datoteke studenti.bin");
		return NULL;
		//exit(EXIT_FAILURE);
	}
	fread(&brojKupaca, sizeof(int), 1, pF);
	printf("brojStudenata: %d\n", brojKupaca);
	CLAN* poljeKupaca = (CLAN*)calloc(brojKupaca, sizeof(CLAN));
	if (poljeKupaca == NULL) {
		perror("Zauzimanje memorije za studente");
		return NULL;
		//exit(EXIT_FAILURE);
	}
	fread(poljeKupaca, sizeof(CLAN), brojKupaca, pF);
	return poljeKupaca;
}

void ispisivanjeKupaca(const CLAN* const poljeKupaca) {
	if (poljeKupaca == NULL) {
		printf("Polje clanova je prazno!\n");
		return;
	}
	int i;
	for (i = 0; i < brojKupaca; i++)
	{
		printf("Clan broj %d\tID: %d\time: %s\tprezime: %s\tadresa %s\tbroj mobitela %d\tbroj filmova %d\n",
			i + 1,
			(poljeKupaca + i)->id,
			(poljeKupaca + i)->ime,
			(poljeKupaca + i)->prezime,
			(poljeKupaca + i)->adresa,
			(poljeKupaca + i)->brojmob,
			(poljeKupaca + i)->brojfilm);
	}
}

void* pretrazivanjeKupaca(CLAN* const poljeKupaca) {
	if (poljeKupaca == NULL) {
		printf("Polje clanova je prazno!\n");
		return NULL;
	}
	int i;
	char trazenoIme[20] = { '\0' };
	printf("Unesite trazeni kriterij za pronalazak clana.\n");
	getchar();
	scanf("%19[^\n]", trazenoIme);
	for (i = 0; i < brojKupaca; i++)
	{
		if (!strcmp(trazenoIme, (poljeKupaca + i)->ime)) {
			printf("Clan je pronaden!\n");
			return (poljeKupaca + i);
		}
	}
	return NULL;
}

int izlazIzPrograma(CLAN* poljeKupaca) {
	free(poljeKupaca);
	return 0;
}