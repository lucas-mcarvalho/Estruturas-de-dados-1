#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"TCircList.h"

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo *inicio;
};

TNo *createNfill(int info){
    TNo *novo = malloc(sizeof(novo));
    if(novo){
        novo->info = info;
        novo->prox = NULL;
    }
    return novo;
}
TCircList* list_create(){
    TCircList *list = malloc(sizeof(TCircList));
    if(list){
        list->inicio = NULL;
    }
    return list;
}

bool list_insert_begin(TCircList *list,int info){
    TNo *novo = createNfill(info);
    if(novo ==NULL) return false;
    if(list->inicio ==NULL){
        list->inicio=novo;
        novo->prox = novo;
        return true;
    }else{
        TNo *aux = list->inicio;
        while(aux ->prox != list->inicio){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = list->inicio;
    }
    list->inicio = novo;
}

bool list_insert_end(TCircList *list,int info){
     TNo *novo = createNfill(info);
    if(novo ==NULL) return false;
    if(list->inicio ==NULL){
        list->inicio=novo;
        novo->prox = novo;
    }else{
        TNo *aux = list->inicio;
        while(aux ->prox != list->inicio){
            aux = aux->prox;
        }
        aux->prox = novo;
        novo->prox = list->inicio;
    }
    return true;
}

void list_print(TCircList *list){
    TNo *aux = list->inicio;
    while(aux !=list->inicio){
        printf("%d ->",aux->info);
        aux = aux ->prox;
    }
    
}