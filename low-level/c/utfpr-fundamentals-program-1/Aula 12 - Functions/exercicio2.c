#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/*
Elabore uma função que receba por parâmetro o sexo (caractere) e a
altura de uma pessoa (real), calcule e retorne seu peso ideal. Para isso,
utilize as fórmulas a seguir.
 Para homens: (72.7 * altura) - 58
 Para mulheres: (62.1 * altura) - 44.7
*/

float pesoIdeal(char sexo, float altura);

int main(){
    char sexo;
    float altura;
    float ideal;

    printf("Digite seu sexo [M]/[F]: ");
    scanf("%c", &sexo);
    printf("Digite sua altura: [1.85]: ");
    scanf("%f", &altura);

    ideal = pesoIdeal(sexo, altura);
    printf("O peso ideal para uma pessoa do sexo [%c] e altura de [%.2f]m é: [%.2f]kg\n", sexo, altura, ideal);
    return 0;
}

float pesoIdeal(char sexo, float altura){
    float pesoIdeal;
    if (sexo == 'M'){
        pesoIdeal = (72.7 * altura) - 58;
    }else if (sexo == 'F'){
        pesoIdeal = (62.1 * altura) - 44.7;
    }
    
    return pesoIdeal;
}