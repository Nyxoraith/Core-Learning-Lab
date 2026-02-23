#include <stdio.h>
#include <stdlib.h>

//1) Crie uma matriz identidade com dimensões 5 x 5;

int main(){
    int matrizIdentidade[5][5];


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i == j) {
                matrizIdentidade[i][j] = 1; 
            } else {
                matrizIdentidade[i][j] = 0;
            }
        }
    }

    printf("Matriz Identidade 5x5:\n");
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d ", matrizIdentidade[i][j]);
        }
        printf("\n");
    }
    return 0;
}