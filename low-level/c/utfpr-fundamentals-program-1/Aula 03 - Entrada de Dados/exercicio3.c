#include <stdio.h>
#include <stdlib.h>

/*
3) Tendo como entrada de dados o total vendido por um
funcionário no mês, calcule a sua comissão e o salário bruto no
mês. Para isso, considere um salário base de R$1.200,00 e
comissão de 10% sobre o total vendido.
*/

int main(){
    float total_vendido, comissao_recebida, total_recebido;
    float salario = 1200.00;
    float comissao_taxa = 0.10;
    
    printf("Salario: R$ %.2f\n", salario);
    printf("Taxa comissão sobre o total vendido: %.2f\n", comissao_taxa);
    printf("--------------------\n");
    
    printf("Digite o valor total de vendas no mês: ");
    scanf("%f", &total_vendido);

    comissao_recebida = total_vendido * comissao_taxa;
    printf("Comissao recebida: %.2f\n", comissao_recebida);

    total_recebido = salario + comissao_recebida;
    printf("O valor total recebido no mes foi de: R$ %.2f\n", total_recebido);

    return 0;
}