#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void popunjavanje(FILE* p) {
	int broj = 0;

	for (int i = 0; i < 500; i++) {
		broj = 0 + (float)rand() / RAND_MAX * (1000 - 0);
		fprintf(p, "%d ", broj);
	}
}

int unos(int GG, int DG) {
	int broj = 0;

	do {
		printf("\nUnesite n: ");
		scanf("%d", &broj);
	} while (broj < DG || broj > GG);

	return broj;
}

void citanje(FILE* p, int* polje) {

	int broj = 0, counter = 0;

	while ((fscanf(p, "%d", &broj)) != EOF) {
		polje[counter] = broj;
		counter++;
	}
}

void ispis(int* polje) {
	for (int i = 0; i < 500; i++)
	{
		if (i == 0) {
			printf("\npolje\n[%d ", polje[i]);
		}
		else if (i > 0 && i < 500 - 1) {
			printf("%d ", polje[i]);
		}
		else {
			printf("%d]\n", polje[i]);
		}
	}
}

void selectionSort(int* polje) {

	int i, j, position, swap;


	for (i = 0; i < 500 - 1; i++) {
		position = i;
		for (j = i + 1; j < 500; j++) {
			if (polje[position] > polje[j])
				position = j;
		}
		if (position != i) {
			swap = polje[i];
			polje[i] = polje[position];
			polje[position] = swap;
		}
	}
}

int linearnoPretrazivanje(int* polje, int trazeniBroj) {
	for (int i = 0; i < 500; i++) {
		if (polje[i] == trazeniBroj) {
			return i;
		}
	}
	return -1;
}

int binarnoPretrazivanje(int* polje, int trazeniBroj) {
	int dg = 0;
	int gg = 500 - 1;
	int s = -1;
	while (dg <= gg) {
		s = (dg + gg) / 2;
		if (polje[s] == trazeniBroj) {
			return s;
		}
		else if (polje[s] > trazeniBroj) {
			gg = s - 1;
		}
		else {
			dg = s + 1;
		}
	}
	return -1;
}