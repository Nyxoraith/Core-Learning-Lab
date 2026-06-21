#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

#define PORT 4444
#define MAX_SIZE 1024

int main(){
    int sockFD, newSocket, valueRead, nClients;
    struct sockaddr_in serverAddr;
    struct sockaddr_in clientAddr;
    pid_t pID;

    socklen_t addrlen_client = sizeof(clientAddr);
    socklen_t addrlen_server = sizeof(serverAddr);

    sockFD = socket(AF_INET, SOCK_STREAM, 0);
    if(sockFD < 0){
        printf("[ERRO]: Erro ao criar o socket!");
        return 1;
    }

    memset(&serverAddr, 0, addrlen_server);
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(PORT);

    if(bind(sockFD, (struct sockaddr *) &serverAddr, addrlen_server) < 0){
        printf("[ERRO] Erro no Bind!");
        return 1;
    }

    if((listen(sockFD, 5)) < 0){
        printf("[ERRO] Erro no Listen!");
        return 1;
    }

    printf("Aguardando conexão na porta %d...\n", PORT);
    signal(SIGCHLD, SIG_IGN);
    while(1){
        if((newSocket = accept(sockFD, (struct sockaddr *) &clientAddr, &addrlen_client)) < 0){
            printf("[ERRO] Erro ao aceitar a conexão!");
            return 1;
        }

        printf("\r\033[K\nCliente conectado\n[IP]:%s\n[PORTA]:%d\n\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));
        pID = fork();

        if(pID < 0){
            printf("[ERRO] Erro no Fork!");
            return 1;
        }

        if(pID == 0){
            close(sockFD);

            const char* send_msg = "whoami";
            char recv_msg[1024];

            if(send(newSocket, send_msg, strlen(send_msg), 0) < 0){
                printf("[ERRO]: Erro ao enviar o conteúdo!");
                _exit(1);
            }

            valueRead = recv(newSocket, recv_msg, sizeof(recv_msg) -1, 0);

            if (valueRead > 0){
                printf("\r\033[K[CLIENTE]: %s\n", recv_msg);
            }

            close(newSocket);
            _exit(0);
        }

        if(pID > 0){
            close(newSocket);
        }
    }

    close(sockFD);
    return 0;
}
