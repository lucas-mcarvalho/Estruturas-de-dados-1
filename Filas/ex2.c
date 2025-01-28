/*Dada uma fila de inteiros, escreva um programa que exclua todos os números negativos sem
alterar a posição dos outros elementos da fila.
*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"Queue.h"

bool negative_destroy(Queue *queue){
    if(Queue_empty(queue) || queue ==NULL) return false;

    int temp;
    Queue *queue_temp = create();
    if(queue ==NULL) return false;

    while(Queue_dequeue(queue,&temp)){
        if(temp >=0){
        Queue_enqueue(queue_temp,temp);
        }
    }
    while(Queue_dequeue(queue_temp,&temp)){
        Queue_enqueue(queue,temp);
    }
    return true;
}

int main(){

Queue *queue = create();
if(queue ==NULL) return -1;

int vet [] = {1,2,3,4,5,6,7,-8};

for(int i =0 ; i<8;i++){
    Queue_enqueue(queue,vet[i]);
}

Queue_print(queue);

printf("\n");

negative_destroy(queue);

Queue_print(queue);





    return 0;
}