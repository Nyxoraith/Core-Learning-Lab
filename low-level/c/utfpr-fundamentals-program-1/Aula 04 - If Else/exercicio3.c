#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
3) Faça um programa que receba os coeficientes a, b e c
de uma equação do segundo grau e retorne as raízes da
equação (se existirem).
- Para isso, lembre-se da fórmula de Báskara:
*/

int main(){
    float a, b, c;
    float delta, raiz1, raiz2;

    printf("Digite o coeficiente a: ");
    scanf("%f", &a);
    printf("Digite o coeficiente b: ");
    scanf("%f", &b);
    printf("Digite o coeficiente c: ");
    scanf("%f", &c);

    if (a == 0) {
        printf("O valor de 'a' deve ser diferente de 0 para ser uma equação do segundo grau.\n");
        return 1;
    }

    // Calcula o delta (b^2 - 4ac)
    delta = b * b - 4 * a * c;

    // Verificar as condições de existência das raízes
    if (delta > 0) {
        // Duas raízes reais e diferentes
        raiz1 = (-b + sqrt(delta)) / (2 * a);
        raiz2 = (-b - sqrt(delta)) / (2 * a);
        printf("As raízes da equação são: %.2f e %.2f\n", raiz1, raiz2);
    } else if (delta == 0) {
        // Uma raiz real e única
        raiz1 = -b / (2 * a);
        printf("A equação possui uma raiz única: %.2f\n", raiz1);
    } else {
        // Delta < 0, não existem raízes reais
        printf("A equação não possui raízes reais.\n");
    }

    return 0;
}