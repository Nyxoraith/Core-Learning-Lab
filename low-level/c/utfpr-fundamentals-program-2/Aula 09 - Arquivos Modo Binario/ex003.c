#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
3) Crie uma estrutura representando um atleta. Essa estrutura
deve conter o nome do atleta, seu esporte, idade e altura. Agora,
escreva um programa que leia os dados de cinco atletas e os
armazene em um arquivo binário.
*/

typedef struct{
    char nome[25];
    char esporte[25];
    int idade;
    float altura;
}Atleta;


int main(){
    Atleta atleta[5];
    char path[40];
    char nomeArquivo[26];

    strcpy(path, "../arquivos/");
    printf("Digite o nome do arquivo para escrever: ");
    fgets(nomeArquivo, 26, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")]='\0';
    strcat(path, nomeArquivo);
    strcat(path, ".bin");
    
    for(int i = 0; i < 5; i++){
        printf("Dados do %dº Atleta.\n", i+1);
        printf("Digite o nome: ");
        fgets(atleta[i].nome, 25, stdin);
        atleta[i].nome[strcspn(atleta[i].nome, "\n")]='\0';

        printf("Digite o esporte: ");
        fgets(atleta[i].esporte, 25, stdin);
        atleta[i].esporte[strcspn(atleta[i].esporte, "\n")]='\0';

        printf("Digite a idade: ");
        scanf("%d", &atleta[i].idade);
        getc(stdin);

        printf("Digite a altura: ");
        scanf("%f", &atleta[i].altura);
        getc(stdin);
        printf("----------------------\n\n");
    }

    FILE *arquivo = fopen(path, "wb");
    if(arquivo == NULL){
        printf("Não foi possivel criar o arquivo.\n");
        return 1;
    }

    fwrite(atleta, sizeof(Atleta), 5, arquivo);

    fclose(arquivo);

    return 0;
}