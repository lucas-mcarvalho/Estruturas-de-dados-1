/*Implemente a função reverso, que reposiciona os elementos na fila de tal forma que o início
da fila torna-se o fim, e vice-versa. */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Queue.h"
#include"Stack.h"

Queue  *reverse(Queue *queue){
    if(Queue_empty(queue) || queue == NULL) return queue;
    Stack * stack_aux = stack_create();
   
    if(!stack_aux) return queue;
    /*NESSA FUNÇÃO EU ARMAZENO OS ELEMENTOS DA FILA EM UMA PILHA E DEPOIS EU RETIRO 
    E COLOCO NA FILA NOVAMENTE ,CRIANDO UMA FILA REVERSA */
     int info;

    while(Queue_dequeue(queue,&info)){
        stack_push(stack_aux,info);
    }

    while(stack_pop(stack_aux,&info)){
        Queue_enqueue(queue,info);
    }    
    free(stack_aux);
    return queue;

}


int main(){

Queue *queue = create();

int vet[] = {1,2,3,4,5,6,7,8};

for(int i =0 ; i<8;i++){
    Queue_enqueue(queue,vet[i]);
}


Queue_print(queue);

printf("\n");

reverse(queue);

Queue_print(queue);

    return 0;
}