#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/*
5) Faça um programa que receba uma frase e depois exiba quantas vezes
cada vogal aparece. Ele deve contar considerando o tamanho da String.
*/

int main(){
    char frase[50];
    int vogalA = 0, vogalE = 0, vogalI = 0, vogalO = 0, vogalU = 0;

    printf("Digite uma frase: ");
    fgets(frase, 50, stdin);
    frase[strcspn(frase, "\n")]='\0';


    size_t frase_len = strlen(frase);

    for(size_t i = 0; i < frase_len; i++){
        frase[i] = tolower(frase[i]);
    }

    for(size_t i = 0; i < frase_len; i++){
        if(frase[i] == 'a'){
            vogalA++;

        }else if(frase[i] == 'e'){
            vogalE++;

        }else if(frase[i] == 'i'){
            vogalI++;

        }else if(frase[i] == 'o'){
            vogalO++;

        }else if(frase[i] == 'u'){
            vogalU++;

        }
    }
    
    printf("Total vogais A: %d\n", vogalA);
    printf("Total vogais E: %d\n", vogalE);
    printf("Total vogais I: %d\n", vogalI);
    printf("Total vogais O: %d\n", vogalO);
    printf("Total vogais U: %d\n", vogalU);
    return 0;
}