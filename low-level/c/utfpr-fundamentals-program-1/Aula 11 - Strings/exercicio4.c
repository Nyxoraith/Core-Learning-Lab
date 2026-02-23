#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
4) Faça um programa que receba um nome, ele deve perguntar
novamente caso o nome tenha tamanho inferior a 5 caracteres. Ao receber
um nome com 5 caracteres ou mais o programa exibe o nome e finaliza.
*/

int main() {
    char name[21];
    
    do{
        printf("Digite um nome: ");
        fgets(name, 21, stdin);
        name[strcspn(name, "\n")]='\0';
        setbuf(stdin, NULL);
    }while(strlen(name) < 5);

    printf("Nome informado: %s\n", name);
    return 0;
}