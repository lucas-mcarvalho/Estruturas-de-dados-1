#include<stdlib.h>
#include<stdbool.h>
#include"Queue.h"
#define MAX 5
struct queue{
    int tail,qty,head;
    int data[MAX];
};

Queue *create(){
    Queue *fila = malloc(sizeof(Queue));
    if(fila){
        fila->head = 0;
        fila->qty = 0;
        fila ->tail = 0;
    }
    return fila;
}

void Queue_destroy(Queue *fila){
    free(fila);
}
//INSERINDO O ELEMENTO NA POSIÇÃO  INICIAL DA FILA/
bool Queue_enqueue(Queue *fila,int info){
    if(Queue_full(fila) || fila ==NULL) return false;
    fila->data[fila->tail] = info;
    /*USAMOS ISSO PARA NÃO ESTOURAR O LIMITE DO VETOR ,AO INVÉS DE APENAS INCREMENTÁLO,
    POIS O TAIL REPRESENTA A POSIÇÃO DO PROXIMO ELEMENTO*/
    fila->tail  = (fila->tail+1) %MAX;
    fila->qty++;
    return true;
}
    //SERVE PARA DESENFILEIRAR O ELEMENTO DO INICIO DA FILA/
bool Queue_dequeue(Queue *fila,int  *info){
    if(Queue_empty(fila)|| fila == NULL) return false;
    *info = fila->data[fila->head];
    /*O HEAD VAI VALER 1 DEPOIS DE ATENDER O QUE ESTAVA NA POSIÇÃO 0 
    , POIS A PESSOA ESTAVA ESPERANDO A MAIS TEMPO NA FILA,
    QUANDO FORMOS INSERIR ,IREI INSERIR NA POSIÇÃO 0 , MAS NÃO POSSO
    RETIRAR DA POSIÇÃO 0.*/
    fila->head = (fila->head+1)%MAX;
    fila->qty--;
    return true;
}

bool Queue_head(Queue *fila,int *info){
     if(Queue_empty(fila)|| fila == NULL) return false;
    *info = fila->data[fila->head];
    return true;
}

bool Queue_full(Queue *fila){
    return fila->qty ==MAX;
}

bool Queue_empty(Queue *fila){
    return fila->qty ==0;
}

bool Queue_qty(Queue *fila){
    return fila->qty;
}