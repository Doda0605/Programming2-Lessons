#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"


int main(void){
    
    srand((unsigned)time(NULL));
    
    int m;
    short int max = 0;

    m = interval(18, 3);
    printf("m: %d\n\n", m);
    
    short int **matrica = NULL;
    matrica = zauzimanjeMatrice(m);
    if(matrica == NULL){
        return 1;
    }
    
    popunjavanjeMatrice(matrica, m, -1550, 250);
    ispisOriginalneMatrice(matrica, m);
    
    max = najveciParniBroj(matrica, m);
    printf("\nMax: %hu", max);
    
    novaMatrica(matrica, m, max);
    printf("\n\n");
    ispisMatrice(matrica, m);
    brisanjeMatrice(matrica, m);
    
    return 0;
}