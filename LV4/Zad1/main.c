#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int odabirIndeksa(int);
float opseg(float broj1, float broj2, float broj3);
float duljina(float broj11, float broj22, float broj33, float broj44);


typedef struct tocka{
    float x;
    float y;
}TOCKA;

typedef struct trokut{
    TOCKA *v1;
    TOCKA *v2;
    TOCKA *v3;
}TROKUT;


int main()
{
    
    int i, koordinata, m, n;
    float a, b , c, najveci = 0, opsegT, najveciops;
    
    do{
        printf("Unesite m: ");
        scanf("%d", &m);
    }while(m < 3 || m > 30);
    
    
    do{
        printf("Unesite n: ");
        scanf("%d", &n);
    }while(m < 1 || m > 11);
    
    
    TOCKA *pokTOCKA = NULL;
    pokTOCKA = (TOCKA*)calloc(m, sizeof(TOCKA));
    
    if(pokTOCKA == NULL){
        return 1;
    }
    
    TROKUT *pokTROKUT = NULL;
    pokTROKUT = (TROKUT*)calloc(n, sizeof(TROKUT));
    
    if(pokTROKUT == NULL){
        return 1;
    }

    
    for (int i = 0; i < m; i++){
        printf("Unesite koordinate x, y za tocku %d\n", i + 1);
        scanf("%f%f", &(pokTOCKA + i) -> x, &(pokTOCKA + i) -> y);
    }
    
    
    for (int i = 0; i < n; i++){
        (pokTROKUT + i) -> v1 = &(pokTOCKA[odabirIndeksa(i)]);
        (pokTROKUT + i) -> v2 = &(pokTOCKA[odabirIndeksa(i)]);
        (pokTROKUT + i) -> v3 = &(pokTOCKA[odabirIndeksa(i)]);

    }
    
    for(i = 0; i < n; i++){
    
        a = duljina(pokTROKUT[i].v1 -> x, pokTROKUT[i].v1 -> y, pokTROKUT[i].v2 -> x, pokTROKUT[i].v2 -> y);
        b = duljina(pokTROKUT[i].v2 -> x, pokTROKUT[i].v2 -> y, pokTROKUT[i].v3 -> x, pokTROKUT[i].v3 -> y);
        c = duljina(pokTROKUT[i].v3 -> x, pokTROKUT[i].v3 -> y, pokTROKUT[i].v1 -> x, pokTROKUT[i].v1 -> y);
        
        opsegT = opseg( a, b ,c);
        
        if(opsegT > najveci){
            najveci = opsegT;
            koordinata = i;
            najveciops = opsegT;
        }
        
    }

    printf("\nTrokut s najvećim opsegom je trokut broj %d koji ima opseg %.2f s koordinatama \nT1: %f %f \nT2: %f %f \nT3: %f %f\n", i, najveciops, pokTROKUT[koordinata].v1 -> x, pokTROKUT[koordinata].v1 -> y, pokTROKUT[koordinata].v2 -> x, pokTROKUT[koordinata].v2 -> y,  pokTROKUT[koordinata].v3 -> x, pokTROKUT[koordinata].v3 -> y);
    
    free(pokTOCKA);
    free(pokTROKUT);

    return 0;
}

int odabirIndeksa(int i) {
    
    int indeks;
    
    do {
        printf("\nOdaberite koordinate od 1 do 9 za vrh trokuta %d\n", (i + 1));
        scanf("%d", &indeks);
        
        if (indeks < 1 || indeks > 9) {
            printf("Odabrali ste krivu koordinatu, pokusajte ponovno\n");
        }
    } 
    
    while (indeks < 1 || indeks > 9);
    
    return indeks - 1;
}


float duljina(float broj11, float broj22, float broj33, float broj44){
    
    int opsegtrok;
    
    opsegtrok = sqrt((pow((broj22 - broj11), 2)) + pow((broj44 - broj33), 2));
    
    return opsegtrok;
    
}


float opseg(float a, float b, float c){
    
    int z;
    
    z = a + b + c;
    
    return z;
}