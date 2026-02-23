#include <stdio.h>
#include <stdlib.h>

/*
2) Faça um programa que receba um número e determine
se ele é um número par ou ímpar.
- Obs.: Utilize o operador % que retorna o resto da divisão)
*/

int main(){
    int numero = 0;
    int resto_divisao = 0;

    printf("Digite um numero: ");
    scanf("%i", &numero);
 
    resto_divisao = numero % 2;

    if(resto_divisao == 0){
        printf("O numero %i é par\n", numero);
    }else{
        printf("O numero %i é impar\n", numero);
    }

    return 0;
}