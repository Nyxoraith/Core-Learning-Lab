#include <stdio.h>
#include <stdlib.h>

/*
1) Sabendo-se que 200 quilowatts de energia custa um quarto do salário mínimo, 
faça um programa que receba o valor do salário mínimo
e a quantidade de quilowatts gasta por uma residência e mostre:
a) O valor em reais de cada quilowatt;
b) O valor em reais a ser pago pelos quilowatts gasto;
c) O novo valor a ser pago por essa residência com um desconto de 12%;
*/

int main(){
    float salario_minimo, qtd_quilowatts, valor_qwatts, total, total_desconto;

    printf("Digite o valor do salário mínimo: ");
    scanf("%f", &salario_minimo);
    
    printf("Digite a quantidade de quilowatts cosumidos: ");
    scanf("%f", &qtd_quilowatts);

    valor_qwatts = (salario_minimo / 4) / 200;

    total = valor_qwatts * qtd_quilowatts;

    total_desconto =  total * 0.88;

    printf("a) Valor de cada quilowatt: R$ %.2f\n", valor_qwatts);
    printf("b) Valor total a ser pago: R$ %.2f\n", total);
    printf("c) Valor com desconto de 12%%: R$ %.2f\n", total_desconto);

    return 0;
}