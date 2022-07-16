#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "header.h"

int generiranje(int DG, int GG){
    int rez;
    
    rez = DG + (float)rand() / RAND_MAX * (GG - DG);
    
    return rez;
}

void* zauzimanje(int broj, int vel){
    
    
     return calloc(broj, vel);
    
    
}


void unosArtikla(ARTIKL* const t1, const int m){   
        
        int i;
        
        for(i = 0; i < m; i++){
        
            printf("Unesite ime\n");
            scanf("%19s", (t1 + i) -> ime);
        
            printf("\nUnesite cijenu artikla:\n");
            scanf("%f", &(t1 + i) -> cijena);
        
            printf("\nUnesite koliko tog artikla zelite kupiti:\n");
            scanf("%d", &(t1 + i) -> kolicina);
        }
}

ARTIKL* pretragaArtikla(ARTIKL* const t1, const int m){
    
    int i;
    ARTIKL *pokMAXX = NULL;
    pokMAXX= (t1 + 0);
    for(i = 0; i < m; i++){
        
        
        if((pokMAXX -> cijena) < ((t1 + i) -> cijena)){
            pokMAXX = (t1 + i);
        }
    }
    
    return pokMAXX;
}

void ispisArtikla(ARTIKL* const t1){
    
    printf("Najskuplji artikl:\nIME: %s CIJENA: %f KOLICINA: %d", t1->ime, t1->cijena, t1->kolicina);
    
}