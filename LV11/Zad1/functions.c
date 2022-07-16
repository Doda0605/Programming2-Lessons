#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

STUDENT* createSLList(FILE* p) {
	
	STUDENT* headNode = (STUDENT*)calloc(1, sizeof(STUDENT));
	if (headNode == NULL) {
		perror("Kreiranje");
		return NULL;
	}
	else {
		fscanf(p, "%d", &headNode->id);
		

		headNode->next = NULL;

		unos(&headNode->ime, p);
		if (headNode->ime == NULL) {
			exit(-1);
		}
		unos(&headNode->prezime, p);
		if (headNode->prezime == NULL) {
			exit(-1);
		}
	}
	return headNode;
}

void unos(char** pok, FILE* p) {
	char pomocnoPolje[50] = { 0 };
	int duljina = 0;
	fscanf(p, "%49s", pomocnoPolje);
	duljina = strlen(pomocnoPolje);
	*pok = (char*)calloc(duljina + 1, sizeof(char));
	if (*pok == NULL) {
		return;
	}
	strcpy(*pok, pomocnoPolje);
}

STUDENT* insertNewNodeSLList(STUDENT* headNode, FILE* p) {

	STUDENT* newHeadNode = (STUDENT*)calloc(1, sizeof(STUDENT));
	if (newHeadNode == NULL) {
		perror("Kreiranje");
		return headNode;
	}
	else {
		fscanf(p, "%d", &newHeadNode->id);
		newHeadNode->next = headNode;
		unos(&newHeadNode->ime, p);
		if (newHeadNode->ime == NULL) {
			exit(-1);
		}
		unos(&newHeadNode->prezime, p);
		if (newHeadNode->prezime == NULL) {
			exit(-1);
		}
		return newHeadNode;
	}
}

void printCurrentNode(STUDENT* currentNode) {
	printf("Vrijednost %3d\t%p\n", currentNode->id, &currentNode->id);
}

int traverseSLList(STUDENT* traverseNode) {
	int counter = 0;
	if (traverseNode == NULL) {
		exit(-1);
	}
	else {
		while (traverseNode) {
			counter++;
			printf("Chvor br. %d ima vrijednost %3d\t%p IME: %s PREZIME: %s\n", counter, traverseNode->id, &traverseNode->id, traverseNode->ime, traverseNode->prezime);
			traverseNode = traverseNode->next;
		}
	}
	return counter;
}

STUDENT* searchSLList(STUDENT* traverseNode, int criteria) {
	while (traverseNode) {
		if (traverseNode->id == criteria) {
			return traverseNode;
		}
		else {
			traverseNode = traverseNode->next;
		}
	}
	return NULL;
}

void deleteNodeSLList(STUDENT** headNode, STUDENT* targetNode) {
	if (*headNode == targetNode) {
		*headNode = (*headNode)->next;
		free(targetNode->ime);
		free(targetNode->prezime);
		free(targetNode);
		printf("Oslobodjen chvor: %p\n", targetNode);
	}
	else {
		STUDENT* traverseNode = *headNode;
		while (traverseNode->next) {
			if (traverseNode->next == targetNode) {
				traverseNode->next = targetNode->next;
				free(targetNode->ime);
				free(targetNode->prezime);
				free(targetNode);
				printf("Oslobodjen chvor: %p\n", targetNode);
				break;
			}
			traverseNode = traverseNode->next;
		}
	}
}

STUDENT* deleteWholeSLList(STUDENT* traverseNode) {
	STUDENT* deleteNode = NULL;
	while (traverseNode) {
		deleteNode = traverseNode;
		traverseNode = traverseNode->next;
		free(deleteNode->ime);
		free(deleteNode->prezime);
		free(deleteNode);
		printf("Oslobodjen chvor: %p\n", deleteNode);
	}
	return NULL;
}