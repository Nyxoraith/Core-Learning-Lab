#include <stdio.h>
#include <stdlib.h>

/*
6) Faça um programa que receba e armazene 20 números em
um vetor. Em seguida exiba:
 Quantos números são iguais a 30;
 Quantos números são maior que a média;
 Quantos números são iguais à media;
*/

int main(){
    int vetor[20], soma = 0, iguais_30 = 0, maiores_media = 0, iguais_media = 0;
    int media;

    for (int i = 0; i < 20; i++) {
        printf("Digite o %dº número: ", i + 1);
        scanf("%d", &vetor[i]);
        soma += vetor[i];
    }

    media = soma / 20;

    for (int i = 0; i < 20; i++) {
        if (vetor[i] == 30) {
            iguais_30++;
        }
        if (vetor[i] > media) {
            maiores_media++;
        }
        if (vetor[i] == media) {
            iguais_media++;
        }
    }

    printf("\nResultado:\n");
    printf("Números iguais a 30: %d\n", iguais_30);
    printf("Números maiores que a média: %d\n", maiores_media);
    printf("Números iguais à média: %d\n", iguais_media);

    return 0;
}