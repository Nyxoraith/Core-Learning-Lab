#include <stdio.h>
#include <stdlib.h>

/*
Altere o exercício anterior para receber os 3 valores no
mesmo scanf.
Exemplo:
Digite a conta a ser realizada: 5+8
O resultado é: 13
*/

int main(){
    char operacao;
    int num1, num2, resultado;
    printf("Digite a conta a ser realizada: ");
    scanf("%i%c%i", &num1, &operacao, &num2);

    switch (operacao){
        case '+':
            resultado = num1 + num2;
            printf("O resultado da SOMA entre %i + %i é: %i\n", num1, num2, resultado);
            break;

        case '-':    
            resultado = num1 - num2;
            printf("O resultado da SUBTRAÇÃO entre %i - %i é: %i\n", num1, num2, resultado);
            break;
    
        case '*':  
            resultado = num1 * num2;
            printf("O resultado da MULTIPLICAÇÃO entre %i * %i é: %i\n", num1, num2, resultado);
            break;
        
        case '/': 
            resultado = num1 / num2;
            printf("O resultado da DIVISÃO entre %i / %i é: %i\n", num1, num2, resultado);
            break;

        default:
            printf("Opção Inválida");
            break;
    }
    return 0;
}