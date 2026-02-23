#include <stdio.h>
#include <stdlib.h>

/*
11) Desenvolva um algoritmo que receba vários números no intervalo fechado de 1 a 1000. Ao receber um valor fora da faixa, o programa deverá exibir a soma dos números pares e o produto dos números ímpares e finalizar.
Obs: O valor fora da faixa utilizado para sair não deverá entrar na conta da soma nem do produto.
*/

int main() {
    int num, soma_pares = 0, produto_impares = 1;
    int primeiro_impar = 1;
    while (1) {
        printf("Digite um número entre 1 e 1000: ");
        scanf("%d", &num);

    
        if (num < 1 || num > 1000) {
            break; 
        }

        if (num % 2 == 0) {
            soma_pares += num;
        } else { 
            if (primeiro_impar) {
                produto_impares = num;
                primeiro_impar = 0;    
            } else {
                produto_impares *= num; 
            }
        }
    }
    printf("Soma dos números pares: %d\n", soma_pares);
    printf("Produto dos números ímpares: %d\n", produto_impares);

    return 0;
}
