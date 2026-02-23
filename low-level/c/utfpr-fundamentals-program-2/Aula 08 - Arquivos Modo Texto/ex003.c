#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
3) Escreva um programa para converter o conteúdo de um arquivo
texto em caracteres maiúsculos. O programa deverá ler do usuário o
nome do arquivo a ser convertido e o nome do arquivo a ser salvo.
*/

int main(){
    char path[40];
    char nomeArquivo[26];
    char conteudo[100];
    char *resultadoLeitura;
    int resultadoEscrita;

    strcpy(path, "../arquivos/");

    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, 26, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")]='\0';
    strcat(path, nomeArquivo);
    strcat(path, ".txt");


    FILE *arquivo = fopen(path, "r");
    if(arquivo == NULL){
        printf("O arquivo não existe, ou não foi possível abrir.\n");
        return 1;
    }

    resultadoLeitura = fgets(conteudo, 100, arquivo);
    if(resultadoLeitura == NULL){
        printf("Erro ao ler o arquivo.\n");
        return 1;
    }

    for(int i = 0; i < strlen(conteudo); i++){
        conteudo[i] = toupper(conteudo[i]);
    }

    strcpy(path, "../arquivos/");
    strcat(path, nomeArquivo);
    strcat(path, "Convertido.txt");

    FILE *arquivoConvertido = fopen(path, "w");
    if(arquivoConvertido == NULL){
        printf("O arquivo não existe, ou não foi possível abrir.\n");
        return 1;
    }

    resultadoEscrita = fputs(conteudo, arquivoConvertido);
    if(resultadoEscrita == EOF){
        printf("Erro na gravação do arquivo!\n");
        return 1;
    }

    printf("Arquivo gravado com sucesso!\n");

    fclose(arquivo);
    fclose(arquivoConvertido);
    return 0;
}