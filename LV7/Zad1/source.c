#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include "header.h"

int main(void) {

	int broj = 0;
	int status = 0;
	
	FILE* fp = NULL;
	fp = fopen("dat.txt", "r");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		broj = citanje(status, fp);

		fclose(fp);
	}

	fp = fopen("studenti.txt", "w");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		studenti(fp, broj, status);
		fclose(fp);
	}
		
	return 0;
}