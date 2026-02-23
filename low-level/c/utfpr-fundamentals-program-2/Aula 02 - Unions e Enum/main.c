#include <stdio.h>

enum Semana{DOMINGO=1, SEGUNDA, TERCA, QUARTA, QUINTA, SEXTA, SABADO};

int main(){
    enum Semana semana;
    semana = DOMINGO;

    switch(semana){
        case DOMINGO:
            printf("Hoje é Domingo\n");
            break;
        
        case SEGUNDA:
            printf("Hoje é Segunda-Feira\n");
            break;

        case TERCA:
            printf("Hoje é Terça-Feira\n");
            break;

        case QUARTA:
            printf("Hoje é Quarta-Feira\n");
            break;
        
        case QUINTA:
            printf("Hoje é Quinta-Feira\n");
            break;
        
        case SEXTA:
            printf("Hoje é Sexta-Feira\n");
            break;
        
        case SABADO:
            printf("Hoje é Sabado\n");
            break;

        default:
            printf("Dia Inválido\n");
            break;
        }

    return 0;
}