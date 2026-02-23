#include <stdio.h>

/*
1) Crie uma função que retorne x*y através de operação de soma. A função recebe x e y por parâmetro
*/

int multiplicacao(int x, int y){
    if(y == 0){
        return 0;
    }
    return x + multiplicacao(x, y-1);
}

int main(){
    int resultado, x, y;

    printf("Digite uma multiplicação (5x5): ");
    scanf("%dx%d", &x, &y);

    resultado = multiplicacao(x, y);

    printf("O resultado entre %dx%d é: %d\n", x, y, resultado);

    return 0;
}