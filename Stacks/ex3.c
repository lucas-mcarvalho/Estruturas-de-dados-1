/*Escreva um programa que utilize uma pilha para verificar se expressões aritméticas estão
com a parentização correta. O programa deve verificar expressões para ver se cada “abre
parênteses” tem um “fecha parênteses” */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Stack.h"
#include<string.h>

bool check_parts(const char *expression){
    Stack *stack = create();
    if(stack ==NULL) return false;

    for(int i =0 ; expression[i] != '\0';i++){
        char caractere = expression[i];
        //ARMAZENANDO NA PILHA O ABRE PARENTESES
        if(caractere == '('){
            stack_push(stack,caractere);
            /*SE O USUARIO DIGITAR O ")"FECHAR PARENTESES,
            ELE PROCURA NA PILHA E VERIFICAR SE ENCONTRA OUTRO "("
            CORRESPONDENTE ,SE ELE ENCONTRAR NO TOPO UM FECHAR PARENTESES,
            OU ELE FALHAR PARA DESEMPILHAR RETORNA FALSO*/
        }else if(caractere == ')'){
            int topo;
            if(!stack_pop(stack,&topo) || topo != '('){
                return false;
            }
        }

    }
    /*AQUI VERIFICAMOS SE A PILHA ESTÁ VAZIA ,SE ESTIVER 
    A EXPRESSÃO ESTÁ BALANCEADA , CASO NÃO ESTEJA ,ELA VIRA FALSO , 
    E AO FINAL FAZEMOS O FREE(STACK) QUE SIGNIFICA LIBERAR A PILHA
    E RETORNAMOS O VALOR BOOL DE BALANCEADO*/
    bool balanceado  = stack_empty(stack);
    free(stack);
    return balanceado;
}  


int main(){

char expresao[1024];

fgets(expresao,1024,stdin);

if(check_parts(expresao)){
    printf("Expressao correta!\n");
}else{
    printf("Expressao incorreta!\n");
}
    return 0;
}