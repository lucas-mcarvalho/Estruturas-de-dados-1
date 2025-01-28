#include<stdio.h>
#include"Stack.h"
#include<stdlib.h>


int main(){

Stack *parking = stack_create();
Stack *secondary_parking = stack_create();
int op=0;
int id;
do{
    printf("1-Inserir no estacionamento \n2-Remover \n0-sair.\n");
    scanf("%d",&op);

    switch (op){
    case 1: printf("Digite o id do carro a ser inserido: \n");
            scanf("%d",&id);
            if(!stack_push(parking,id)){
                printf("Overflow!.\n");
            }
        break;
        case 2: 
        printf("Digite o id a ser removido : \n");
        scanf("%d",&id);
        int temp;
        int count =0;
        while(stack_pop(parking,&temp)){
            printf("%d",temp);
            printf(",");
            if(temp == id){
                count = 1;
                break;
            } 
            stack_push(secondary_parking,temp);
            
        }
        if(count != 1){
        printf("Underflow!\n");
        }
    //AQUI ESTOU REMOVENDO PRO ESTACIONAMENTO PRIMARIO/
        while (stack_pop(secondary_parking,&temp)){
            stack_push(parking,temp);
        }
       
        break;
    
    default:
        break;
    }

}while(op!=0);



    return 0;
}