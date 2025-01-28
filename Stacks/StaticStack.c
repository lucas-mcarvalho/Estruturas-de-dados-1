#include<stdbool.h>
#include<stdlib.h>
#include"Stack.h"
#define TAM 10

struct stack{
    int index,qty;
    int data[TAM];
};

Stack *stack_create(){
    Stack *stack = malloc(sizeof(Stack));
    if(stack){
        stack->index = 0;
        stack->qty = 0;
    }
    return stack;
}

bool stack_push(Stack *stack,int info){
    if(stack ==NULL || stack_full(stack)) return false;
    stack->data[stack->index++] = info;
    stack->qty++;
    return true;

}

bool stack_pop(Stack *stack,int *info){
    if(stack_empty(stack) || stack ==NULL) return false;
    *info = stack->data[stack->index -1];
    stack->index --;
    stack->qty --;
    return true;
}

bool stack_destroy(Stack*);

bool stack_empty(Stack *stack){
    return stack->qty ==0;
}
bool stack_full(Stack *stack){
    return stack->index == TAM;
}