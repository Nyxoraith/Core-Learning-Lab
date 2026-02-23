#include <stdio.h>
#include <stdlib.h>

int main() {
    float a, b, c;

    printf("Digite os três lados do triângulo:\n");
    scanf("%f %f %f", &a, &b, &c);

    if (a + b > c && a + c > b && b + c > a) {
        printf("Os valores formam um triângulo.\n");

        if (a == b && b == c) {
            printf("Triângulo equilátero.\n");
        } else if (a == b || a == c || b == c) {
            printf("Triângulo isósceles.\n");
        } else {
            printf("Triângulo escaleno.\n");
        }

        //Teorema de Pitágoras
        if ((a * a == b * b + c * c) || 
            (b * b == a * a + c * c) || 
            (c * c == a * a + b * b)) {
            printf("Triângulo retângulo.\n");
        }
    } else {
        printf("Os valores não formam um triângulo.\n");
    }

    return 0;
}