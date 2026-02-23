#include <stdio.h>
#include <stdlib.h>

/*
Faça um programa que mostre n elementos da sequência de
Fibonacci.
 O valor de n é passado para o programa.
 O primeiro termo é 0, e o segundo termo é 1, os demais devem seguir a
fórmula t
n = tn-1 + tn-2
*/

int main() {
    int n, t1 = 0, t2 = 1, prox_term;

    do {
        printf("Digite quantos elementos terá a sequência de Fibonacci: ");
        scanf("%d", &n);
    } while (n < 1);

    printf("Sequência de Fibonacci com %d termos:\n", n);

    if (n >= 1) printf("%d ", t1);
    if (n >= 2) printf("%d ", t2); 

    for (int i = 3; i <= n; i++) { 
        prox_term = t1 + t2;
        printf("%d ", prox_term);
        t1 = t2;     
        t2 = prox_term;
    }

    printf("\n");
    return 0;
}