#include <stdio.h>
#include <stdlib.h>

/*
2) Crie um algoritmo que receba 10 números e os armazene em
um vetor A. Em seguida, gere o vetor B onde cada elemento é o
quadrado do valor da mesma posição no vetor A
*/

int main() {
    int A[10], B[10];

    printf("Digite 10 números para preencher o vetor A:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < 10; i++) {
        B[i] = A[i] * A[i];
    }

    printf("\nVetor A: [");
    for (int i = 0; i < 10; i++) {
        printf("%d", A[i]);
        if (i < 9) printf(", ");
    }
    printf("]\n");

    printf("Vetor B (quadrados): [");
    for (int i = 0; i < 10; i++) {
        printf("%d", B[i]);
        if (i < 9) printf(", ");
    }
    printf("]\n");

    return 0;
}
