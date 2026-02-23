#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
5) Sabendo que a função sqrt(valor), que está na biblioteca
math.h retorna a raiz quadrada do valor, calcule a raiz
quadrada de um número que o usuário digitar.
*/

int main(){
    double raiz, resultado;
    printf("Digite um valor para calcular a raiz quadrada: ");
    scanf("%lf", &raiz);
    resultado = sqrt(raiz);
    printf("O resultado da raiz de %.2lf é: %.3lf\n", raiz, resultado);
    return 0;
}