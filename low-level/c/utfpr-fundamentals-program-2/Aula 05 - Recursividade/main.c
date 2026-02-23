#include <stdio.h>

void exibeNumero(int num){
    if(num <= 1){
        printf("%d\n", num);
    }else{
        printf("%d\n", num);
        exibeNumero(num - 1);
        printf("%d\n", num);
    }
    return;
}

int main(){

    setbuf(stdout, NULL);
    exibeNumero(5);
    return 0;
}