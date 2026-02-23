#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/*
1) Faça um programa que gere 100 números aleatórios. Esse
programa deverá, em seguida,armazenar esses números em um
arquivo binário.
*/

int main(){
    int random[100];
    char path[40];
    char nomeArquivo[26];

    strcpy(path, "../arquivos/");
    printf("Digite o nome do arquivo para salvar: ");
    fgets(nomeArquivo, 26, stdin);
    nomeArquivo[strcspn(nomeArquivo, "\n")]='\0';
    strcat(path, nomeArquivo);
    strcat(path, ".bin");

    srand(time(NULL));
    for(int i = 0; i < 100; i++){
        random[i] = rand() % 100 + 1;
    }
    
    FILE *arquivo = fopen(path, "wb");
    if(arquivo == NULL){
        printf("Não foi possivel criar o arquivo.\n");
        return 1;
    }

    fwrite(random, sizeof(int), 100, arquivo);

    fclose(arquivo);
    return 0;
}