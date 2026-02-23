#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = fopen("teste2.txt", "r");
    char c;
    char texto[50];
    int i = 0;

    if(fp == NULL){
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    while((c = fgetc(fp)) != EOF){
        texto[i++] = c;
    }

    fclose(fp);
    printf("%s", texto);
    return 0;
}