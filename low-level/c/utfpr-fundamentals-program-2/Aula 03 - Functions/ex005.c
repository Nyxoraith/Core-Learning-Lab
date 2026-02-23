#include <stdio.h>

/*
5) Implemente uma função em C que receba um número inteiro positivo N como parâmetro e retorne o seu fatorial. O fatorial de N é definido como:

N! = N×(N−1)×(N−2)×...×1
Considere que 0! = 1.

Na função main, solicite ao usuário um valor para N, chame a função para calcular o fatorial e exiba o resultado na tela.
*/

int fatorial(int n){
    int resultado = 1;

    if (n == 0) return 1;

    for(int i = n; i > 0; i--){
        resultado *= i; 
    }
    
    return resultado;
}

int main(){
    int n, resultado;

    printf("Digite um valor para calcular o fatorial: ");
    scanf("%d", &n);


    if (n < 0) {
        printf("Não é possível calcular o fatorial de um número negativo.\n");
    } else {
        resultado = fatorial(n);
        printf("O fatorial de %d é: %d\n", n, resultado);
    }
    return 0;
}