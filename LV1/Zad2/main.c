#include <stdio.h>
#include <math.h>
int main(void){
    
    int broj[8], i, brojac = 0, dek = 0, j = 0, z = 0;
    
    for(i = 0; i <= 7; i++){
        do{    
            scanf("%d", &broj[i]);
        }while(broj[i] != 1 && broj[i] != 0);
    }
    
    if(broj[0] == 1){
        z = 1;
    }
    
    if(broj[0] == 1){
        for(i = 7; i >= 0; i--){
            if(j == 1){
                if(broj[i] == 0){
                    broj[i] = 1;
                }
                else{
                    broj[i] = 0;
                }
            }
            if(j == 0){
                if(broj[i] == 1){
                    j = 1;
                }
            }
        }
    }
    
    for(i = 7; i >= 0; i--){
        dek = dek + (broj[i]* pow(2,brojac));
        brojac++;
    }
    
    if(z == 1){
        dek = dek * (-1);
    }
    
    printf("\n %d", dek);
    
    return 0;
}