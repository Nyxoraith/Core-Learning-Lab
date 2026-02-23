#include <stdio.h>
#include <stdlib.h>

/*
3) Escreva uma função que receba como parâmetro dois vetores via referência( A e B)
e o tamanho N. A função deve retornar o ponteiro para um vetor C de tamanho N
alocado dinamicamente, em que:
C[i] = A[i] * B[i]
*/

int* vetorEscalar(int *vetA, int *vetB, int tamN);

int main(){
    int tamVet;

    printf("Digite o tamanho dos vetores: ");
    scanf("%d", &tamVet);

    int vetorA[tamVet];
    int vetorB[tamVet];
    
    printf("\nDigite o vetor A: \n");
    for(int i=0; i<tamVet; i++){
        printf("Digite o %dº valor: ", i+1);
        scanf("%d", &vetorA[i]);
    }

    printf("\nDigite o vetor B: \n");
    for(int i=0; i<tamVet; i++){
        printf("Digite o %dº valor: ", i+1);
        scanf("%d", &vetorB[i]);
    }
    
    int *vetorC = vetorEscalar(vetorA, vetorB, tamVet);
    if(vetorC == NULL){
        printf("Erro ao alocar o vetor");
        return 1;
    }
    
    printf("\nVetor A: ");
    for(int i = 0; i < tamVet; i++){
        printf("%d ", vetorA[i]);
    }

    printf("\nVetor B: ");
    for(int i = 0; i < tamVet; i++){
        printf("%d ", vetorB[i]);
    }

    printf("\nVetor C: ");
    for(int i = 0; i < tamVet; i++){
        printf("%d ", vetorC[i]);
    }

    free(vetorC);
    return 0;
}

int* vetorEscalar(int *vetA, int *vetB, int tamN){
    int *vetC;

    vetC = malloc(tamN * sizeof(int));
    if(vetC == NULL){
        return NULL;
    }

    for(int i = 0; i < tamN; i++){
        vetC[i] = vetA[i] * vetB[i];
    }

    return vetC;
}