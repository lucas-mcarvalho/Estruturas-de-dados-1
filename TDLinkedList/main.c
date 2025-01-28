#include"TDLinkedList.h"

int main(){
TDLinkedList *list = list_create();

list_insert_sorted(list,1);
list_insert_sorted(list,1);
list_insert_sorted(list,1);
list_insert_sorted(list,0);

list_print(list);



    return 0;
}