#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
4) Considerando a estrutura atleta do exercício anterior, escreva
um programa que leia um arquivo binário contendo os dados de
cinco atletas. Calcule e exiba o nome do atleta mais alto e do
mais velho.
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
    printf("Digite o nome do arquivo para ler: ");
    fgets(nomeArquivo, 26, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")]='\0';
    strcat(path, nomeArquivo);
    strcat(path, ".bin");

    FILE *arquivo = fopen(path, "rb");
    if(arquivo == NULL){
        printf("Não foi possivel ler o arquivo.\n");
        return 1;
    }

    fread(atleta, sizeof(Atleta), 5, arquivo);

    fclose(arquivo);

    for(int i = 0; i < 5; i++){
        printf("Exibindo dados do %dº Atleta.\n", i+1);
        printf("Nome: %s\n", atleta[i].nome);
        printf("Esporte: %s\n", atleta[i].esporte);
        printf("Idade: %d\n", atleta[i].idade);
        printf("Altura: %.2f\n", atleta[i].altura);
        printf("----------------------\n\n");
    }

    return 0;
}

