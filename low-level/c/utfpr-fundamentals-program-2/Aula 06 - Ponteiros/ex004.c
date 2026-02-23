#include <stdio.h>

/*
4) Crie um programa que contenha um vetor de inteiros de tamanho 5.
Utilizando aritmética de ponteiros, leia os dados do teclado e exiba seus
valores multiplicado por 2. Em seguida, exiba o endereço de memória das
posições que contém valores pares.
*/

int main(){
    int vetor[5];

    for(int i = 0; i < 5; i ++){
        printf("Digite o %d valor: ", i+1);
        scanf("%d", (vetor + i));
    }

    printf("\nExibindo vetor: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", *(vetor + i));
    }

    printf("\nExibindo vetor multiplicado por 2: ");
    for(int i = 0; i < 5; i++){
        printf("%d ", *(vetor + i) * 2);
    }

    printf("\nExibindo os endereços de memória dos valores pares\n");
    for(int i = 0; i < 5; i++){
        if((*(vetor + i)%2) == 0){
            printf("Valor: %d | Endereço: %p\n", *(vetor + i), vetor + i);
        }
    }

    return 0;
}