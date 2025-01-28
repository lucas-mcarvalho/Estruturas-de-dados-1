#include"TLinkedList.h"
#include<stdio.h>

int main(){

TLinkdedList *list = list_create();

list_insert_begin(list,1);
list_insert_begin(list,2);
list_insert_begin(list,3);
list_insert_begin(list,4);
list_insert_begin(list,5);

list_print(list);



printf("\n");
list_print(list);

    return 0;
}