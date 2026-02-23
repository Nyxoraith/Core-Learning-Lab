#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

/*
6) Elabore um programa no qual o usuário informe o nome
de um arquivo texto e uma palavra, e o programa informe o
número de vezes que aquela palavra aparece
*/

int main(){
    char path[40];
    char nomeArquivo[26];
    char texto[255];
    char palavra[30];
    char *token;
    int contagem = 0;


    strcpy(path, "../arquivos/");
    printf("Digite o nome do arquivo: ");
    fgets(nomeArquivo, 26, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")]='\0';
    strcat(path, nomeArquivo);
    strcat(path, ".txt");

    printf("Informe a palavra a ser buscada no arquivo: ");
    fgets(palavra, 30, stdin);
    palavra[strcspn(palavra, "\n")]='\0';

    FILE *arquivo = fopen(path, "r");
    if (arquivo == NULL){
        printf("O arquivo não existe, ou não foi possível abrir.\n");
        return 1;
    }

    fgets(texto, 255, arquivo);

    token = strtok(texto, " ");

    while(token != NULL){
        if(strcmp(token, palavra) == 0){
            contagem++;
        }

        token = strtok(NULL, " ");
    }
    
    fclose(arquivo);
    
    printf("%d", contagem);

    return 0;
}