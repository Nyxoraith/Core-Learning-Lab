#include <stdio.h>
#include <string.h>

/*
2) Usando a estrutura “atleta” do exercício anterior, escreva um programa que leia os dados de cinco atletas e os exiba por ordem de idade, do mais velho para o mais novo.
Dica: Procure pelo algoritmo BubbleSort no Google
*/

typedef struct{
    char nome[26], esporte[26];
    int idade;
    float altura;

}Atleta;

int main(){
    Atleta atletas[5];

    for(int i = 0; i < 5; i++){
        printf("Digite o nome do %dº atleta: ", i+1);
        fgets(atletas[i].nome, 25, stdin);
        atletas[i].nome[strcspn(atletas[i].nome, "\n")]='\0';
        setbuf(stdin, NULL);

        printf("Digite o esporte do %dº atleta: ", i+1);
        fgets(atletas[i].esporte, 25, stdin);
        atletas[i].esporte[strcspn(atletas[i].esporte, "\n")]='\0';
        setbuf(stdin, NULL);

        printf("Digite a idade do %dº atleta: ", i+1);
        scanf("%d", &atletas[i].idade);
        getchar();

        printf("Digite a altura do %dº atleta: ", i+1);     
        scanf("%f", &atletas[i].altura);
        getchar();

        printf("\n");
    }


    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5 - i - 1; j++){
            if(atletas[j].idade < atletas[j+1].idade){
                Atleta temp[1];
                temp[j] = atletas[j];
                atletas[j] = atletas[j+1];
                atletas[j+1] = temp[j];
            }
        }
    }

    printf("\nAtletas ordenados por idade: \n");

    for(int i = 0; i < 5; i++){
        printf("Nome: %s\n", atletas[i].nome);
        printf("Esporte: %s\n", atletas[i].esporte);
        printf("Idade: %d\n", atletas[i].idade);
        printf("Altura: %.2f\n\n", atletas[i].altura);
    }

    return 0;
}