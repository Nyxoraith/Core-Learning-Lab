#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
5) Crie uma estrutura representando um ranking. Essa
estrutura deve conter o nome do jogador e sua pontuação.
Em seguida, escreva um programa que leia os dados de 5
jogadores e os armazene em um arquivo utilizando a
técnica de Dados formatados.
*/

typedef struct{
    char nome[25];
    float pontuacao;
}Ranking;


int main(){
    Ranking jogadores[5];
    char path[40];
    char nomeArquivo[26];

    strcpy(path, "../arquivos/");
    printf("Digite o nome do arquivo para escrever: ");
    fgets(nomeArquivo, 26, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")]='\0';
    strcat(path, nomeArquivo);
    strcat(path, ".bin");
    
    for(int i = 0; i < 5; i++){
        printf("Dados do %dº Jogador.\n", i+1);
        printf("Digite o nome: ");
        fgets(jogadores[i].nome, 25, stdin);
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")]='\0';

        printf("Digite a pontuação: ");
        scanf("%f", &jogadores[i].pontuacao);
        getc(stdin);
        printf("----------------------\n\n");
    }

    FILE *arquivo = fopen(path, "wb");
    if(arquivo == NULL){
        printf("Não foi possivel criar o arquivo.\n");
        return 1;
    }

    for(int i = 0; i < 5; i++){
        fprintf(arquivo, "Nome: %s\n", jogadores[i].nome);
        fprintf(arquivo, "Pontuação: %.2f\n", jogadores[i].pontuacao);
    }

    fclose(arquivo);
    return 0;
}

