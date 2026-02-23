#include <stdio.h>

/*
1) Escreva um programa que receba um número inteiro representando a quantidade total de segundos e, usando passagem de parâmetros por referência, converta a quantidade informada de segundos em Horas, Minutos e Segundos. Imprima o resultado da conversão no formato HH:MM:SS. Utilize o seguinte protótipo da função:
void converteHora(int total_segundos, int* hora, int* min, int* seg)
*/

void converteHora(int total_segundos, int *hora, int *min, int *seg){
    *hora = total_segundos / 3600;
    *min = (total_segundos % 3600) / 60;
    *seg = total_segundos % 60;
    
}

int main(){
    int total_segundos, hora, min, seg;

    printf("Digite a quantidade total de segundos: ");
    scanf("%d", &total_segundos);

    converteHora(total_segundos, &hora, &min, &seg);

    printf("A conversão de %d segundos é: %02d:%02d:%02d", total_segundos, hora, min, seg);

    return 0;
}