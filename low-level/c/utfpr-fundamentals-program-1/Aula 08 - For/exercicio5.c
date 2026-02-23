#include <stdio.h>
#include <stdlib.h>

/*
5) Faça um programa que calcule o fatorial de um número a ser
digitado.
*/

int main(){
    int num;
    int fatorial = 1;

    printf("Digite um número inteiro positivo para calcular o fatorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Fatorial não está definido para números negativos.\n");
    } else {
        for (int i = 1; i <= num; i++){
            fatorial *= i;
        }
        printf("O fatorial de %d é %d.\n", num, fatorial);
    }
    return 0;
}