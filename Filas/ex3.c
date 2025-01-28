/* Faça uma função que receba três filas, duas já preenchidas em ordem crescente e preencha
a última com os valores das duas primeiras em ordem crescente.*/
#include<stdlib.h>
#include<stdbool.h>
#include"Queue.h"
#include<stdio.h>


bool ascending_order(Queue *fila1,Queue *fila2, Queue *fila3){

    if(fila1 ==NULL || fila2 ==NULL) return false;
    if(Queue_empty(fila1) || Queue_empty(fila2)) return false;
    if(fila3 ==NULL ) return false;
    ;
    int info1,info2;

    while(!Queue_empty(fila1) && !Queue_empty(fila2)){
        //RETIRANDO DO TOPO DAS DUAS FILAS
        Queue_dequeue(fila1,&info1);
         Queue_dequeue(fila2,&info2);
    /*SE A INFO 1 FOR MENOR QUE A INFO 2,ENTÃO A MINHA FILA 3 RECEBE A INFO 1
       E A MINHA FILA 2 CONTINUA COM A INFO 2. 
    */

   /*SE A INFO 1 FOR MENOR QUE A INFO 2 ,ENTÃO EU INSIRO NA FILA 3 A INFO 1 ,CASO CONTRARIO INSIRO A
   INFO 2*/
         if(info1 <= info2){
            Queue_enqueue(fila3,info1);
            Queue_enqueue(fila2,info2);
         }else{
             Queue_enqueue(fila3,info2);
            Queue_enqueue(fila1,info1);

         }
    }
    //SE AINDA RESTAREM ELEMENTOS NAS FILA 1 OU 2 INSERE NA FILA 3/
    while(Queue_dequeue(fila1,&info1)){
        Queue_enqueue(fila3,info1);
    }

     while(Queue_dequeue(fila2,&info2)){
        Queue_enqueue(fila3,info2);
    }

return true;

}

int main(){

Queue *fila1 = create();
Queue *fila2 = create();
Queue *fila3 = create();

int vet1[] = {1,2,3,4,5,6};
int vet2[] = {7,8,9,10,11,12};

for(int i =0 ; i<6;i++){
    Queue_enqueue(fila1,vet1[i]);
     Queue_enqueue(fila2,vet2[i]);
}

Queue_print(fila1);
printf("\n");


Queue_print(fila2);

ascending_order(fila1,fila2,fila3);

printf("\n");

Queue_print(fila3);
    return 0;
}