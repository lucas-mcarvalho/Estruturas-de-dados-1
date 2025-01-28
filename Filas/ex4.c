/*Escreva uma função que, dado duas filas, concatene as duas filas. Retorne a fila concatenada
em F1. F2 deve ficar vazia*/
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Queue.h"


bool concatenate(Queue*queue,Queue *queue2){
   if(queue ==NULL || queue2 == NULL) return false;
   if(Queue_empty(queue) || Queue_empty(queue)) return false;

    int info;
//INSERINDO OS ELEMENTOS DA FILA 2 NA FILA ,CONCATENANDO AS DUAS/
    while(Queue_dequeue(queue2,&info)){
        Queue_enqueue(queue,info);
    }
    return true;
    
}


int main(){

Queue *fila1 = create();
Queue *fila2 = create();

int vet[] = {1,2,3,4,5,6};
int vet2[] = {7,8,9,10,11,12};
for(int i =0;i<sizeof(vet)/sizeof(vet[0]);i++){
    Queue_enqueue(fila1,vet[i]);
    Queue_enqueue(fila2,vet2[i]);
}

Queue_print(fila1);
Queue_print(fila2);


concatenate(fila1,fila2);

Queue_print(fila1);




    return 0;
}