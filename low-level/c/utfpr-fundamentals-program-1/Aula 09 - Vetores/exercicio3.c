#include <stdio.h>
#include <stdlib.h>

/*
3) Leia um vetor A com 10 elementos inteiros correspondentes
as idades de um grupo de pessoas. Escreva um programa que
conte e exiba a quantidade de pessoas que possuem idade
superior a 35 anos.
*/

int main() {
    int A[10], contador = 0;

    printf("Digite as idades de 10 pessoas:\n");
    for (int i = 0; i < 10; i++) {
        printf("Idade da pessoa %d: ", i + 1);
        scanf("%d", &A[i]);

        if (A[i] > 35) {
            contador++;
        }
    }

    printf("\nQuantidade de pessoas com idade superior a 35: %d\n", contador);

    return 0;
}
