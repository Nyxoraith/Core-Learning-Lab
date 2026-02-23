#include <stdio.h>
#include <stdlib.h>

/*
1) Elabore um programa que leia do usuário o tamanho de um vetor a ser lido. Em
seguida, faça a alocação dinâmica desse vetor. Por fim, leia o vetor do usuário e o
imprima.
*/

int main(){
    int tamVet;
    int *vetor;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamVet);

    if(tamVet >= 1){
        
        vetor = malloc(tamVet * sizeof(int));
        if(vetor == NULL){
            printf("Erro ao alocar memória!\n");
            exit(1);
        }

        for(int i = 0; i < tamVet; i++){
            printf("Digite o %dº valor: ", i+1);
            scanf("%d", (vetor + i));
        }
    }else{
        printf("Digite um tamanho válido!\n");
        return 1;
    }

    for(int i = 0; i < tamVet; i++){
        printf("%dº valor: %d\n", i + 1, *(vetor + i));
    }

    free(vetor);
}