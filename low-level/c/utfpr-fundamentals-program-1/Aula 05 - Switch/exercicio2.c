#include <stdio.h>
#include <stdlib.h>

/*
2) Crie uma calculadora usando a instrução switch, que
pergunte qual das operações básicas quer fazer (+, -, *
e /), em seguida peça os dois números e mostre o
resultado da operação matemática entre eles.
*/

int main(){
    char operacao;
    int num1, num2, resultado;
    printf("Digite qual operação você deseja realizar (| + | - | * | / |): ");
    scanf("%c", &operacao);

    switch (operacao){
        case '+':
            printf("Digite o primeiro número: ");
            scanf("%i", &num1);

            printf("Digite o segundo número: ");
            scanf("%i", &num2);

            resultado = num1 + num2;
            printf("O resultado da SOMA entre %i + %i é: %i\n", num1, num2, resultado);
            break;

        case '-':
            printf("Digite o primeiro número: ");
            scanf("%i", &num1);

            printf("Digite o segundo número: ");
            scanf("%i", &num2);
                
            resultado = num1 - num2;
            printf("O resultado da SUBTRAÇÃO entre %i - %i é: %i\n", num1, num2, resultado);
            break;
    
        case '*':
            printf("Digite o primeiro número: ");
            scanf("%i", &num1);

            printf("Digite o segundo número: ");
            scanf("%i", &num2);
                
            resultado = num1 * num2;
            printf("O resultado da MULTIPLICAÇÃO entre %i * %i é: %i\n", num1, num2, resultado);
            break;
        
        case '/':
            printf("Digite o primeiro número: ");
            scanf("%i", &num1);

            printf("Digite o segundo número: ");
            scanf("%i", &num2);
                
            resultado = num1 / num2;
            printf("O resultado da DIVISÃO entre %i / %i é: %i\n", num1, num2, resultado);
            break;

        default:
            printf("Opção Inválida");
            break;
    }
    return 0;
}