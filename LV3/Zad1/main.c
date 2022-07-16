#include <stdio.h>
#include <math.h>

typedef struct kompleksni{
    float   re;
    float   im;
}KOMPLEKSNI;

int main(void){
    
    KOMPLEKSNI br1;
    KOMPLEKSNI br2;
    KOMPLEKSNI rez;
    
    float Modul1, Modul2;
    
    
    printf("Unesite re dio prvog kompleksnog broja: ");
    scanf("%f", &br1.re);
    
    printf("Unesite im dio prvog kompleksnog broja: ");
    scanf("%f", &br1.im);
    
    printf("Unesite re dio drugog kompleksnog broja: ");
    scanf("%f", &br2.re);
    
    printf("Unesite im dio drugog kompleksnog broja: ");
    scanf("%f", &br2.im);
    
    
    printf("\nOpci oblik kompleksnog broja 1: %f + (%f)i", br1.re, br1.im);
    printf("\nOpci oblik kompleksnog broja 2: %f + (%f)i", br2.re, br2.im);
    
    rez.re = (br1.re + br2.re);
    rez.im = (br1.im + br2.im);
    
    if(rez.im < 0){
        printf("\nZbroj: %f - %fi", rez.re, rez.im*(-1));
    }else{
        printf("\nZbroj: %f + %fi", rez.re, rez.im);
    }
    
    
    rez.re = (br1.re - br2.re);
    rez.im = (br1.im - br2.im);
    
    if(rez.im < 0){
        printf("\nRazlika: %f + %fi", rez.re, rez.im*(-1));
    }else{
        printf("\nRazlika: %f - %fi", rez.re, rez.im);
    }
    
    
    rez.re = (br1.re * br2.re - br1.im * br2.im);
    rez.im = (br1.re * br2.im + br1.im * br2.re);
    
    if(rez.im < 0){
        printf("\nRezultat mnozenja: %f - %fi", rez.re, rez.im*(-1));
    }else{
        printf("\nRezultat mnozenja: %f + %fi", rez.re, rez.im);
    }
    
    
    if((pow(br2.re, 2) + pow(br2.im, 2)) != 0){
        rez.re = (br1.re * br2.re + br1.im * br2.im) / (pow(br2.re, 2) + pow(br2.im, 2));;
        rez.im = (br1.im * br2.re - br1.re * br2.im) / (pow(br2.re, 2) + pow(br2.im, 2));;
    
        if(rez.im < 0){
            printf("\nRezultat djeljenja: %f - %fi", rez.re, rez.im*(-1));
        }else{
            printf("\nRezultat djeljenja: %f + %fi", rez.re, rez.im);
        }
    }else{
        printf("Ne može se podijeliti.");
    }
    
    Modul1 = sqrt(pow(br1.re, 2) + pow(br1.im, 2));
    printf("\nModul prvog kompleksnog broja: %f", Modul1);
    
    Modul2 = sqrt(pow(br2.re, 2) + pow(br2.im, 2));
    printf("\nModul drugog kompleksnog broja: %f", Modul2);
    
    
    
    return 0;
}

