#include <stdio.h>
#include <stdlib.h>

int soma(int n1, int n2){
    return n1 + n2;
}

int main(int argc, char **argv){
	int nums[2], resultado;

    if(argc == 3){
        for(int i = 1, j = 0; i < argc; i++, j++){
            nums[j] = atoi(argv[i]);
        }
        
        resultado = soma(nums[0], nums[1]);
        printf("O resultado da soma entre %d e %d é: %d\n", nums[0], nums[1], resultado);
    }else{
        printf("O programa deve receber 2 argumentos\n");
    }
	
	return 0;
}