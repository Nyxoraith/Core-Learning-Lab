#include <stdio.h>
#include <stdlib.h>

/*
1) Faça um programa que receba a altura de uma pessoa e
calcule e exiba seu peso ideal utilizando a seguinte:
peso ideal = 72.7 x altura – 58
*/

int main(){
    float altura = 0;
    float peso_ideal = 0;
    printf("Digite sua altura: ");
    scanf("%f", &altura);
    printf("Sua altura é: %.2f\n", altura);
    peso_ideal = 72.7 * altura - 58;
    printf("O peso ideal para uma pessoa de %.2f de altura é: %.2f kg.\n", altura, peso_ideal);
    return 0;
}