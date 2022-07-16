#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void){
    
    srand((unsigned)time(NULL));
    int m, vel, i;
    
    m = generiranje(0, 60);
    printf("m: %d", m);
    
    vel = sizeof(ARTIKL);
    ARTIKL *pokARTIKL = NULL;
    pokARTIKL = zauzimanje(m, vel);
    if(pokARTIKL == NULL){
        return 1;
    }
    
    printf("\n");
    unosArtikla(pokARTIKL, m);
    
     ARTIKL *pokMAX = NULL;
     pokMAX = pretragaArtikla(pokARTIKL, m);
     
     ispisArtikla(pokMAX);
     
     free(pokARTIKL);
    
    return 0;
}