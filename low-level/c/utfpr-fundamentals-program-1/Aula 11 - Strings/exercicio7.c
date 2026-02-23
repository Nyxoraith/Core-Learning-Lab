#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
 7) Escreva um programa que receba uma sigla de um estado da região
Sul ou Sudeste e exiba o nome completo do estado correspondente.
*/

int main(){
    char estado[3];
    
    printf("Digite a sigla de um estado da região sul ou sudeste: ");
    fgets(estado, 3, stdin);
    estado[strcspn(estado, "\n")]='\0';
    
    size_t len = strlen(estado);

    for (size_t i = 0; i < len; i++){
        estado[i] = toupper(estado[i]);
    }

    if(strcmp(estado, "PR") == 0){
        printf("Estado do Paraná\n");
    }else if(strcmp(estado, "SC") == 0){
        printf("Estado de Santa Catarina\n");
    }else if(strcmp(estado, "RS") == 0){
        printf("Estado do Rio Grande do Sul\n");
    }else if(strcmp(estado, "SP") == 0){
        printf("Estado de São Paulo\n");
    }else if(strcmp(estado, "RJ") == 0){
        printf("Estado do Rio de Janeiro\n");
    }else if(strcmp(estado, "MG") == 0){
        printf("Estado de Minas Gerais\n");
    }

    return 0;
}