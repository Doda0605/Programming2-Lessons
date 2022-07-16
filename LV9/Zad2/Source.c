#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void) {

	srand((unsigned)time(NULL));

	int n[5], polje[500], indeks, GG = 1000, DG = 1, sv1 = 0, sv2 = 0, brojac1 = 0, brojac2 = 0;
	float rjes1 = 0, rjes2 = 0;

	FILE* fp = NULL;
	fp = fopen("dat.txt", "w");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		popunjavanje(fp);

		fclose(fp);
	}


	for (int i = 0; i < 5; i++) {
		n[i] = unos(GG, DG);
	}
	printf("\nn1: %d\tn2: %d\tn3: %d\tn4: %d\tn5: %d\t", n[0], n[1], n[2], n[3], n[4]);

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

	printf("\nREZULTATI:\nSekvencijalno:\n");
	
	for (int i = 0; i < 5; i++) {
		indeks = linearnoPretrazivanje(polje, n[i]);
		if (indeks == -1) {
			printf("5. Trazeni broj %d nije pronadjen unutar polja.\n", n[i]);
		}
		else {
			printf("5. Trazeni broj %d je pronadjen unutar polja nakon %d koraka.\n", n[i], indeks + 1);
			sv1 =+ indeks + 1;
			brojac1++;
		}
	}
	

	selectionSort(polje);
	
	printf("\nBinarno:\n");
	for (int i = 0; i < 5; i++) {
		indeks = binarnoPretrazivanje(polje, n[i]);
		if (indeks == -1) {
			printf("%d. Trazeni broj %d nije pronadjen unutar polja.\n", i + 1, n[i]);
		}
		else {
			printf("%d. Trazeni broj %d je pronadjen unutar polja nakon %d koraka.\n", i + 1, n[i], indeks + 1);
			sv2 =+ indeks + 1;
			brojac2++;
		}
	}

	rjes1 = sv1 / brojac1;
	rjes2 = sv2 / brojac2;

	printf("\nSrednji broj koraka za sekvencijalno pretrazivanje je: %f", rjes1);
	printf("\nSrednji broj koraka za binarno pretrazivanje je : %f", rjes2);



	
	return 0;
}