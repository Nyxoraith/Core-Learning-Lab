#include <stdio.h>
#include <stdlib.h>

/*
2) Faça um algoritmo que leia uma matriz 3 por 3 (3x3) e
retorna a soma dos elementos da sua diagonal principal e
da sua diagonal secundária;
*/

int main() {
    int matriz[3][3];
    int somaDiagonalPrincipal = 0, somaDiagonalSecundaria = 0;

    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for (int i = 0; i < 3; i++) {
        somaDiagonalPrincipal += matriz[i][i];          
        somaDiagonalSecundaria += matriz[i][2 - i]; 
    }

    printf("\nSoma da diagonal principal: %d\n", somaDiagonalPrincipal);
    printf("Soma da diagonal secundária: %d\n", somaDiagonalSecundaria);

    return 0;
}
