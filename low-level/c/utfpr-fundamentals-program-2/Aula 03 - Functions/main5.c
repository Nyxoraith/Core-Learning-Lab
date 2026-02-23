#include <stdio.h>
#include <stdlib.h>

/**
 * @brief 
 * 
 * @param argc 
 * @param argv 
 * @return int 
 */

int main(int argc, char** argv){
    int ano;

    for(int i = 0; i < argc; i++){
        printf("O %dº argumento é: %s\n", i+1, argv[i]);
    }

    if(argc > 1){
        ano = atoi(argv[1]);    
        printf("Ano: %d\n", ano);
    }else{
        printf("Falta argumentos\n");
    }
    return 0;
}