#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
1) Escreva um programa que leia do usuário o nome de um arquivo
texto. Em seguida, mostre na tela quantas linhas esse arquivo possui
*/

int main(){
    char nomeArquivo[26];
    char path[40];
    char c;
    int linhas = 0;
    int temConteudo = 0;

    strcpy(path, "../arquivos/");

    printf("Digite o nome de um arquivo de texto: ");
    fgets(nomeArquivo, 26, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")]='\0';
    strcat(path, nomeArquivo);

    FILE *fp = fopen(path, "r");
    if(fp == NULL){
        printf("O arquivo não existe, ou não foi possível abrir.");
        return 1;
    }

    while((c = fgetc(fp)) != EOF){
        temConteudo = 1;
        if(c == '\n'){
            linhas++;
        }
    }
        
    if(temConteudo == 1){
        linhas++;
    }

    printf("O arquivo possui %d linhas.", linhas);
    fclose(fp);
    return 0;
}