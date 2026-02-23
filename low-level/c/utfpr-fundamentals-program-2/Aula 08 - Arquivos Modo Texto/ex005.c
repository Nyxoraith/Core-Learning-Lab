#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
5) Elabore um programa para calcular e exibir o número de
vezes que cada letra ocorre dentro de um arquivo texto.
Ignore as letras com acento. O usuário deverá informar o
nome do arquivo.
*/

int main(){
    char c;
    char path[40];
    char nomeArquivo[26];
    int contagem[26] = {0};

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
        c = tolower(c);

        if(c >= 'a' && c <= 'z'){
            contagem[c - 'a']++;
        }

    }

    for (int i = 0; i < 26; i++) {
        if (contagem[i] > 0) {
            printf("'%c': %d vez(es)\n", 'a' + i, contagem[i]);
        }
    }

    fclose(arquivo);
    return 0;
}