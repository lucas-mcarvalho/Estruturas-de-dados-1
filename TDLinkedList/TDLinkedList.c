#include<stdio.h>
#include<stdlib.h>
#include"TDLinkedList.h"

typedef struct _no{
    int info;
    struct _no *prox;
    struct _no *ant;
}TNo;

struct _list{
    TNo *inicio;
    TNo *fim;
};

TNo *createNfill(int info){
    TNo *novo = malloc(sizeof(TNo));
    if(novo){
        novo->info = info;
        novo->ant =NULL;
        novo->prox = NULL;
    }
    return novo;
}

TDLinkedList *list_create(){
    TDLinkedList *list = malloc(sizeof(TDLinkedList));
    if(list){
        list->inicio =NULL;
        list->fim = NULL;
    }
    return list;
}

bool list_insert_begin(TDLinkedList *list,int info){
    TNo *novo = createNfill(info);
    if(novo ==NULL) return false;
    if(list->inicio ==NULL) {
        list->inicio =novo;
        list->fim = novo;
        return true;
    }else{
        novo->prox = list->inicio;
        list->inicio->ant = novo;
        list->inicio = novo;
          return true;
    }

}

bool list_insert_end(TDLinkedList *list,int  info){
    TNo *novo = createNfill(info);
    if(novo ==NULL) return false;
    if(list->inicio ==NULL) {
        list->inicio =novo;
        list->fim = novo;
        return true;
    }else{
        list->fim->prox = novo;
        novo->ant = list->fim;
        list->fim = novo;
        return true;
    }
}

void list_print(TDLinkedList *list){
    TNo *aux = list->inicio ;
    while(aux!=NULL){
        printf("%d->",aux->info);
        aux = aux->prox;
    }
}

void list_print_reverse(TDLinkedList *list){
     TNo *aux = list->fim ;
    while(aux!=NULL){
        printf("%d->",aux->info);
        aux = aux->ant;
    }
}

bool list_insert_sorted(TDLinkedList *list,int info ){
     TNo *novo = createNfill(info);
    if(novo ==NULL) return false;
    if(list->inicio ==NULL){
        list->inicio = novo;
        list->fim = novo;
        return true;
    }
    if(info <=list->inicio->info){
        novo->prox = list->inicio;
        list->inicio->ant = novo;
        list->inicio = novo;
         return true;
    }if(info> list->fim->info){
          list->fim->prox = novo;
            novo->ant = list->fim;
             list->fim = novo;
        return true;
    }TNo *atual = list->inicio->prox;
    while(atual->prox !=NULL && atual->info < info){
        atual = atual->prox;
    }
    novo->prox = atual;
    novo->ant = atual->ant;
    atual->ant->prox = novo;
    atual->ant = novo;
    return true;
    

}
