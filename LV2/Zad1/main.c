#include <stdio.h>

int main(void){
    
    int n, x = 0;
    
    printf("Unesite broj jednog dana u tjednu: ");
    do{
        if(x > 0){
            printf("\nKrivo uneseni broj za dan, ponovno unesite broj:\n");
        }
        scanf("%d", &n);
        x++;
        
    }while(n < 1 || n > 7);
    
    char *dani[] = { "ponedjeljak", "utorak", "srijeda", "cetvrtak", "petak", "subota", "nedjelja" };
    
    printf("\nBroj koji ste unijeli predstavlja dan: %s", *(dani + n - 1));
    
    return 0;
}