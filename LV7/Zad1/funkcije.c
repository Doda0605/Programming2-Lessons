#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include "header.h"

int citanje(int status, FILE* p) {
	int broj = 0;

	while ((status = fscanf(p, "%d", &broj)) != EOF) {
		printf("Status je %d.\n", status);
		printf("%d\n", broj);
	}
	printf("Status je %d.\n", status);

	

	return broj;
}

void studenti(FILE* p, int broj, int status) {
	char ime[20] = { '\0' };
	char prezime[30] = { '\0' };
	for (int i = 0; i < broj; i++)
	{
		printf("Unesite ime za %d. studenta\n", i + 1);
		scanf("%19s", ime);
		printf("Unesite prezime za %d. studenta\n", i + 1);
		scanf("%29s", prezime);
		status = fprintf(p, "Student br: %d\tIme: %s Prezime: %s\n", i + 1, ime, prezime);
		printf("Status je %d.\n", status);
	}
}