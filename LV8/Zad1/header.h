#ifndef HEADER_H
#define HEADER_H

#include "datatype.h"

int izbornik(const char* const);
void dodajKupca(const char* const imeDatoteke);
void* ucitavanjeKupaca(const char* const imeDatoteke);
void ispisivanjeKupaca(const CLAN* const poljeKupaca);
void* pretrazivanjeKupaca(CLAN* const poljeKupaca);
int izlazIzPrograma(CLAN* poljeKupaca);


#endif //HEADER_H