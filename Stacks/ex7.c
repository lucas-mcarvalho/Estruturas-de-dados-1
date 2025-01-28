/*Escreva um algoritmo que leia um número indeterminado de valores inteiros. O valor 0
(zero) finaliza a entrada de dados. Para cada valor lido, determinar se ele é um número par
ou ímpar. Se o número for par, então incluí-lo na FILA PAR; caso contrário, incluí-lo na
FILA ÍMPAR. Após o término da entrada de dados, retirar um elemento de cada fila,
alternadamente (iniciando-se pela FILA ÍMPAR) até que ambas as filas estejam vazias. Se o
elemento retirado de uma das filas for um valor positivo, então incluí-lo em uma PILHA;
caso contrário, remover um elemento da PILHA. Finalmente, escrever o conteúdo da pilha.*/
#include<stdio.h>
#include<stdlib.h>
#include"Queue.h"
#include"Stack.h"

int main(){
Queue * fila_impar = queue_create();
Queue *fila_par = queue_create();
Stack *stack = create();

int num;
do{
    printf("Digite um numero :\n");
    scanf("%d",&num);

    if(num %2 != 0){
        queue_enqueue(fila_impar,num);
    }else{
        queue_enqueue(fila_par,num);
    }
}while(num!=0);


int elemento,elemento2;
while(!queue_empty(fila_impar) || !queue_empty(fila_par)){
    queue_dequeue(fila_impar,&elemento);
    if(!queue_empty(fila_impar)){
    if(elemento >0){
        stack_push(stack,elemento);
    }else{
        int temp;
        stack_pop(stack,&temp);
    }
}
     if(!queue_empty(fila_par)){
    queue_dequeue(fila_par,&elemento2);

    if(elemento2 >0){
        stack_push(stack,elemento2);
    }else{
        int temp;
        stack_pop(stack,&temp);
    }

     }
}


print(stack);

    return 0;
}