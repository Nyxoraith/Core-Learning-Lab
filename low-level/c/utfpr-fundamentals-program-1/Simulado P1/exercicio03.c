#include <stdio.h>
#include <stdlib.h>

/*
3) Faça um programa que tenha como entrada: o número de horas, minutos e segundos atuais, informe quantos segundos faltam para chegar terminar o dia.
*/

int main(){
    int horas, minutos, segundos, segundos_restantes;

    printf("Digite a hora/minuto/segundo atual (00:00:00): ");
    scanf("%d:%d:%d", &horas, &minutos, &segundos);

    segundos_restantes = (23 - horas) * 3600 + (59 - minutos) * 60 + (60 - segundos);

    printf("Faltam %d segundos para o término do dia.\n", segundos_restantes);

    return 0;
}