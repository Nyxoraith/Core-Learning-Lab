#include <stdio.h>
#include <stdlib.h>

/*
5) Faça um programa que receba um número real, calcule e
exiba o quadrado dele. O programa deverá repetir esse
procedimento para 10 números, um de cada vez.
*/

int main(){
    int c = 1;
    float num, quadrado;

    while (c <= 10){
        printf("Digite um numero para calcular o quadrado: ");
        scanf("%f", &num);
        quadrado = num * num;
        printf("O quadrado de %.2f é: %.2f\n", num, quadrado);
        c++;
    }
    
    return 0;
}