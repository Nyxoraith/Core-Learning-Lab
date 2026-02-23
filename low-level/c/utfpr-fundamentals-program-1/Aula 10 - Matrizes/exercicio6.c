#include <stdio.h>
#include <stdlib.h>

/*
6 ) Faça um programa que multiplique as matrizes A e D
abaixo gerando matriz AD 
*/

#include <stdio.h>

int main() {
    int A[2][3], D[3][2], AD[2][2]; 

    printf("Digite os elementos da matriz A (2x3):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\nDigite os elementos da matriz D (3x2):\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            printf("D[%d][%d]: ", i, j);
            scanf("%d", &D[i][j]);
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            AD[i][j] = 0;
        }
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 3; k++) { 
                AD[i][j] += A[i][k] * D[k][j];
            }
        }
    }

    printf("\nMatriz AD (A * D):\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", AD[i][j]);
        }
        printf("\n");
    }

    return 0;
}
