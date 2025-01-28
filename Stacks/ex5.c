/*Desenvolva uma função para testar se duas pilhas P1 e P2 são iguais.
*/
#include<stdio.h>
#include<stdlib.h>
#include"Stack.h"
#include<stdbool.h>

bool equal(Stack *stack1, Stack *stack2){
    //VERIFICANDO SE AS PLIHAS ESTÃO VAZIAS/
    if(stack_empty(stack1) || stack_empty(stack2)) return false;
    int aux1,aux2;
    Stack *stack_aux= create();
    Stack *stack_aux2 = create();
    //INICIALIZANDO AS VARIÁVEIS E DEPOIS O LOOP/
    while(!stack_empty(stack1) && !stack_empty(stack2)){
    /*ENQUANTO AS PILHAS NÃO ESTIVEREM VAZIAS O LOOP CONTINUA
    ,DESEMPILHANDO E COLOCANDO NAS STACKS AUXILIARES*/
        stack_pop(stack1,&aux1);
        stack_pop(stack2,&aux2);
            
            //VERIFICANDO SE OS VALORES SÃO DIFERENTES
            if(aux1 != aux2){
                return false;
            }
            //ADICIONANDO NAS STACKS AUXILIARES
            stack_push(stack_aux,aux1);
             stack_push(stack_aux2,aux2);
        }
        /*CASO MESMO APÓS O LOOP ,A STACK CONTINUE COM 
          MAIS ELEMENTOS, OU SEJA ELA NÃO ESTÁ VAZIA,SIGNIFICA QUE
          ELAS NÃOS SÃO IGUAIS
          */      if(!stack_empty(stack1) || !stack_empty(stack2)){
                    return false;
        }
        /*AGORA CRIAMOS UM LOOP PARA DEVOLVER OS VALORES AS PILHAS ORIGINAIS
         RETORNANDO*/
        while(!stack_empty(stack1)){
            stack_pop(stack_aux,&aux1);
            stack_push(stack1,aux1);
        }
        while(!stack_empty(stack2)){
            stack_pop(stack_aux2,&aux2);
            stack_push(stack2,aux2);
        }
//LIBERANDO AS AUXILIARES   
        free(stack_aux);
        free(stack_aux2);
        return true;
    }
    



int main(){

Stack *stack1 = create();
Stack *stack2 = create();

int vet[]={1,2,3,4,5,6};

for(int i =0; i<6;i++){
    stack_push(stack1,vet[i]);
       
}

if(equal(stack1,stack2)){
    printf("Iguais!\n");
}else{
    printf("Diferentes!\n");
}
    return 0;
}