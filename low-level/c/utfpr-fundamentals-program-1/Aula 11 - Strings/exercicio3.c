#include <stdio.h>
#include <stdlib.h>

/*
3) Desenvolva um programa que armazene o nome e o
telefone de 5 pessoas. Ao digitar a posição desejada, o
programa deve exibir o nome e telefone daquela posição. O
programa finaliza ao receber a entrada -1.
*/

int main() {
    char nomes[5][50];
    char telefones[5][15];
    int posicao;

    for (int i = 0; i < 5; i++) {
        printf("Digite o nome da pessoa %d: ", i + 1);
        fgets(nomes[i], 50, stdin);

        printf("Digite o telefone da pessoa %d: ", i + 1);
        fgets(telefones[i], 15, stdin);
    }

    while (1) {
        printf("\nDigite a posição desejada (1 a %d, ou -1 para sair): ", 5);
        scanf("%d", &posicao);

        if (posicao == -1) {
            printf("Encerrando o programa.\n");
            break;
        }

        if (posicao >= 1 && posicao <= 5) {
            printf("Nome: %s", nomes[posicao - 1]);
            printf("Telefone: %s", telefones[posicao - 1]);
        } else {
            printf("Posição inválida! Tente novamente.\n");
        }
    }

    return 0;
}