#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
6) Considerando a estrutura ranking do exercício anterior,
escreva um programa que leia o arquivo gerado contendo
os dados dos 5 jogadores.
*/

typedef struct{
    char nome[25];
    float pontuacao;
}Ranking;


int main(){
    Ranking jogadores[5];
    char path[40];
    char nomeArquivo[26];
    char label[26];

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

    for(int i = 0; i < 5; i++){
        fscanf(arquivo, "%s %24s\n", label, jogadores[i].nome);
        fscanf(arquivo, "%s %f\n", label, &jogadores[i].pontuacao);
    }

    fclose(arquivo);

    for(int i = 0; i < 5; i++){
        printf("Dados do %dº Jogador.\n", i+1);
        printf("Nome: %s\n", jogadores[i].nome);
        printf("Pontuação: %.2f\n", jogadores[i].pontuacao);
        printf("----------------------\n\n");
    }
    return 0;
}

