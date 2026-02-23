#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
6) Faça um programa que receba um nome e um sobrenome. Ele deve
construir uma nova string no formato americano (Sobrenome, Nome)
Exemplo: Silva, José*/

int main(){
    char nome[25];
    char sobrenome[25];
    char nomeCompleto [50];

    printf("Digite seu nome: ");
    fgets(nome, 25, stdin);
    nome[strcspn(nome, "\n")]='\0';
    setbuf(stdin, NULL);

    printf("Digite seu sobrenome: ");
    fgets(sobrenome, 25, stdin);
    sobrenome[strcspn(sobrenome, "\n")]='\0';
    setbuf(stdin, NULL);

    strcpy(nomeCompleto, sobrenome);
    strcat(nomeCompleto, ", ");
    strcat(nomeCompleto, nome);
    
    printf("Nome Americano: %s\n", nomeCompleto);
    
    return 0;
}