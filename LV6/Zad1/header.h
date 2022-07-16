#ifndef HEADER_H
#define HEADER_h
    typedef struct tocka{
        int x;
        int y;
    }TOCKA;
    
    typedef struct trokut{
        TOCKA *v1;
        TOCKA *v2;
        TOCKA *v3;
    }TROKUT;
    
    int generiranje(int DG, int GG);
    void* zauzimanje(int broj, int velSizeof);
    float duljina(const TOCKA* const T1, const TOCKA* const T2);
    float opseg(float a, float b, float c);
    
#endif //HEADER_H