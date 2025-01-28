#include<stdlib.h>
#include<stdbool.h>
#include<stdio.h>
#include"Stack.h"

typedef struct no{
    int info;
    struct no *prox;
}TNo;

struct stack{
    TNo *topo;
    int qty;
};

TNo *createNfill(int info){
    TNo *novo = malloc(sizeof(TNo));
    if(novo){
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}

Stack *stack_create(){
    Stack *stack = malloc(sizeof(Stack));
    if(stack){
        stack->qty = 0;
        stack->topo = NULL;
    }
    return stack;
}

bool stack_push(Stack *stack,int info){
    TNo * novo = createNfill(info);
    if(novo ==NULL || stack ==NULL) return false;
    novo->prox = stack->topo;
    stack->topo = novo;
    stack->qty++;
    return true;
}

bool stack_pop(Stack *stack,int *info){
    if(stack_empty(stack) || stack ==NULL) return false;
    TNo * aux = stack->topo;
    *info = aux->info;
    stack->topo = aux->prox;
    free(aux);
    stack->qty--;
    
    return true;
}

bool stack_empty(Stack *stack){
    return stack->topo ==NULL;
}

bool stack_destroy(Stack*);

bool stack_print(Stack *stack){
    if(stack_empty(stack)|| stack==NULL) return false;
    TNo *aux = stack->topo;
    do{
        printf("%d ",aux->info);
        aux = aux->prox;
    }while(aux!= NULL);
    return true;
}