#include <stdio.h>

int main(void){
    
    int n, negn, binar[8] = {0}, i, j = 0;
    
    
    do{
        scanf("%d", &n);
    }while(n <= -128 || n >= 127);
    
    if(n < 0){
        negn = n;
        n = n*(-1); 
    }
    
    for(i = 7; n > 0; i--){
        binar[i] = n % 2;
        n = n/2;
    }
    
    if(negn < 0){
        for(i = 7; i >= 0; i--){
            if(j == 1){
                if(binar[i] == 0){
                    binar[i] = 1;
                }
                else{
                    binar[i] = 0;
                }
            }
            if(j == 0){
                if(binar[i] == 1){
                    j = 1;
                }
            }
        }
    }
    
    
    for(i = 0; i < 8; i++){
        printf("%d", binar[i]);
    }        
    
    return 0;
}