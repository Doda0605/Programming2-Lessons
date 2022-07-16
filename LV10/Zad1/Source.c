#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "header.h"

int main(void) {

	int n, zbroj;

	
	printf("\nUnesite n: ");
	scanf("%d", &n);
	
	zbroj = suma(n);

	FILE* fp = NULL;
	fp = fopen("suma.txt", "w");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		fprintf(fp, "%d", zbroj);

		fclose(fp);
	}

	printf("\nsuma: %d", zbroj);

	return 0;
}