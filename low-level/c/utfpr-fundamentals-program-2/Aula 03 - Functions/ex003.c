#include <stdio.h>

/*
3) Implemente uma função em C que receba, via parâmetro, três notas de um aluno (valores reais) e um caractere indicando o tipo de cálculo a ser realizado:

'A' → Média aritmética das três notas.
'P' → Média ponderada, considerando os pesos: 5 para a primeira nota, 3 para a segunda e 2 para a terceira.
'S' → Soma das três notas.
A função deve retornar o valor calculado. Na função main, solicite ao usuário as três notas e a letra correspondente à operação desejada, chame a função e exiba o resultado na tela.
*/
//(peso * nota) + (peso * nota) / (nota + nota)

float calcNotas(float nota1, float nota2, float nota3, char operacao){
    float resultado;

    switch(operacao){        
        case 'A':
            //media aritimetica
            resultado = (nota1 + nota2 + nota3) / 3;
            break;
        case 'P':
            //media ponderada
            resultado = (5 * nota1 + 3 * nota2 + 2 * nota3) / (nota1 + nota2 + nota3);
            break;

        case 'S':
            resultado = nota1 + nota2 + nota3;
            break;
    }
    return resultado;
}
int main(){
    float nota1, nota2, nota3, resultado;
    char operacao;

    printf("Digite a 1º nota: ");
    scanf("%f", &nota1);
    getchar();

    printf("Digite a 2º nota: ");
    scanf("%f", &nota2);
    getchar();
    
    printf("Digite a 3º nota: ");
    scanf("%f", &nota3);
    getchar();

    printf("(A) Média aritmética das três notas\n(P) Média ponderada\n(S) Soma\nDigite o tipo de calculo desejado:");
    scanf("%c", &operacao);
    getchar();

    resultado = calcNotas(nota1, nota2, nota3, operacao);

    printf("O resultado da operação (%c) foi: %.2f\n", operacao, resultado);
    return 0;
}

