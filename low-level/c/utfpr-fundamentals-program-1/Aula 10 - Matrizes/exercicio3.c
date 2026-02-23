#include <stdio.h>
#include <stdlib.h>

/*
3) Construa um programa que leia uma matriz de tamanho
5 x 5 e escreva:
 O valor e a localização (linha, coluna) do maior valor encontrado
na matriz.
*/

int main(){
    int matriz[5][5];
    int maiorValor, linhaMaior, colunaMaior;

    printf("Digite os elementos da matriz 5x5:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    maiorValor = matriz[0][0];
    linhaMaior = 0;
    colunaMaior = 0;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matriz[i][j] > maiorValor) {
                maiorValor = matriz[i][j];
                linhaMaior = i;
                colunaMaior = j;
            }
        }
    }

    printf("\nMaior valor: %d\n", maiorValor);
    printf("Localizado na linha %d, coluna %d\n", linhaMaior, colunaMaior);
    return 0;
}