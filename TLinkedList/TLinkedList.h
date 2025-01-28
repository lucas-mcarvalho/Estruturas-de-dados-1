#ifndef TLinkdedList_H
#define TLinkdedList_H
#include<stdbool.h>
typedef struct _list TLinkdedList;
 
TLinkdedList *list_create();

bool list_insert_begin(TLinkdedList*,int);

bool list_insert_end(TLinkdedList*,int);

void list_print(TLinkdedList*);
bool list_remove(TLinkdedList *, int);





#endif