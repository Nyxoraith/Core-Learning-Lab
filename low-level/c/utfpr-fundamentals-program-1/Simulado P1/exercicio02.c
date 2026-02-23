#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
2) Fazer um programa para ler as coordenadas x e y de dois pontos e calcular a distância entre os dois pontos no plano, através da seguinte fórmula:
d=√(x2−x1)²+(y2−y1)²
*/

int main(){
    float x1, y1, x2, y2, distancia;

    printf("Digite as coordenadas do ponto 1 (x1 y1): ");
    scanf("%f %f", &x1, &y1);

    printf("Digite as coordenadas do ponto 2 (x2 y2): ");
    scanf("%f %f", &x2, &y2);

    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    printf("A distância entre os pontos é: %.2f\n", distancia);

    return 0;
}