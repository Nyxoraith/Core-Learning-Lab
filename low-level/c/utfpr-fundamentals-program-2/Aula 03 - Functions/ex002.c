#include <stdio.h>

/*
2) Implemente uma função em C que receba como parâmetros o sexo ('M' para masculino e 'F' para feminino) e a altura (número real) de uma pessoa. A função deve calcular e retornar o peso ideal usando as seguintes fórmulas:

Homens: (72.7 * altura) - 58
Mulheres: (62.1 * altura) - 44.7
Na função main, chame essa função com diferentes valores de teste e exiba o resultado na tela.
*/

float pesoIdeal(char sexo, float altura){
    float pesoideal;
    switch(sexo){
        case 'M':
            pesoideal = (72.7 * altura) - 58;
            break;
        case 'F':
            pesoideal = (62.1 * altura) - 58;
            break;
        default:
            printf("Sexo inválido.");
    }
    return pesoideal;
}

int main(){
    char sexo;
    float altura, pesoideal;

    printf("Digite o seu sexo (M) Masculino | (F) Feminino: ");
    scanf("%c", &sexo);

    printf("Digite a sua altura: ");
    scanf("%f", &altura);

    pesoideal = pesoIdeal(sexo, altura);

    printf("O peso ideal para uma pessoa do sexo %c e altura de %.2f é de: %.2f\n", sexo, altura, pesoideal);
    return 0;
}