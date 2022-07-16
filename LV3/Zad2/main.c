#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct cijeli_broj{
    long   uneseni_broj;
    int   broj_znamenaka;
}CIJELI_BROJ;

long generiranje(void);
int znamenke(long a);

int main(void){
    
    CIJELI_BROJ polje[40];
    
    srand((unsigned)time(NULL));
    
    int i, najveci = 0, najveci1 = 0, najmanji = 10, najmanji1 = 0;
    
    for (int i = 0; i < 40; i++){

        polje[i].uneseni_broj = generiranje();
    
        polje[i].broj_znamenaka = znamenke(polje[i].uneseni_broj);
        
        if(polje[i].broj_znamenaka > najveci){
            najveci = polje[i].broj_znamenaka;
            najveci1 = i;
        }
        if(polje[i].broj_znamenaka < najmanji){
            najmanji = polje[i].broj_znamenaka;
            najmanji1 = i;
        }
        
    }
    
    printf("\nPolje s najviše znamenaka:\n%ld", polje[najveci1].uneseni_broj);
    printf("\nBroj znamenaka toga polja:\n%ld", polje[najveci1].broj_znamenaka);
    printf("\nPolje s najmanje znamenka:\n%ld", polje[najmanji1].uneseni_broj);
    printf("\nBroj znamenaka toga polja:\n%ld", polje[najmanji1].broj_znamenaka);
    return 0;
}

long generiranje(){
    
    
    long z;
    
    
    z = -2147483648 + (rand() %(2145483648 - (-2147483648) + 1));
    
    
    return z;
}

int znamenke(long broj){

    int br = 0, a = broj;
    

    do {
        a /= 10;
        br++;
    } while (a != 0);

    return br;
}
