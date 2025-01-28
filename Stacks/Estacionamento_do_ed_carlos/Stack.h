#ifndef Stack_H
#define Stack_H
#include<stdbool.h>

typedef struct stack Stack;

Stack *stack_create();

bool stack_push(Stack*,int );

bool stack_pop(Stack*,int*);

bool stack_destroy(Stack*);

bool stack_empty(Stack*);

bool stack_full(Stack*);

bool stack_print(Stack *);

#endif