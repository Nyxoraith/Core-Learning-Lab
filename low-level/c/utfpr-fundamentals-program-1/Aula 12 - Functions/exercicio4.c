#include <stdio.h>

/*
Faça uma função que receba a média final de um aluno
por parâmetro e retorne o seu conceito, conforme a tabela
abaixo:
[ 9 - 10] A
[ 7 – 9 ] B
[ 5 - 7 ] C
[ 0 – 5 ] D
*/

char conceitoNota(int media);

int main(){
    int media;
    char conceito;

    printf("Digite a media final [0-10]: ");
    scanf("%d", &media);

    conceito = conceitoNota(media);

    printf("A média [%d] é equivalente ao conceito: [%c]", media, conceito);
    return 0;
}

char conceitoNota(int media){
    char conceito = ' ';
    if (media >= 0 && media < 5){
        conceito = 'D';
    }else if(media >= 5 && media < 7){
        conceito = 'C';
    }else if(media >= 7 && media < 9){
        conceito = 'B';
    }else if (media >= 9 && media <= 10){
        conceito = 'A';
    }else{
        printf("Média inválida.");
    }

    return conceito;
}