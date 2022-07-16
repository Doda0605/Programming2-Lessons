#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

int interval(int GG, int DG){
    
    int m = DG + (float)rand() / RAND_MAX * (GG - DG);
    
    return m;
}

short int** zauzimanjeMatrice(int m){
    
    short int **matrica = NULL;
    matrica = (short int**)calloc(m, sizeof(short int*));
    if(matrica == NULL){
        return NULL;
    }
    
    for (int i = 0; i < m; i++) {
        *(matrica + i) = (short int*)calloc(m, sizeof(short int));
        if(*(matrica + i) == NULL){
            return NULL;
        }
    }
    
    return matrica;
}

void popunjavanjeMatrice(short int **p, int m, int GG, int DG){
    
    for(int i = 0; i < m; i++){
        for(int j =  0; j < m; j++){
            *(*(p + i) + j) = DG + (float)rand()/RAND_MAX*(GG - DG);
        }
    }
}

void ispisOriginalneMatrice(short int **p, int m){
    
    for(int i = 0; i < m; i++){
        for(int j =  0; j < m; j++){
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    
}

short int najveciParniBroj(short int **p, int m){
    
    short int max = -1550;
    
    for(int i = 0; i < m; i++){
        for(int j =  0; j < m; j++){
            if(i + j > m - 1){
                if( ((*(*(p + i) + j)) % 2) == 0){
                    if( (*(*(p + i) + j)) > max){
                        max = *(*(p + i) + j);
                    }
                }
            }
        }
    }
    
    return max;
}

void novaMatrica(short int **p, int m, short int max){
    
    for(int i = 0; i < m; i++){
        for(int j =  0; j < m; j++){
            if(i + j < m - 1){
                *(*(p + i) + j) = max;
            }
        }
    }
    
}

void ispisMatrice(short int **p, int m){
    
    for(int i = 0; i < m; i++){
        for(int j =  0; j < m; j++){
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
    
}

short int** brisanjeMatrice(short int **p, int m){
    
    for (int i = 0; i < m; i++){
        free(*(p + i));
    }
    
    free(p);
    
    return NULL;
}