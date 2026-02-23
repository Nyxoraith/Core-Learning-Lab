#include <stdio.h>

/*
1) Escreva um programa que contenha duas variáveis inteiras. Compare os
endereços e exiba o endereço e o conteúdo do maior endereço.
*/

int main(){
    int num1 = 10;
    int num2 = 20;

    if(&num1 > &num2){
        printf("O endereço da variavel NUM1 é o maior.\n");
        printf("Conteudo da variavel NUM1: %d\n", num1);
        printf("Endereço da variavel NUM1: %p\n", &num1);
    }else{
        printf("O endereço da variavel NUM2 é o maior.\n");
        printf("Conteudo da variavel NUM2: %d\n", num2);
        printf("Endereço da variavel NUM2: %p\n", &num2);
    }

    return 0; 
}