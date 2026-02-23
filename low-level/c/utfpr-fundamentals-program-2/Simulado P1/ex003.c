#include <stdio.h>

/*
3) Elabore uma função que receba como parâmetro um valor inteiro 
n e gere como saída um triângulo lateral formado por asteriscos 
conforme o exemplo a seguir, em que usamos n = 4
*/

void gerarTrianguloLateral(int n) {
    int i, j;

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }

    for (i = n - 1; i >= 1; i--) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

int main() {
    int n = 4;
    printf("Exemplo para n = %d:\n", n);
    gerarTrianguloLateral(n);

    return 0;
}