#include <stdio.h>
#include <stdlib.h>

/*
7) Faça um programa que calcule o fatorial de um número a ser
digitado.
*/

int main(){
    int num, fatorial = 1, contador = 1;

    printf("Digite um numero para calcular o fatorial: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Nao e possivel calcular o fatorial de numeros negativos.\n");
    } else {
        while (contador <= num){
            fatorial *= contador;
            contador++;
        }
        printf("O fatorial de %d é: %d\n", num, fatorial);
    }

    return 0;
}