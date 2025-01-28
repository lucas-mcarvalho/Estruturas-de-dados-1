#ifndef Queue_H
#define Queue_H
#include<stdbool.h>

typedef struct queue Queue;

Queue *queue_create();

bool Queue_enqueue(Queue*,int);

bool Queue_dequeue(Queue*,int *info);

bool Queue_empty(Queue*);

void Queue_print(Queue*);

void Queue_destroy(Queue*);


#endif