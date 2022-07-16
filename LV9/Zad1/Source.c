#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void) {

	srand((unsigned)time(NULL));

	int n, polje[500], indeks, GG = 1000, DG = 0;
	
	FILE* fp = NULL;
	fp = fopen("dat.txt", "w");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		popunjavanje(fp);

		fclose(fp);
	}

	n = unos(GG, DG);
	printf("\nn: %d\n", n);

	fp = fopen("dat.txt", "r");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		citanje(fp, polje);

		fclose(fp);
	}

	ispis(polje);
	/*selectionSort(polje);
	ispis(polje);*/

	indeks = linearnoPretrazivanje(polje, n);
	if (indeks == -1) {
		printf("Trazeni broj %d nije pronadjen unutar polja.\n", n);
	}
	else {
		printf("Trazeni broj %d je pronadjen unutar polja nakon %d koraka na indeksu %d.\n", n, indeks, indeks);
	}

	return 0;
}