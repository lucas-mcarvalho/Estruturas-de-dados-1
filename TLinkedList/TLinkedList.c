#include<stdio.h>
#include<stdlib.h>
#include"TLinkedList.h"
#include<stdbool.h>

typedef struct _no{
    int info;
    struct _no *prox;
}TNo;

struct _list{
    TNo *inicio;
};

TNo *CreateNfill(int info){
    TNo *novo = malloc(sizeof(TNo));
    if(novo){
        novo->info = info;
        novo->prox =NULL;
    }
    return novo;
}

TLinkdedList *list_create(){
    TLinkdedList *list = malloc(sizeof(TLinkdedList));
    if(list){
        list->inicio = NULL;
    }
    return list;
}

bool list_insert_begin(TLinkdedList *list,int info){
        TNo *novo = CreateNfill(info);
        if(novo ==NULL) return false;
        novo->prox = list->inicio;
        list->inicio = novo;
        return true;
        
}

bool list_insert_end(TLinkdedList *list,int info){
           TNo *novo = CreateNfill(info);
         if(novo ==NULL) return false;
        if(list->inicio ==NULL){
            list->inicio = novo;
        }else{
            TNo *aux = list->inicio;
            while(aux->prox !=NULL){
                aux = aux->prox;
            }
            aux ->prox = novo;
            return true;
        }
}

void list_print(TLinkdedList *list){
    TNo *aux = list->inicio;
    while(aux!=NULL){
        printf("%d->",aux->info);
        aux = aux->prox;
    }   
}
bool list_remove(TLinkdedList *list, int info){
    if(list->inicio ==NULL) return false;
    TNo *atual = list->inicio;
    TNo *anterior = NULL;
    // Percorrer a lista para encontrar o nó a ser removido
    while(atual!=NULL && atual->info!= info){
        anterior = atual;
        atual = atual->prox;
    }if(atual ==NULL) return false; //VALOR NÃO ENCONTRADO
    if(anterior ==NULL){
        list->inicio = atual->prox;
    }else{
        anterior->prox = atual->prox;
    }
    free(atual);
    return true;
}