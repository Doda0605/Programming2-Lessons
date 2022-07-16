#ifndef HEADER_H
#define HEADER_H

void popunjavanje(FILE* p);
int unos(int GG, int DG);
void citanje(FILE* p, int* polje);
void ispis(int* polje);
void selectionSort(int* polje);
int linearnoPretrazivanje(int* polje, int trazeniBroj);
int binarnoPretrazivanje(int* polje, int trazeniBroj);


#endif //HEADER_H