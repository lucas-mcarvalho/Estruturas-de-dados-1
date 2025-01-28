/*Desenvolva uma operação para transferir elementos de uma pilha P1 para uma pilha P2
(cópia).*/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"

bool stack_copy(Stack *stack1, Stack *stack2){
    /*VERIFICANDO SE ESTÃO VAZIAS */
    if(stack_empty(stack1) || stack2 ==NULL) return false;
    int item;
    Stack *stack_copy = create();
    /*A LOGIA SERIA COLOCAR TODOS OS ELEMENTO DA PILHA PRINCIPAL
    NA PILHA COPIA E DEPOIS COLOCAR NAS DUAS PILHAS ,A COPIA E A ORIGINAL*/
    while(stack_pop(stack1,&item)){
        stack_push(stack_copy,item);
    }

    while(stack_pop(stack_copy,&item)){
        stack_push(stack2,item);
         stack_push(stack1,item);
    }
    return true;
}

int main(){

Stack * stack1 = create();
Stack * stack2 = create();

int vet [] = {1,2,3};

for(int i=0 ;i<3 ; i++){
    stack_push(stack1,vet[i]);
}

print(stack1);

printf("\n");

stack_copy(stack1,stack2);


print(stack2);

    return 0;
}