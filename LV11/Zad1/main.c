#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "functions.h"


int main(void) {

	int trazeni;

	FILE* fp = NULL;
	fp = fopen("studenti.txt", "r");
	if (fp == NULL) {
		printf("Datoteka se ne moze otvoriti.\n");
		exit(-1);
	}
	
	STUDENT* headNode = createSLList(fp);
	if (headNode == NULL) {
		return 1;
	}





	for (int i = 0; i < 4; i++) {
		headNode = insertNewNodeSLList(headNode, fp);
	}

	fclose(fp);
	
	
	printCurrentNode(headNode);
	printf("Broj elemenata u jednostrukom povezanom popisu: %d\n", traverseSLList(headNode));

	printf("\nUnesite ID koji zelite izbrisati: ");
	scanf("%d", &trazeni);
	printf("\n");
	STUDENT* targetNode = searchSLList(headNode, trazeni);
	if (targetNode == NULL) {
		return 1;
	}

	deleteNodeSLList(&headNode, targetNode);
	printf("\n");
	printf("Broj elemenata u jednostrukom povezanom popisu: %d\n", traverseSLList(headNode));
	printf("\n");
	headNode = deleteWholeSLList(headNode);
	
	
	return 0;
}