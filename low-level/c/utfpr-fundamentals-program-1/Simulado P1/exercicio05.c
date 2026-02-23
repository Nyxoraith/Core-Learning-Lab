#include <stdio.h>
#include <stdlib.h>

/*
5) Faça um programa que receba 2 números referentes ao numerador e denominador de uma fração e informe se é uma fração própria, imprópria, ou aparente
*/

int main(){
    int numerador, denominador;

    printf("Digite o numerador: ");
    scanf("%d", &numerador);

    printf("Digite o denominador: ");
    scanf("%d", &denominador);

    if (denominador == 0) {
        printf("Erro: o denominador não pode ser zero.\n");
        return 1;
    }

    if (numerador == 0) {
        printf("A fração é aparente (fração resulta em 0).\n");
    } else if (numerador % denominador == 0) {
        printf("A fração é aparente (fração resulta em %d).\n", numerador / denominador);
    } else if (numerador < denominador) {
        printf("A fração é própria.\n");
    } else {
        printf("A fração é imprópria.\n");
    }

    return 0;
}