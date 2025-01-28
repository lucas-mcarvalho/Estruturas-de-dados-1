/*Considere uma pilha que armazene caracteres. Escreva uma função que verifique se uma
palavra É um palíndromo.*/
#include "Stack.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main(){
    //Ler a string
    char string[1024];
    //FGETS SERVE  PARA  DAR ENTRADA DE DADOS
    fgets(string, 1024, stdin);
    Stack *stack = create();
    for(int i = 0; i <strlen(string); i++){
        //\n SIGNIFICA O FIM DA STRING
        //\r significa o final de uma string no windows
        if(string[i] == '\n' || string[i] == '\r' || string[i]=='\0')
            break;
        stack_push(stack, string[i]);
    }
    bool palim = true; 
    int item;
    for(int i = 0; i <strlen(string) && palim; i++){
        if(string[i] == '\n' || string[i] == '\r' || string[i]=='\0')
            break;
        stack_pop(stack, &item); 
        if((char)item != string[i])
            palim = false;
    }
    if(palim)
        puts("Palim");
    else
        puts("Nao eh Palim");
    return 0;
}