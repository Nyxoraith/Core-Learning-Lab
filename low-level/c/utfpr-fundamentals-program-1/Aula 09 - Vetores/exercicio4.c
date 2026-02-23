#include <stdio.h>
#include <stdlib.h>

/*
4) Crie e inicialize um vetor de inteiros de tamanho 8. Faça a
soma dos seus elementos, e apresente o resultado. 
*/

int main(){
    int vetor[8];
    int soma_vetor = 0;

    for(int i = 0; i < 8; i++){
        printf("Digite o %d valor: ", i)+1;
        scanf("%d", &vetor[i]);
    }

    for (int c = 0; c <= 8; c++){
        soma_vetor += vetor[c];
    }
    
    printf("A soma de todos os elementos do vetor é: %d\n", soma_vetor);

    return 0;
}