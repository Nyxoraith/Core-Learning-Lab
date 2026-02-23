#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
4) Crie um programa para calcular e exibir o número de palavras
contido em um arquivo texto. O usuário deverá informar o nome do
arquivo. 
*/

int main(){
    char c;
    char path[40];
    char nomeArquivo[26];
    int totalPalavras = 0;
    int temConteudo = 0;

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

    while((c = fgetc(arquivo)) != EOF){
        temConteudo = 1;
        if(isspace(c)){
            totalPalavras++;
        }
    }

    if(temConteudo == 1 ){
        totalPalavras++;
    }

    printf("O arquivo possui %d palavras", totalPalavras);
    return 0;
}