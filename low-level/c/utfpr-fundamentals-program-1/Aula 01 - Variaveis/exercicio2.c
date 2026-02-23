#include <stdio.h>
#include <stdlib.h>

/*
2) Declare duas variáveis inteiras A e B e atribua valores
diferentes. Em seguida, efetue a troca dos valores de forma
que, a variável A passe a possuir o valor da variável B, e que a
variável B passe a possuir o valor da variável A. Apresente os
valores iniciais e finais de A e B.
*/

int main(){
    int A = 15;
    int B = 7;
    int temp;
    
    printf("Valor inicial de A: %i\n", A);
    printf("Valor inicial de B: %i\n", B);

    temp = A;
    A = B;
    B = temp;

    printf("Valor final de A: %i\n", A);
    printf("Valor final de B: %i\n", B);

    return 0;
}