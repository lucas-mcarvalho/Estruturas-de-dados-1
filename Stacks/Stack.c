#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"
#include<stdio.h>


typedef struct no{
    int info;
    struct no *prox;
}TNo;


struct stack{
    TNo *topo;
    int qty;
};

TNo *createNfill2(int info){
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
        stack->topo = NULL;
        stack->qty = 0;
    }
    return stack;
}

bool stack_push(Stack *stack,int info){
    TNo *novo = createNfill2(info);
    if(novo ==NULL) return false;
    if(stack->topo ==NULL){
        stack->topo = novo;
        stack->qty++;
        return true;
    }else{
        novo->prox = stack->topo;
        stack->topo = novo;
        stack->qty++;
    }
    return true;
}

bool stack_pop(Stack *stack,int *info){
    if(stack_empty(stack)|| stack ==NULL) return false;
    *info = stack->topo->info;
    TNo *delete = stack->topo;
    stack->topo = stack->topo->prox;
    free(delete);
    stack->qty++;
    return true;
}

bool stack_destroy(Stack*){

}


bool stack_empty(Stack *stack){
    return stack->topo == NULL;
}

bool stack_print(Stack *stack){
    if(stack ==NULL || stack_empty(stack)) return false;
    TNo *aux = stack->topo;
    do{
        printf("%d->",aux->info);
        aux = aux->prox;
    }while(aux!=NULL);
    return true;
}