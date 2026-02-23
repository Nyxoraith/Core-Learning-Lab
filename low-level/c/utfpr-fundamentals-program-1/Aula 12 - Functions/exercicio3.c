#include <stdio.h>

/*
3) Escreva um procedimento que recebe por parâmetro as 3 notas de um
aluno e uma letra. Se a letra for A, o procedimento calcula a média
aritmética das notas do aluno, se for P, a sua média ponderada (pesos: 5, 3
e 2) e se for S, a soma das notas. O valor calculado também deve ser
retornado e exibido na função main.
*/

float calcMedia(float nota1, float nota2, float nota3, char letra);

int main(){
    float nota1, nota2, nota3, media;
    char letra;

    printf("Digite a primera nota: ");
    scanf("%f", &nota1);
    printf("Digite a segunda nota: ");
    scanf("%f", &nota2);
    printf("Digite a terceira nota: ");
    scanf("%f", &nota3);

    printf("[A] para média aritimética\n[P] para média ponderada\n[S] para soma\nDigite uma letra [A/P/S]: ");
    scanf(" %c", &letra);

    media = calcMedia(nota1, nota2, nota3, letra);

    printf("O valor da média é: %.2f", media);

    return 0;
}

float calcMedia(float nota1, float nota2, float nota3, char letra){
    float media;
    int peso1 = 5, peso2 = 3, peso3 = 2;

    if (letra == 'A'){
        media = (nota1 + nota2 + nota3) / 3;
    }else if(letra == 'P'){
        media = ((nota1 * peso1) + (nota2 * peso2) + (nota3 * peso3)) / (peso1 + peso2 + peso3);
    }else if(letra == 'S'){
        media = nota1 + nota2 + nota3;
    }else{
        printf("Letra inválida.");
    }


    return media;

}