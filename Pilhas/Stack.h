#ifndef Stack_H
#define Stack_H

typedef struct stack Stack;

Stack *create();

int empilhar(Stack*,int);

int desempilhar(Stack*,int*);

int topo(Stack*,int*);

void destroy(Stack*);

int cheia(Stack*);

int vazia(Stack*);

int tamanho(Stack*);










#endif