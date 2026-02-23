#include <stdio.h>
#include <stdlib.h>

/*
8) Utilizando a estrutura do laço for aninhado, crie um
programa que exiba a tabuada de todos os números de
1 a 10 no seguinte formato:
Tabuada do 1:
1 x 1 = 1
1 x 2 = 2
1 x 3 = 3
...
Tabuada do 5:
5 X 1 = 5
5 X 2 = 10
5 X 3 = 15
...
*/

int main(){

    for(int tabuada = 1; tabuada <= 10; tabuada++){
        for(int mult = 1, resultado; mult <= 10; mult++){
            resultado = tabuada * mult;
            printf("%d x %d = %d\n",tabuada, mult, resultado);
        }
        printf("...\n");
    }

    return 0;
}