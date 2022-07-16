#include <stdio.h>
#include <stdlib.h>

typedef struct tocka{
    float x;
    float y;
    float z;
}TOCKA;

int main(void){
    
    TOCKA *pokTOCKA = NULL;
    pokTOCKA = (TOCKA*)calloc(10, sizeof(TOCKA));
    
    if(pokTOCKA == NULL){
        return 1;
    }
    
    for(int i = 0; i < 10; i++){
        printf("Unesite 3 koordinate tocke: ");
        scanf("%f %f %f", &(pokTOCKA + i) -> x, &(pokTOCKA + i) -> y, &(pokTOCKA + i) -> z);
    }
    
    
    
    return 0;
}