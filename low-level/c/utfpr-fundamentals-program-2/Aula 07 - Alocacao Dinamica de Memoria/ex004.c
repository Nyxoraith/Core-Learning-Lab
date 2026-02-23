#include <stdio.h>
#include <stdlib.h>

/*
4) Escreva uma função que receba como parâmetro um valor L e um valor C e retorne
o ponteiro para uma matriz alocada dinamicamente contendo L linhas e C colunas.
Essa matriz deve ser inicializada com o valor 0 em todas as suas posições.
*/

int** retornaMatriz(int linhas, int colunas);

int main(){
    int l, c;
    int **matriz;

    printf("Digite o numero de linhas: ");
    scanf("%d", &l);

    printf("Digite o numero de colunas: ");
    scanf("%d", &c);

    matriz = retornaMatriz(l, c);

    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }


     for(int i = 0; i < l; i++) {
        free(matriz[i]);
    }
    free(matriz);
    return 0;
}

int** retornaMatriz(int linhas, int colunas){
    int **matriz = calloc(linhas, sizeof(int));
    if(matriz == NULL){
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
    for(int i=0; i<linhas; i++){
        matriz[i] = calloc(colunas, sizeof(int));
    }

    return matriz;
}