#include <stdio.h>
#include <string.h>
/*
2) Escreva um trecho de código para fazer a criação dos
novos tipos de dados conforme solicitado abaixo:
 Horário: composto de hora, minutos e segundos.
 Data: composto de dia, mês e ano.
 Compromisso: local, data, horário e texto que descreve o
compromisso.
*/

typedef struct {
    int horas;
    int minutos;
    int segundos;
}Horario;

typedef struct {
    int dia;
    int mes;
    int ano;
}Data;

typedef struct {
    Horario horario;
    Data data;
    char local[21];
    char descricao[51];
}Compromisso;

int main(){
    Compromisso compromisso;

    printf("Digite o horario do compromisso [hh:mm:ss]: ");
    scanf("%d:%d:%d", &compromisso.horario.horas, &compromisso.horario.minutos, &compromisso.horario.segundos);
    
    printf("Digite a data do compromisso [dd/mm/aaaa]: ");
    scanf("%d/%d/%d", &compromisso.data.dia, &compromisso.data.mes, &compromisso.data.ano);

    setbuf(stdin, NULL);
    printf("Digite o local do compromisso: ");
    fgets(compromisso.local, 20, stdin);
    compromisso.local[strcspn(compromisso.local, "\n")]='\0';

    printf("Digite a descrição do compromisso: ");
    fgets(compromisso.descricao, 20, stdin);
    compromisso.descricao[strcspn(compromisso.descricao, "\n")]='\0';

    printf("Horario do compromisso: [%d:%d:%d]\n", compromisso.horario.horas, compromisso.horario.minutos, compromisso.horario.segundos);
    printf("Data do compromisso: [%d/%d/%d]\n", compromisso.data.dia, compromisso.data.mes, compromisso.data.ano);
    printf("Local do compromisso: %s\n", compromisso.local);
    printf("Descrição do compromisso: %s\n", compromisso.descricao);
    return 0;
}