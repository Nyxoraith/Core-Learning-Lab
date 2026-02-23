#include <stdio.h>
#include "cripto.h"

int main(){
    char mensagem[35] = "Minha mensagem secreta";

    printf("Mensagem original: %s \n", mensagem);
    criptografa(mensagem);
    printf("Mensagem criptografada: %s \n", mensagem);
    return 0;
}