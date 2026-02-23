#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
Uma conta de caderneta de poupança foi aberta com um
depósito de R$ 500,00. Imagine que esta conta é remunerada
em 1% de juros ao mês. Qual será o valor da conta após três
meses?
Para calcular potência, deve-se colocar a biblioteca #include <math.h>
no começo do arquivo, e usar a função pow. Exemplo:
variavel = pow(base,expoente);
*/

int main(){
    float valorEmConta = 500.00;
    float taxa = 0.01;
    float juros = valorEmConta * pow(1 + taxa, 3);
    printf("O valor da conta após 3 meses será de: %.2f\n", juros);
    return 0;
}