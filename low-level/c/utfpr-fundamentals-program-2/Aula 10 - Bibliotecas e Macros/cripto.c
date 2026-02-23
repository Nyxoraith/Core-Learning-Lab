#include "cripto.h"

void criptografa(char* msg){
    while(*msg != '\0'){
        *msg = (*msg) + 2;
        msg++;
    }
}