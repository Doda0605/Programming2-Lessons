#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int main(void){
    
    srand((unsigned)time(NULL));
    
    int m, n, vel, koordinata, i;
    float opsegT, najveci = 0, najveciops, a, b, c;
    
    m = generiranje(4, 100);
    printf("m: %d", m);
    n = generiranje(3, 16);
    printf("\nn: %d", n);
    
    vel = sizeof(TOCKA);
    TOCKA *pokTOCKA = NULL;
    pokTOCKA = zauzimanje(m, vel);
    if(pokTOCKA == NULL){
        return 1;
    }
    
    vel = sizeof(TROKUT);
    TROKUT *pokTROKUT = NULL;
    pokTROKUT = zauzimanje(n, vel);
    if(pokTROKUT == NULL){
        return 1;
    }
    
    for (int i = 0; i < m; i++){
        (pokTOCKA + i) -> x = generiranje(0, 100);
        (pokTOCKA + i) -> y = generiranje(0, 100);
    }
    
    for (i = 0; i < n; i++){
        (pokTROKUT + i) -> v1 = &(pokTOCKA[generiranje(0, m-1)]);
        (pokTROKUT + i) -> v2 = &(pokTOCKA[generiranje(0, m-1)]);
        (pokTROKUT + i) -> v3 = &(pokTOCKA[generiranje(0, m-1)]);
    }
    
    for(i = 0; i < n; i++){
    
        a = duljina(((pokTROKUT + i) -> v1), ((pokTROKUT + i) -> v2));
        b = duljina(((pokTROKUT + i) -> v2), ((pokTROKUT + i) -> v3));
        c = duljina(((pokTROKUT + i) -> v3), ((pokTROKUT + i) -> v1));
        
        opsegT = opseg( a, b ,c);
        
        if(opsegT > najveci){
            najveci = opsegT;
            koordinata = i;
            najveciops = opsegT;
        }
        
    }
    
    printf("\nTrokut s najvećim opsegom je trokut broj %d koji ima opseg %.2f s koordinatama \nT1: %d %d \nT2: %d %d \nT3: %d %d\n", i, najveciops, pokTROKUT[koordinata].v1 -> x, pokTROKUT[koordinata].v1 -> y, pokTROKUT[koordinata].v2 -> x, pokTROKUT[koordinata].v2 -> y,  pokTROKUT[koordinata].v3 -> x, pokTROKUT[koordinata].v3 -> y);
    
    free(pokTOCKA);
    free(pokTROKUT);
    
    return 0;
}