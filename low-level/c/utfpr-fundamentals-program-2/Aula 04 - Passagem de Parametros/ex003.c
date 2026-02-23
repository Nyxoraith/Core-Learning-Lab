#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
/*
3) 
Crie um Sistema de Gerenciamento de Bandas seguindo os seguintes passos:
a) Defina uma estrutura que irá representar bandas de música. Essa estrutura deve ter o nome da banda, que tipo de música ela toca, o número de integrantes e em que posição do ranking essa banda está dentre as suas 5 bandas favoritas;
b) Crie uma função para preencher as 5 estruturas de bandas criadas no exemplo passado. Após criar e preencher, exiba todas as informações das bandas/estruturas.
c) Crie uma função que peça ao usuário um número de 1 até 5. Em seguida, seu programa deve exibir informações da banda cuja posição no seu ranking é a que foi solicitada pelo usuário;
d) Crie uma função que peça ao usuário um tipo de música e exiba as bandas com esse tipo de música no seu ranking.
e) Crie uma função que peça o nome de uma banda ao usuário e diga se ela está entre suas bandas favoritas ou não;
f) Agora junte tudo e crie um menu com as opções de preencher as estruturas e todas as opções das questões passadas.
*/

typedef struct{
    char nome[26];
    char genero[26];
    int integrantes;
    int ranking;
}Banda;

void preencherDados(Banda *bandas, int tam){
    system("cls");
    for(int i = 0; i < tam; i++){
        printf("Digite o nome da banda: ");
        fgets(bandas[i].nome, 25, stdin);
        setbuf(stdin, NULL);
        bandas[i].nome[strcspn(bandas[i].nome, "\n")]='\0';

        printf("Digite o tipo de música: ");
        fgets(bandas[i].genero, 25, stdin);
        setbuf(stdin, NULL);
        bandas[i].genero[strcspn(bandas[i].genero, "\n")]='\0';

        printf("Digite quantos integrantes a banda possuí: ");
        scanf("%d", &bandas[i].integrantes);
        getchar();

        printf("Digite em qual posição do ranking a banda está entre seu top 5: ");
        scanf("%d", &bandas[i].ranking);
        getchar();
        printf("\n");
    }

    system("cls");
    printf("\nDados das bandas\n");
    for(int i = 0; i < tam; i++){
        printf("-------------------------\n");
        printf("Nome: %s\n", bandas[i].nome);
        printf("Tipo de Música: %s\n", bandas[i].genero);
        printf("Quantidade de Integrantes: %d\n", bandas[i].integrantes);
        printf("Posição do Ranking: %dº\n", bandas[i].ranking);
    }
    return;
}

void ranking(Banda *bandas, int tam){
    int ranking_banda;
    system("cls");
    printf("\nDigite um número entre 1 e 5 para exibir informações da banda: ");
    scanf("%d", &ranking_banda);

    if (ranking_banda < 1 || ranking_banda > 5) {
        printf("Por favor, digite um número válido entre 1 e 5.\n");
        Sleep(5000);
        return;
    }

    for(int i = 0; i < tam; i++){
        if(ranking_banda == bandas[i].ranking){
            printf("\nDados da banda\n");
            printf("-------------------------\n");
            printf("Nome: %s\n", bandas[i].nome);
            printf("Tipo de Música: %s\n", bandas[i].genero);
            printf("Quantidade de Integrantes: %d\n", bandas[i].integrantes);
            printf("Posição do Ranking: %dº\n", bandas[i].ranking);
        }
    }
    Sleep(5000);
    return;
}

void generoMusical(Banda *bandas, int tam){
    char genero[26];
    int encontrado = 0;

    system("cls");
    printf("\nDigite um tipo de de música: ");
    fgets(genero, 25, stdin);
    setbuf(stdin, NULL);
    genero[strcspn(genero, "\n")]='\0';

    for(int i = 0; i < tam; i++){
        if(strcmp(genero, bandas[i].genero) == 0){
            printf("\nDados da banda\n");
            printf("-------------------------\n");
            printf("Nome: %s\n", bandas[i].nome);
            printf("Tipo de Música: %s\n", bandas[i].genero);
            printf("Quantidade de Integrantes: %d\n", bandas[i].integrantes);
            printf("Posição do Ranking: %dº\n", bandas[i].ranking);
            encontrado = 1;
        }
    }

    if(!encontrado){
        printf("Nenhuma banda do gênero %s encontrada.\n", genero);
    }
    Sleep(5000);
}

void bandasFavoritas(Banda *bandas, int tam){
    char nomeBanda[26];
    int encontrado = 0;

    system("cls");
    printf("Digite o nome de uma banda: ");
    fgets(nomeBanda, 25, stdin);
    setbuf(stdin, NULL);
    nomeBanda[strcspn(nomeBanda, "\n")]='\0';

    for(int i = 0; i < tam; i++){
        if(strcmp(nomeBanda, bandas[i].nome) == 0){
            printf("Esta banda está entre suas bandas favoritas.\n");
            printf("\nDados da banda\n");
            printf("-------------------------\n");
            printf("Nome: %s\n", bandas[i].nome);
            printf("Tipo de Música: %s\n", bandas[i].genero);
            printf("Quantidade de Integrantes: %d\n", bandas[i].integrantes);
            printf("Posição do Ranking: %dº\n", bandas[i].ranking);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Esta banda não está entre suas bandas favoritas.\n");
    }
    Sleep(5000);
}

int main(){
    Banda bandas[5];
    int op;

    while(1){
        printf("Bem vindo ao SGDB - Sistema de Gerenciamento de Bandas\n");
        printf("------------------------------------------------------\n");
        printf("[1] Preencher dados das 5 bandas favoritas.\n");
        printf("[2] Visualizar informações de uma banda de acordo com o ranking.\n");
        printf("[3] Visualizar informações de uma banda de acordo com o estilo musical.\n");
        printf("[4] Verificar se uma banda está entre o ranking das bandas favoritas.\n");
        printf("[5] Sair.\n");
        printf("Digite uma opção válida: ");
        scanf("%d", &op);
        getchar();

        switch(op){
            case 1:
                preencherDados(bandas, 5);
                break;
            case 2:
                ranking(bandas, 5);
                break;
            case 3:
                generoMusical(bandas, 5);
                break;
            case 4:
                bandasFavoritas(bandas, 5);
                break;
            case 5:
                printf("Saindo...");
                Sleep(3000);
                return 0;
            default:
                printf("Por favor digite uma opção válida!\n");
        }
        system("cls");
    }

    return 0;
}