#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
2) Escreva um programa que leia do usuário os nomes de dois
arquivos texto. Crie um terceiro arquivo texto com o conteúdo dos
dois primeiros juntos (o conteúdo do primeiro seguido do conteúdo do
segundo).
*/

int main(){
    char path[40];
    char nomeArqUm[26];
    char textoArqUm[100];
    char nomeArqDois[26];
    char textoArqDois[100];
    char *nomeArqTres = "../arquivos/arquivoTres.txt";
    char textoArqTres[100];
    char *resultadoLeitura;
    int resultadoEscrita;

    strcpy(path, "../arquivos/");
    printf("Digite o nome do primeiro arquivo: ");
    fgets(nomeArqUm, 26, stdin);
    nomeArqUm[strcspn(nomeArqUm, "\n")]='\0';
    strcat(path, nomeArqUm);
   
    FILE *arqUm = fopen(path, "r");
    if(arqUm == NULL){
        printf("O arquivo não existe, ou não foi possível abrir.");
        return 1;
    }

    strcpy(path, "../arquivos/");
    printf("Digite o nome do segundo arquivo: ");
    fgets(nomeArqDois, 26, stdin);
    nomeArqDois[strcspn(nomeArqDois, "\n")]='\0';
    strcat(path, nomeArqDois);

    FILE *arqDois = fopen(path, "r");
    if(arqDois == NULL){
        printf("O arquivo não existe, ou não foi possível abrir.");
        return 1;

    }

    FILE *arqTres = fopen(nomeArqTres, "w");
    if(arqDois == NULL){
        printf("Não foi possível criar o arquivo.");
    }

    resultadoLeitura = fgets(textoArqUm, 100, arqUm);
    if(resultadoLeitura == NULL){
        printf("Erro na leitura!\n");
        return 1;   
    }
    
    resultadoLeitura = fgets(textoArqDois, 100, arqDois);
    if(resultadoLeitura == NULL){
        printf("Erro na leitura!\n");
        return 1;
    }

    strcpy(textoArqTres, textoArqUm);
    strcat(textoArqTres, "\n");
    strcat(textoArqTres, textoArqDois);

    resultadoEscrita = fputs(textoArqTres, arqTres);
    if(resultadoEscrita == EOF){
        printf("Erro na gravação!\n");
        return 1;
    }

    printf("Arquivo gravado com sucesso!\n");
    
    fclose(arqUm);
    fclose(arqDois);
    fclose(arqTres);
    return 0;
}