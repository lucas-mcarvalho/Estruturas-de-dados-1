#include<stdlib.h>
#include"Queue.h"
#include<stdio.h>

typedef struct no{
    int info;
    struct no *prox;
}TNo;

struct queue{
    TNo *end;
    int qty;
};

TNo *createNfill(int info){
    TNo *novo = malloc(sizeof(TNo));
    if(novo){
        novo->info = info;
        //NOVO APONTA PRA ELE MESMO
        novo->prox = novo;
    }
    return novo;
}

Queue *create(){
    Queue *fila = malloc(sizeof(Queue));
    if(fila){
        fila->end = NULL;
        fila->qty = 0;
    }
    return fila;
}

void Queue_destroy(Queue *){

}

bool Queue_enqueue(Queue *fila,int info){
    TNo *novo = createNfill(info);
    if(novo ==NULL) return false;
    if(fila->end ==NULL){
        /*SE A LISTA ESTIVER VAZIA, COLOCAMOS O ELEMENTO NO INICIO,
        COMO ELE É O PRIMEIRO ELE É O PRÓPRIO FIM*/
        fila->end = novo;
        fila->qty++;
    }else{
        /*AQUI FAZEMOS ELE AO INVÉS DE APONTAR PARA SI MESMO
        , APONTAR PARA O PROX DO ELEMENTO INICIAL,OU SEJA "O PROX 
        DA CAIXA ANTERIOR VAI SER O NOVO ELEMENTO.
        FAZEMOS ELE RECEBER O ENDEREÇO DO PRIMEIRO NO."*/
        novo->prox = fila->end->prox;
        //AQUI CONECTAMOS ELA ,FAZENDO ELA APONTAR PARA O PRIMEIRO ELEMENTO/
        fila->end->prox = novo;
        //NOVO FIM DA FILA AGORA É O NOVO  ELEMENTO/
        fila->end = novo;
        fila->qty++;
    }
    return true;
}

bool Queue_dequeue(Queue *fila,int *info){
        if(Queue_empty(fila) || fila ==NULL) return false;
        //PEGAMOS O ENDEREÇO DO PRIMEIRO ELEMENTO/
        TNo *oldbegin = fila->end->prox;
        *info = oldbegin->info;
        //VERIFICANDO SE ESSE É O PRIMEIRO ELEMENTO DA FILA,SE FOR/
        if(fila->end  ==oldbegin){
            //SE FOR O END VAI SER ATUALIZADO PAR NULL , PRA NÃO DAR ERRO NO ENQUEUE/
            fila->end =NULL;
        }else{
        /*AQUI FAZEMOS ELE APONTAR PARA A PRÓXIMA PESSOA DEPOIS DO NO,
        EX: A PESSOA 1 SAIU AGORA É A VEZ DA PESSOA 2 .*/
        fila->end->prox = oldbegin->prox;
        }
        fila->qty--;
        //LIBERAMOS A OLBEGIN
        free(oldbegin);
        return true;

}

bool Queue_head(Queue *fila,int *info){
if(Queue_empty(fila) || fila ==NULL) return false;
        TNo *oldbegin = fila->end->prox;
         *info = oldbegin->info; return true;
}

bool Queue_full(Queue *fila){
    return false;
}

bool Queue_empty(Queue *fila){
    return fila->end ==NULL;
}

bool Queue_qty(Queue *fila){
    return fila->qty;
}

void Queue_print(Queue *queue){
    if(Queue_empty(queue) || queue ==NULL) return ;
    TNo *aux = queue->end->prox;
    do{
        printf("%d ->",aux->info);
        aux = aux->prox;
    }while(aux != queue->end->prox);
    printf("\n");
}

void destroy(Queue *queue){
    if(queue ==NULL) return;
    
    TNo *aux = queue->end->prox;
    TNo *temp;

    while(queue->qty >0){
        temp = aux->prox;
        free(aux);
        
        aux = temp;
        queue->qty --;
    }
    free(queue);

}