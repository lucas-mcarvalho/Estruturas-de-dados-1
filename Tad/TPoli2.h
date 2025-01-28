#ifndef TPoli2_H
#define TPoli2_H

typedef struct polinomios Polinomios;

Polinomios *poliCreate(float ,float,float);

float avaliate(Polinomios* , float num);

Polinomios *soma(Polinomios*,Polinomios*);

void print(Polinomios*);





#endif