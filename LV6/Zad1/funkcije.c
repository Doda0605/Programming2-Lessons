#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "header.h"

int generiranje(int DG, int GG){
    int rez;
    
    rez = DG + (float)rand() / RAND_MAX * (GG - DG);
    
    return rez;
}

void* zauzimanje(int broj, int vel){
    
    
     return calloc(broj, vel);
    
    
}

float duljina(const TOCKA* const T1, const TOCKA* const T2){
    
    float opsegtrok;
    
    opsegtrok = sqrt( ( (pow((T2->x) - (T1->x), 2)) + (pow((T2->y) - (T1->y), 2)) ) );
    
    return opsegtrok;
}

float opseg(float a, float b, float c){
    
    int z;
    
    z = a + b + c;
    
    return z;
}