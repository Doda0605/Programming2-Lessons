#ifndef FUNCTIONS_H
#define FUNCTIONS_H

typedef struct student {
	char* ime;
	char* prezime;
	int id;
	struct student* next;
}STUDENT;


void popunjavanje(FILE* p);
STUDENT* createSLList(FILE* p);
void unos(char** pok, FILE* p);
STUDENT* insertNewNodeSLList(STUDENT*, FILE* p);
void printCurrentNode(STUDENT* currentNode);
int traverseSLList(STUDENT* traverseNode);
STUDENT* searchSLList(STUDENT* traverseNode, int criteria);
void deleteNodeSLList(STUDENT** headNode, STUDENT* targetNode);
STUDENT* deleteWholeSLList(STUDENT* traverseNode);

#endif //FUNCTIONS_H