#include <stdio.h>
#include <stdlib.h>

/*
2) Faça um programa que receba valores enquanto eles estiverem no
intervalo de 500 a 1000. Ao receber um valor fora da faixa, o
programa deverá parar de solicitar valores, exibir quantos valores
válidos foram digitados e finalizar.
*/

int main(){
    int range = 0;
    int contador = 0;
    do{
        printf("Digite um valor entre 500 e 1000: ");
        scanf("%d", &range);
        contador++;
    }while(range >= 500 && range <= 1000);
    contador--;
    printf("Foram digitados %d valores válidos.\n", contador);
    return 0;
}