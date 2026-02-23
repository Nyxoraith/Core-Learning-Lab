#include <stdio.h>
#include <math.h>
/*
1) Crie uma estrutura para representar as coordenadas de
um ponto no plano (posições X e Y). Em seguida, declare
e leia do teclado dois pontos e exiba a distância entre
eles. 
*/

//p1(4,6) p2(3,2)
//Raiz( (4-3)² + (6-2)² )
//Raiz(  (1)² + (4)²   )
//Raiz(   1    +   16   )
//Raiz(17)
//4.12

typedef struct {
    int x;
    int y;
}Ponto;

int main(){
    Ponto pontos[2];
    double distancia;

    for(int i = 0; i < 2; i++){
        printf("Digite a posição X do %dº ponto no plano: ", i+1);
        scanf("%d", &pontos[i].x);

        printf("Digite a posição Y do %dº ponto no plano: ", i+1);
        scanf("%d", &pontos[i].y);
    }

    for(int i = 0; i < 2; i++){
        printf("Posição X do ponto %dº: %d\n", i+1, pontos[i].x);
        printf("Posição Y do ponto %dº: %d\n", i+1, pontos[i].y);
    }

    distancia = sqrt(pow((pontos[0].x - pontos[1].x), 2) + pow((pontos[0].y - pontos[1].y), 2));

    printf("A distancia entre os dois pontos é de: %.2f\n", distancia);

    return 0;
}