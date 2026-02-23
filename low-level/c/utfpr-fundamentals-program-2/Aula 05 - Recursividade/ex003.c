#include <stdio.h>

/*
3) Crie uma função que retorne o fatorial de um número passado por parâmetro.
fatorial(n): 
=1 se n=0
= n x fatorial (n-1) se n>0
*/

int fatorial(int n){
    if(n == 0){
        return 1;
    }
    return n * fatorial(n-1);
}

int main(){
    int resultado, n;

    printf("Digite um valor para calcular o fatorial: ");
    scanf("%d", &n);

    if(n >= 0){
        resultado = fatorial(n);
        printf("O resultado do fatorial de %d é: %d\n", n, resultado);
    }   
    

    return 0;
}