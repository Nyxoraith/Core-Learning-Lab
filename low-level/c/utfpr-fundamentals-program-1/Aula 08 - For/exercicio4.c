#include <stdio.h>
#include <stdlib.h>

/*
4) Crie um algoritmo que exiba todos os números pares
entre 240 e 730 inclusive.
*/

int main(){

    for(int i = 240; i <= 730; i++){
        if(i % 2 == 0){
            printf("%d\n", i);
        }
    }

    return 0;
}