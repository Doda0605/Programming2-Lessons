#include <stdio.h>
#include <string.h>

int main(void){
    
    int n, x = 0, i, j, najveci = 0, brojac, z = 0;
    
    printf("Unesite broj jednog dana u tjednu: ");
    do{
        if(x > 0){
            printf("\nKrivo uneseni broj za dan, ponovno unesite broj:\n");
        }
        scanf("%d", &n);
        x++;
        
    }while(n < 1 || n > 7);
    
    char *dani[] = { "ponedjeljak", "utorak", "srijeda", "cetvrtak", "petak", "subota", "nedjelja" };
    
    printf("\nBroj koji ste unijeli predstavlja dan: %s\n", *(dani + n - 1));
    
    for(i = 0; i < 7; i++){
        for(j = 0; j < strlen(*(dani + i)); j++){
            brojac = 0;
            if((*(*(dani + i) + j)) != 'a' && (*(*(dani + i) + j)) != 'e' && (*(*(dani + i) + j)) != 'i' && (*(*(dani + i) + j)) != 'o' && (*(*(dani + i) + j)) != 'u'){
                brojac++;
            }
            if(brojac > najveci){
                najveci = brojac;
                z = i;
            }
        }
    }
    
    printf("Dan s najviše suglasnika i obrnutim redoslijedom slova je: ");
    for(i = 0; i < 7; i++){
        if(i == z){
            for(j = strlen(*(dani + i)); j >= 0; j--){
                printf("%c", (*(*(dani + i) + j)));
                }
        }
    }
    
    return 0;
}