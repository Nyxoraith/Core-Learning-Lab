#include <stdio.h>
#include <stdlib.h>

/*
5)Dado dois vetores, A (4 elementos) e B (5 elementos), faça
um programa em C que imprima todos os elementos comuns
aos dois vetores.
*/

int main(){
    int vetorA[4], vetorB[5];

    printf("Vetor A\n");
    for(int i = 0; i < 4; i++){
        printf("Digite o %d valor: ", i+1);
        scanf("%d", &vetorA[i]);
    }

    printf("\nVetor B\n");
    for(int c = 0; c < 5; c++){
        printf("Digite o %d valor: ", c+1);
        scanf("%d", &vetorB[c]);     
    }

    printf("Vetor A: ");
    for(int i = 0; i < 4; i++){
        printf(" %d ", vetorA[i]);
    }

    printf("\nVetor B: ");
    for(int c = 0; c < 5; c++){
        printf(" %d ", vetorB[c]);
    }

    printf("\nElementos em comum:");
    for(int i = 0; i < 4; i++){
        for(int c = 0; c < 5; c++)
            if (vetorA[i] == vetorB[c]){
                printf(" %d ", vetorA[i]);
            }
    }
    printf("\n");
    
    return 0;
}