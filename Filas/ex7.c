/*. Faça uma função para intercalar filas: a função recebe as duas filas e retorna a fila com os
elementos das duas filas intercalados conforme a ordem com que elas se dispõe na fila.
*/
#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#include"Queue.h"

bool interleave(Queue*fila1,Queue*fila2,Queue *fila3){
    if(Queue_empty(fila1) && Queue_empty(fila2)) return false;
    if(fila1 ==NULL || fila2 ==NULL) return false;

    int info1,info2;
    /*CRIO UM LOOP PARA RODAR ENQUANTO AS FUNÇÕES NÃO ESTIVEREM VAZIAS , E DENTRO DO LOOP
    EU COLOCO UM IF PARA VERIFICA SE A FILA 1 OU 2 NÃO ESTÁ VAZIA,
    SE NÃO ESTIVER EU INSIRO NA FILA 3 ,INTERCALANDO OS ELEMENTOS ENTRE AS DUAS FILAS*/
    while(!Queue_empty(fila1) || !Queue_empty(fila2)){
            if(!Queue_empty(fila1)){
        Queue_dequeue(fila1,&info1);
        Queue_enqueue(fila3,info1);
        }
         if(!Queue_empty(fila2)){
        Queue_dequeue(fila2,&info2);
        Queue_enqueue(fila3,info2);
        }
    }

    return true;


}   

int main(){

Queue *queue = create();
Queue *queue2 = create();
Queue *queue3 = create();

int vet[] = {1,2,3,4,5,6};
int vet2[] ={7,8,9,10,11,12};

for(int i =0 ; i<(sizeof(vet)/(sizeof(vet[0])));i++){
    Queue_enqueue(queue,vet[i]);
     Queue_enqueue(queue2,vet2[i]);
}

Queue_print(queue);
printf("\n");
Queue_print(queue2);

interleave(queue,queue2,queue3);

printf("\n");


Queue_print(queue3);


    return 0;
}