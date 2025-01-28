#include"Stack.h"
#include<stdlib.h>
#define TAM 10
struct stack{
    int index;
    int data[TAM];
};


Stack *create(){
    Stack *stack = malloc(sizeof(stack));
    if(stack){
        stack->index =-1;
    }
    return stack;
}

int empilhar(Stack *stack,int info){
    if(!cheia){
        stack->index++;
        stack->data[stack->index] = info;
        return 1;
    }
    return 0;

}

int desempilhar(Stack *stack,int *info ){
    if(!vazia){
        *info = stack->data[stack->index];
        stack->index --;
        return 1;
    }
    return 0;
}

int topo(Stack *stack,int *info){
    if(!vazia){
        *info = stack->data[stack->index];
        return 1;
    }
    return 0;
}

void destroy(Stack *stack){
    free(stack);
}

int cheia(Stack *stack){
    return stack->index ==TAM -1;
}

int vazia(Stack *stack){
    return stack->index == -1;
}

int tamanho(Stack *stack){
    return stack->index+1;
}
