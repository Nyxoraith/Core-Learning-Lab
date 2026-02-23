#include <stdio.h>
#include <stdlib.h>

/*
3) Crie um algoritmo que exiba todos os números múltiplos
de 3 no intervalo de 1 a 322.
*/

int main(){
    int contador = 1;
    while(contador <= 322){
        if(contador % 3 == 0){
            printf("%d\n", contador);
        }
        contador++;
    }
    return 0;
}