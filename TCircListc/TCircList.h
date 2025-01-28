#ifndef TCircList_H
#define TCircList_H
#include<stdbool.h>

typedef struct _list TCircList;

TCircList* list_create();

bool list_insert_begin(TCircList*,int);

bool list_insert_end(TCircList*,int);

void list_print(TCircList*);



#endif