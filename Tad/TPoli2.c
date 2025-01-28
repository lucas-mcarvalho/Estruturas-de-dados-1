#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include"TPoli2.h"

struct polinomios{
    float coeficientes[3];
};

Polinomios *poliCreate(float i,float j,float k){
    Polinomios * novo = malloc(sizeof(Polinomios));
    if(novo){
        novo->coeficientes[0] = i;
        novo->coeficientes[1] = j;
        novo->coeficientes[2] = k;
    }
    return novo;
}

float avaliate(Polinomios*poli, float num){
    float resultado;
    resultado = (poli->coeficientes[0]*num*num) +(poli->coeficientes[1]*num) +(poli->coeficientes[2]);
    return resultado;
}   

Polinomios *soma(Polinomios*poli1,Polinomios*poli2){
Polinomios *resultado = malloc(sizeof(Polinomios));

for(int i =0 ; i<3 ; i++){
    resultado->coeficientes[i] = poli1->coeficientes[i]+poli2->coeficientes[i];
}
return resultado;

}

void print(Polinomios *poli){
    for(int i =0 ; i<3 ; i++){
        if(i == 0){
            printf("%.1fx²",poli->coeficientes[i]);
        }
        if(i==1){
            printf("+%.1fx",poli->coeficientes[i]);
        }
        else{
            printf("+%.1f", poli->coeficientes[i]);
        }
    }
}