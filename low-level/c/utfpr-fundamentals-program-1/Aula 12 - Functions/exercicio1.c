#include <stdio.h>
#include <stdlib.h>

/*
1) Faça um algoritmo que implemente uma função que receba 3 números
inteiros e retorne o maior valor;
*/

int maior_Numero(int num1, int num2, int num3);

int main(){
    int num1 = 55, num2 = 13, num3 = 108;
    int maior;
    maior = maior_Numero(num1, num2, num3);
    printf("Maior numero é: %d", maior);
    return 0;
}

int maior_Numero(int num1, int num2, int num3){
    int maior = num1;

    if (maior < num2){
        maior = num2;
    }if (maior < num3){
        maior = num3;
    }

    return maior;
}