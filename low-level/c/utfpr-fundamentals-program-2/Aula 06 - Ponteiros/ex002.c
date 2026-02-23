#include <stdio.h>

/*
2) Crie um programa que contenha um vetor float (tamanho 10). Imprima o
endereço de cada posição desse vetor.
*/

int main(){
    float vetor[10];

    for(int i = 0; i < 10; i++){
        printf("Digite o %dº valor: ", i+1);
        scanf("%f", &vetor[i]);
    }

    printf("\n\n--------Valores em cada posição--------\n");
    for(int i = 0; i < 10; i++){
        printf("Posição %dº | Valor: %.2f\n", i+1, vetor[i]);
    }

    printf("\n\n--------Endereço de cada posição--------\n");
    for(int i = 0; i < 10; i++){
        printf("Posição %dº | Endereço: %p\n", i+1, &vetor[i]);
    }

    return 0;
}