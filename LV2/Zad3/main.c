#include<stdio.h>
#include<stdlib.h>
#include<time.h>
float** zauzimanje(int);
void popunjavanje(float**, int);
void ispis2D(float**, int);
float** oslobadjanje(float**, int);

int main(void) {
    
    srand((unsigned)time(NULL));
    
    float **polje2D = NULL;
    
    int n;
    
    do{
        scanf("%d", &n);
    }while(n <2 || n > 8);
    
    
    
    polje2D = zauzimanje(n);
    
    if(polje2D == NULL){
        return 1;
        }
    popunjavanje(polje2D, n);
    ispis2D(polje2D, n);
    polje2D = oslobadjanje(polje2D, n);
    return 0;
}


float** zauzimanje(int n) {
    float **polje2D = NULL;
    
    polje2D = (float**)calloc(n, sizeof(int*));
        if(polje2D == NULL){
            return NULL;
        }
    for (int i = 0; i < n; i++) {
        *(polje2D + i) = (float*)calloc(n, sizeof(int));
        if(*(polje2D + i) == NULL){
            return NULL;
        }
    }
    return polje2D;
}

void popunjavanje(float **p, int n) {
    int i, j;

    
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            *(*(p + i) + j) = -1.25 + (float)rand() / RAND_MAX * (5.75 - (-1.25));
        }
    }
}

void ispis2D(float **p, int n) {
    int i, j;
    
    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            printf(" %3d", *(*(p + i) + j));
        }
        printf("\n");
    }
}

float** oslobadjanje(float **p, int n) {
    int i;

    for (i = 0; i < n; i++){
        free(*(p + i));
    }
    free(p);
    return NULL;
}