#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
13) Faça um programa que verifique se um número dado via teclado é primo.
Dica: para saber se um número n é primo, basta dividir por cada um dos números entre 2 e raiz quadrada de n; se o resto for diferente de zero pra todos ele é primo.
*/

int main() {
    int numero;
    int is_prime = 1; 

    printf("Digite um número: ");
    scanf("%d", &numero);

    if (numero <= 1) {
        is_prime = 0;  
    } else {
        int limite = (int)sqrt(numero);
        for (int i = 2; i <= limite; i++) {
            if (numero % i == 0) {
                is_prime = 0; 
                break;
            }
        }
    }

    if (is_prime) {
        printf("%d é um número primo.\n", numero);
    } else {
        printf("%d não é um número primo.\n", numero);
    }

    return 0;
}