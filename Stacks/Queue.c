#include<stdlib.h>
#include<stdbool.h>
#include"Queue.h"

typedef struct no{
    int info;
    struct no *prox;
}TNo;

struct queue{
    TNo *fim;
    int qty;
};

TNo *createNfill(int info){
    TNo *novo = malloc(sizeof(TNo));
    if(novo){
        novo->prox = NULL;
        novo->info = info;
    }
    return novo;
}

Queue *queue_create(){
    Queue *novo = malloc(sizeof(Queue));
    if(novo){
        novo->fim =NULL;
        novo->qty = 0;
    }
    return novo;
}

bool Queue_enqueue(Queue *queue,int info){
    TNo *novo = createNfill(info);
    if(novo ==NULL ) return false;
    if(queue->fim ==NULL){
        queue->fim = novo;
        queue->qty++;
        return true;
    }else{
        novo->prox = queue->fim->prox;
        queue->fim->prox = novo;
        queue->fim = novo;
        queue->qty++;
        return true;
    }
}

bool Queue_dequeue(Queue *queue,int *info){
    if(Queue_empty(queue)|| queue ==NULL) return false;
    TNo *aux = queue->fim->prox;
    *info = aux->info;
    queue->fim->prox = aux->prox;
    free(aux);
    queue->qty--;
    return true;
}
bool Queue_empty(Queue *queue){
    return queue->fim ==NULL;
}