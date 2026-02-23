#include <stdio.h>
#include <stdlib.h>

/*
2) Escreva uma função que receba um valor inteiro positivo N por parâmetro e retorne
o ponteiro para um vetor de tamanho N alocado dinamicamente. Se N for negativo ou
igual a zero, um ponteiro nulo deverá ser retornado.
*/
int* retornaPonteiro(int n);

int main(){
    int n;
    printf("Digite o valor de N: ");
    scanf("%d", &n);

    int *ptrVet = retornaPonteiro(n);
    if(ptrVet != NULL){
        for(int i = 0; i < n; i++){
            printf("Digite o %dº valor: ", i+1);
            scanf("%d", &ptrVet[i]);
        }
    }else{
        printf("O ponteiro nulo retornado\n");
        return 1;
    }

    printf("Vetor: ");
    for(int i = 0; i < n; i++){
        printf("%d ", ptrVet[i]);
    }

    free(ptrVet);
    return 0;
}

int* retornaPonteiro(int n){
    if(n <= 0){
        return NULL;
    }
    int *vetor;

    vetor = malloc(n * sizeof(int));
    if(vetor == NULL){
        printf("Erro ao alocar vetor!\n");
        exit(1);
    }

    return vetor;
}