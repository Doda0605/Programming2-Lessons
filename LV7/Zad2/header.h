#ifndef HEADER_H
#define HEADER_H
void citanje(int status, FILE* p, int* broj);
float ** zauzimanjeMatrice(broj);
void popunjavanjeMatrice(int* broj, float** matrica);
void ispis(FILE* p, float** matrica, int status, int* broj);
float** brisanjeMatrice(float** p, int* broj);

#endif //HEADER_H