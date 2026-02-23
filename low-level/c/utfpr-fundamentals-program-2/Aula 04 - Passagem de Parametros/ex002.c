#include <stdio.h>

/*
2) Reescreva o exercício anterior utilizando a estrutura horário (contendo hora, minuto e segundo) e passando a estrutura por referência. Utilize o seguinte protótipo da função:
void converteHorario(int total_segundos, Horario* hor)
*/

typedef struct{
    int hora;
    int minuto;
    int segundo;
}Horario;

void converteHora(int total_segundos, Horario *horas){
    
    horas->hora = total_segundos / 3600;
    horas->minuto = (total_segundos % 3600) / 60;
    horas->segundo = total_segundos % 60;
    
}

int main(){
    Horario horas;
    int total_segundos;

    printf("Digite a quantidade total de segundos: ");
    scanf("%d", &total_segundos);

    converteHora(total_segundos, &horas);

    printf("A conversão de %d segundos é: %02d:%02d:%02d", total_segundos, horas.hora, horas.minuto, horas.segundo);

    return 0;
}
