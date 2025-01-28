#include"Stack.h"
#include<stdio.h>

int main(){

Stack *stack = stack_create();


if(stack_empty(stack)){
    printf("Pilha vazia !\n");
}else{
    printf("Cheia!");
}





    return 0;
}