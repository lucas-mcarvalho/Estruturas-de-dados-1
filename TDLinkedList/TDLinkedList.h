#ifndef TDLinkedList_H
#define TDLinkedList_H
#include<stdbool.h>

typedef struct _list TDLinkedList;

TDLinkedList *list_create();

bool list_insert_end(TDLinkedList*,int );

bool list_insert_begin(TDLinkedList*,int );

void list_print(TDLinkedList*);

void list_print_reverse(TDLinkedList*);

bool list_insert_sorted(TDLinkedList*,int );


#endif