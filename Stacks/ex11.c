#include<stdio.h>
#include"Stack.h"

int main(){
Stack *stack = create();

int num;

printf("Digite um numero para converter em binario: \n");
scanf("%d",&num);

while(num!= 0){
    stack_push(stack,(num %2));
    num = num/2;
}

print(stack);






    return 0;
}