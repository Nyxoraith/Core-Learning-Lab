#include <stdio.h>

/*
2) Crie uma função que retorne x elevado a y através de operação de multiplicação. A função recebe x e y por parâmetro
*/

int potenciacao(int x, int y){
    if(y == 0){
        return 1;
    }
    return x * potenciacao(x, y-1);
}

int main(){
    int resultado, x, y;

    printf("Digite uma potenciação (5^5): ");
    scanf("%d^%d", &x, &y);

    resultado = potenciacao(x, y);
    
    printf("O resultado de %d elevado a %d é: %d\n", x, y, resultado);

    return 0;
}