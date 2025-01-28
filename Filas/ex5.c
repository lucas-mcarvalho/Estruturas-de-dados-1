//Faça uma função para retornar o número de elementos da fila que possuem valor ímpar/
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Queue.h"

int pair(Queue* queue){
if(Queue_empty(queue)  || queue ==NULL) return false;


int info;
int imp = 0;
Queue *aux = create();

while(Queue_dequeue(queue,&info)){
    Queue_enqueue(aux,info);
}

/*NESSA FUNÇÃO EU RETIRO E COLOCO OS ELEMENTOS NA MESMA FILA E VERIFICA SE O RESTO 
DO NUMERO É DIFERENTE DE 2 , SE FOR ,O MEU CONTADOR DE IMPARES RECEBE ++*/
while(Queue_dequeue(aux,&info)){
    if(info %2 != 0){
    imp++;
}
Queue_enqueue(queue,info);

}
return imp;
}

int main(){

Queue *queue = create();

int vet[] = {1,2,3,4,5,6,7};

for(int i =0; i <sizeof(vet)/sizeof(vet[0]); i++){
    Queue_enqueue(queue,vet[i]);    
}


Queue_print(queue);

printf("Numero de impares : %d ",pair(queue));

printf("\n");

Queue_print(queue);

    return 0;
}