#include <stdio.h>
#include <stdlib.h>

/*
1) Crie um programa para armazenar 10 nomes em um vetor
e imprimir uma lista numerada
*/

int main(){
    char listaNomes[10][20];

    for(int i = 0; i < 10; i++){
        printf("Digite o %dº nome: ", i+1);
        fgets(listaNomes[i], 20, stdin);
    }

    printf("Lista de nomes:\n");
    for(int c = 0; c < 10; c++){
        printf("%dº %s", c+1, listaNomes[c]);
    }
    return 0;
}