#include <stdio.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define PORT 4444
#define MAX_SIZE 1024

int main(){
    int sockFD, valueRead;
    char sendMsg[1024];
    char recvMsg[1024];
    struct sockaddr_in clientAddr;
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
        FD_ZERO(&readFDs);
        FD_SET(0, &readFDs);
        FD_SET(sockFD, &readFDs);

        printf("Digite sua mensagem: ");
        fflush(stdout);
        if(select(sockFD + 1, &readFDs, NULL, NULL, NULL) < 0){
            perror("Erro no select");
            break;
        }

        if(FD_ISSET(0, &readFDs)){
            memset(sendMsg, 0, sizeof(sendMsg));
            fgets(sendMsg, MAX_SIZE, stdin);
            sendMsg[strcspn(sendMsg, "\n")]='\0';
            printf("\033[A\r\033[K");
            fflush(stdout);
            if(send(sockFD, sendMsg, strlen(sendMsg), 0) < 0){
                printf("[ERRO]: Erro ao enviar o conteúdo!");
                break;
            }

            printf("[Você]: %s\n", sendMsg);
            fflush(stdout);
            if(strcmp(sendMsg, "/quit")==0){
                printf("Saindo...\n");
                break;
            }
        }

        if(FD_ISSET(sockFD, &readFDs)){
            memset(recvMsg, 0, sizeof(recvMsg));
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
        }
    }

    close(sockFD);
    return 0;
}
