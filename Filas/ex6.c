//Faça uma função para retornar o número de elementos da fila que possuem valor par/
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Queue.h"

int pair(Queue* queue){
if(Queue_empty(queue)  || queue ==NULL) return false;


int info;
int par = 0;
Queue *aux = create();

while(Queue_dequeue(queue,&info)){
    Queue_enqueue(aux,info);
}

/*NESSA FUNÇÃO EU FAÇO A MESMA COISA QUE NA FUNÇÃO IMPAR, SÓ MUDA QUE EU VERIFICA SE O RESTO 
É 2 ,SE FOR O MEU CONTADOR ++*/
while(Queue_dequeue(aux,&info)){
    if(info %2 == 0){
    par++;
}
Queue_enqueue(queue,info);

}
return par;
}

int main(){

Queue *queue = create();

int vet[] = {1,2,3,4,5,6,7,8};

for(int i =0; i <sizeof(vet)/sizeof(vet[0]); i++){
    Queue_enqueue(queue,vet[i]);    
}


Queue_print(queue);

printf("Numero de pares : %d ",pair(queue));

printf("\n");

Queue_print(queue);

    return 0;
}