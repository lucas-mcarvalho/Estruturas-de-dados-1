/*Escreva um algoritmo, usando uma Pilha, que inverte as letras de cada palavra de um texto
terminado por ponto (.) preservando a ordem das palavras. Por exemplo, dado o texto:
1. ESTE EXERCÍCIO É MUITO FÁCIL.
2. A saída deve ser:
3. ETSE OICÍCREXE É OTIUM LICÁF*/
#include<stdlib.h>
#include<stdio.h>
#include"Stack.h"
#include<string.h>

void reverse_print(Stack *stack){
    if(stack ==NULL || stack_empty(stack)) return;
    int item;

    while(stack_pop(stack,&item)){
        printf("%c",item);
    }
}

int main(){

Stack *stack = stack_create();

char string[1024];

fgets(string,1024,stdin);

for(int i =0 ;i<strlen(string);i++){
    if(string[i] == '\n'){
        break;
    }
    if(string[i] == '.' || string[i] == ' '){
        reverse_print(stack);
        printf("%c",string[i]);
    }
    stack_push(stack,string[i]);
}

if(!stack_empty(stack)){
    reverse_print(stack);
}


    return 0;
}