#include <stdio.h>
#include <stdlib.h>

/*
8) Faça um menu que mostre 3 opções
Menu do programa:
1 - Teste 1
2 - Teste 2
3 – Sair do programa
Digite sua opção:
 A primeira opção imprime o texto “Teste1” e mostra o menu novamente.
 A segunda opção imprime “Teste2” e mostra o menu novamente.
 A terceira opção finaliza o programa.
 Caso digite uma opção diferente, deve mostrar uma mensagem de erro e
mostrar o menu novamente
*/

int main() {
    int opcao;

    while (1) {
        printf("Menu do programa:\n");
        printf("1 - Teste 1\n");
        printf("2 - Teste 2\n");
        printf("3 - Sair do programa\n");
        printf("Digite sua opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Teste1\n");
                break;
            case 2:
                printf("Teste2\n");
                break;
            case 3:
                printf("Saindo do programa...\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                break;
        }
    }
    return 0;
}