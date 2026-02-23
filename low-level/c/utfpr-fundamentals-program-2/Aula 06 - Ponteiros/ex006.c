#include <stdio.h>

/*
6) Considere a seguinte declaração:
int a, *b, **c, ***d;
Escreva um programa que receba o valor de a, calcule e exiba:
O dobro do valor a, utilizando o ponteiro b
O triplo do valor a, utilizando o ponteiro c
O quadruplo do valor a, utilizando o ponteiro d
*/

int main(){
    int a, *b, **c, ***d;
    int dobro_a, triplo_a, quadruplo_a;

    printf("Digite o valor de a: ");
    scanf("%d", &a);

    b = &a;
    c = &b;
    d = &c;

    dobro_a = (*b) * 2;
    triplo_a = (**c) * 3;
    quadruplo_a = (***d) * 4;

    printf("O dobro de %d é: %d\n", a, dobro_a);
    printf("O triplo de %d é: %d\n", a, triplo_a);
    printf("O quadruplo de %d é: %d\n", a, quadruplo_a);

    return 0;
}