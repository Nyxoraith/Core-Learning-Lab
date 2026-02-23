#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
2) Elabore um programa que leia um arquivo binário contendo
100 números. Mostre na tela a soma desses números.
*/

int main(){
    int random[100];
    int soma = 0;
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

    fread(random, sizeof(int), 100, arquivo);

    for(int i = 0; i < 100; i++){
        soma += random[i];
    }
    
    printf("A soma de todos os números aleatórios do arquivo binário é: %d\n", soma);
    fclose(arquivo);
    return 0;