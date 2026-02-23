#include <stdio.h>
#include <stdlib.h>

/*
6) Faça um programa que receba 10 números e calcule o
quadrado desse número (um de cada vez).
*/

int main(){
    int num, quadrado = 0;

    for(int i = 1; i <= 10; i++){
        printf("Digite um valor apra calcular o quadrado: ");
        scanf("%d", &num);

        quadrado = num * num;
        printf("O quadrado de %d é %d.\n", num, quadrado);
    }
    return 0;
}