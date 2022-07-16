#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"

int main(void) {

	srand((unsigned)time(NULL));
	
	int n, najelement;

	
	do {
		printf("\nUnesite n: ");
		scanf("%d", &n);
	} while (n <= 0 || n > 20);
	
	
	int* polje = NULL;
	polje = (int*)calloc(n, sizeof(int));
	if (polje == NULL) {
		return NULL;
	}

	
	popunjavanje(polje, n);
	najelement = najvecielem(polje, n);
	
	printf("\n%d", najelement);
	
	FILE* fp = NULL;
	fp = fopen("najveci.txt", "w");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		fprintf(fp, "%d", najelement);

		fclose(fp);
	}
	

	return 0;
}