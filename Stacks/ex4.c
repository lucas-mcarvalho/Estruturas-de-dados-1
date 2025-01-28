//Desenvolva uma função para inverter a posição dos elementos de uma pilha P.
#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"

Stack *reverse(Stack *stack){
    if(stack_empty(stack)|| stack ==NULL) return 0;
    int item;
    Stack *stack1 = create();
    Stack *stack2 = create();
//DESEMPILHO NA STACK ORIGINAL E DEPOIS EMPILHO NA OUTRA STACK TEMPORÁRIA
    while(stack_pop(stack,&item)){
        stack_push(stack1,item);
    }   
//AGORA DESEMPILHO DA STACK TEMPORÁROA E COLOCA NA OUTRA TEMPORÁRIA/
       while(stack_pop(stack1,&item)){
        stack_push(stack2,item);
    }   

    //EMPILHANDO E DESEMPILHANDO NA STACK ORIGINAL/
         while(stack_pop(stack2,&item)){
        stack_push(stack,item);
    }   

    return stack;

}   

int main(){

Stack *stack = create();

stack_push(stack,1);
stack_push(stack,2);
stack_push(stack,3);

print(stack);

reverse(stack);

printf("\n");


print(stack);


    return 0;
}