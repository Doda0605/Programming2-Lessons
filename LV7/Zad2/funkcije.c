#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

void citanje(int status, FILE* p, int* broj) {
	
	fscanf(p, "%d%d", broj, broj + 1);

}

float** zauzimanjeMatrice(int* broj) {

	float** matrica = NULL;
	matrica = (float**)calloc(*(broj), sizeof(float*));
	if (matrica == NULL) {
		return NULL;
	}

	for (int i = 0; i < *(broj); i++) {
		*(matrica + i) = (float*)calloc(*(broj + 1), sizeof(float));
		if (*(matrica + i) == NULL) {
			return NULL;
		}
	}

	return matrica;
}

void popunjavanjeMatrice(int* broj, float** matrica) {

	for (int i = 0; i < *(broj); i++) {
		for (int j = 0; j < *(broj + 1); j++) {
			matrica[i][j] = -125.5 + (float)rand() / RAND_MAX * (65.8 + 125.5);
		}
	}
}


void ispis(FILE* p, float** matrica, int status, int* broj) {

	for (int i = 0; i < *broj; i++) {
		for (int j = 0; j < *(broj + 1); j++) {
			if (i != 0) {
				if (j != (*(broj + 1) - 1)) {
					printf("%f ", matrica[i][j]);
					fprintf(p, "%f ", matrica[i][j]);
				}
			}
			
		}
		printf("\n");
		fprintf(p, "\n");
	}



}

float** brisanjeMatrice(float** p, int* broj) {

	for (int i = 0; i < *broj; i++) {
		free(*(p + i));
	}

	free(p);

	return NULL;
}