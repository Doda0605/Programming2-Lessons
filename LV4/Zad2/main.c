#include <stdio.h>
#include <stdlib.h>

typedef struct artikl{
    char    ime[20];
    float   cijena;
    int     kolicina;
}ARTIKL;


int main(void){
    
    int n, i;
    
    
    do{
        printf("Unesite broj artikala: ");
        scanf("%d", &n);
    }while(n < 1 || n > 50);
    
    
    ARTIKL *pokARTIKL = NULL;
    pokARTIKL = (ARTIKL*)calloc(n, sizeof(ARTIKL));
    
    if(pokARTIKL == NULL){
        return 1;
    }
    
    ARTIKL *pokMAX = NULL;
    

    
    for(i = 0; i < n; i++){
        
        printf("Unesite ime\n");
        scanf("%19s", (pokARTIKL + i) -> ime);
        
        printf("\nUnesite cijenu artikla:\n");
        scanf("%f", &(pokARTIKL + i) -> cijena);
        
        printf("\nUnesite koliko tog artikla zelite kupiti:\n");
        scanf("%d", &(pokARTIKL + i) -> kolicina);
    }
    pokMAX= (pokARTIKL + 0);
    for(i = 0; i < n; i++){
        
        
        if((pokMAX -> cijena) > ((pokARTIKL + i) -> cijena)){
            pokMAX = (pokARTIKL + i);
        }
        
    }
    
    printf("Najskuplji artikl:\nIME: %s CIJENA: %f KOLICINA: %d", pokMAX->ime, pokMAX->cijena, pokMAX->kolicina);
    
    free(pokARTIKL);
    
    return 0;
}