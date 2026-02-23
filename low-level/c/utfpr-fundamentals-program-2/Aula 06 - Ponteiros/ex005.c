#include <stdio.h>

/*
5) Elabora uma função que receba duas strings como parâmetros e
verifique se a segunda string está dentro da primeira. Para isso, utilize
apenas aritmética de ponteiros.
*/

void verificaString(char *str1, char *str2);

int main(){
    char *str1 = "PrimeiraString";
    char *str2 = "String";
    verificaString(str1, str2);
    return 0;
}

void verificaString(char *str1, char *str2){
    const char *p1, *p2;

    while(*str1 != '\0'){
        p1 = str1;
        p2 = str2;

        while (*p1 != '\0' && *p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }

        if(*p2 == '\0'){
            printf("Sim, a segunda string está contida na primeira");
            return;
        }
        str1++;
    }
    printf("Não, a segunda string NÃO está contida na primeira.");
}