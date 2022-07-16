#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void) {

	srand((unsigned)time(NULL));

	int broj[2];
	int status = 0;
	int k = 1;

	FILE* fp = NULL;
	fp = fopen("in.txt", "r");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		citanje(status, fp, broj);

		printf("%d\n", *broj);
		printf("%d\n", *(broj + 1));

		fclose(fp);
	}

	float** matrica = NULL;
	matrica = zauzimanjeMatrice(broj);
	if (matrica == NULL) {
		return 1;
	}

	popunjavanjeMatrice(broj, matrica);

	
	fp = fopen("out.txt", "w");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		ispis(fp, matrica, status, broj);
		fclose(fp);
	}
	
	brisanjeMatrice(fp, broj);
	
	return 0;
}