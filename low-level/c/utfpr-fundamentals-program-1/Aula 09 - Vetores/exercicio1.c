#include <stdio.h>
#include <stdlib.h>

/*
1) Faça um programa que leia e armazene dois vetores de
tamanho 5. Ao final o programa deve calcular e exibir o vetor
soma; 
*/

int main(){
    int vetor1[5], vetor2[5], soma_vetores[5];

    printf("-------\n");
    printf("Vetor 1\n");
    printf("-------\n");

    for(int i = 0; i < 5; i++){
        printf("Escreva o valor %d: ", i);
        scanf("%d", &vetor1[i]);
    }

    printf("\nVetor 1:");
    for(int i = 0; i < 5; i++){
        printf(" %d ", vetor1[i]);
    }

    printf("\n\n-------\n");
    printf("Vetor 2\n");
    printf("-------\n");

    for(int i = 0; i < 5; i++){
        printf("Escreva o valor %d: ", i);
        scanf("%d", &vetor2[i]);
    }

    printf("\nVetor 2:");
    for(int i = 0; i < 5; i++){
        
        printf(" %d ", vetor2[i]);
    }

    for(int i = 0; i < 5; i++){
        soma_vetores[i] = vetor1[i] + vetor2[i];
    }

    printf("\n\n-------\n");
    printf("Soma vetores\n");
    printf("-------\n");

    printf("\nVetor soma: ");
    for(int i = 0; i < 5; i++){
        printf(" %d ", soma_vetores[i]);
    }
    printf("\n");

    return 0;
}