#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

int main(void) {

	char string[20];
	
	
	FILE* fp = NULL;
	fp = fopen("string.txt", "w");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
	}
	else {
		printf("Unesite string: ");
		scanf("%s", string);
		printf("\nPrvotni string: %s\n", string);

		
		okrenuti(string, fp);
		
		fclose(fp);
	}
	

	return 0;
}