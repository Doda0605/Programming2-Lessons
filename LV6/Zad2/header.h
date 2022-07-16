#ifndef HEADER_H
#define HEADER_H
    typedef struct artikl{
        char    ime[20];
        float   cijena;
        int     kolicina;
    }ARTIKL;
    
    int generiranje(int DG, int GG);
    void* zauzimanje(int broj, int velSizeof);
    void unosArtikla(ARTIKL* const t1, const int m);
    ARTIKL* pretragaArtikla(ARTIKL* const t1, const int m);
    void ispisArtikla(ARTIKL* const t1);

#endif //HEADER_H