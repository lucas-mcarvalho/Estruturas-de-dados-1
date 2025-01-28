#include<stdio.h>
#include"Queue.h"

int main(){

Queue *queue = queue_create();

Queue_enqueue(queue,1);

Queue_enqueue(queue,2);

int item;

while(Queue_dequeue(queue,&item)){
    printf("%d",item);
}

    return 0;
}