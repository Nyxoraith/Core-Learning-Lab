#include <stdio.h>

/*
3) Crie um programa que contenha uma matriz (3x3) de float. Imprima o
endereço de cada posição dessa matriz.
*/

int main(){
    float matriz[3][3];

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Linha[%d] | Coluna[%d] | Digite o valor: ", i+1, j+1);
            scanf("%f", &matriz[i][j]);
        }
    }

    printf("\n--------Matriz--------\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%.1f ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\n--------Endereço de cada posição--------\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("Linha[%d] | Coluna[%d] | Endereço: %p\n", i+1, j+1, &matriz[i][j]);
        }
    }
    return 0;
}