#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp = fopen("teste2.txt", "r");
    char texto[50];

    if(fp == NULL){
        perror("Erro ao abrir o arquivo");
        exit(1);
    }

    //fputs(texto, fp);
    fgets(texto, 50, fp);
    
    printf("%s\n", texto);

    fclose(fp);
    return 0;
}