#include"Stack.h"
#include<stdlib.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct stack{
    TNo *inicio;
    int qty;
};

TNo *createNfill(int info){
    TNo *novo = malloc(sizeof(TNo));
    if(novo){
        novo->info = info;
        novo->prox =NULL;
    }
    return novo;
}

Stack *create(){
    Stack *stack = malloc(sizeof(stack));
    if(stack){
        stack->inicio =NULL;
        stack->qty = 0;
    }
    return stack;
}

int empilhar(Stack *stack,int info){
    TNo *novo = createNfill(info);
    if(!novo) return 0;
    novo->prox = stack->inicio;
    stack->inicio = novo;
        stack->qty++;
        return 1;
    }


int desempilhar(Stack *stack,int *info){
    if(!vazia(stack)){
        *info = stack->inicio->info;
        TNo *aux = stack->inicio;
        stack->inicio = stack->inicio->prox; 
        free(aux);
        stack->qty--;
        return 1;
    }
    return 0;
}

int topo(Stack *stack,int *info){
    if(!vazia(stack)){
        *info = stack->inicio->info;
        return 1;
    }
    return 0;
}   

void destroy(Stack*);



int vazia(Stack *stack){
    return stack->qty ==0;
}

int tamanho(Stack *stack){
    return stack->qty;
}
