#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>

#define PORTS 65535
#define CHILD 100

int main(){
    int portsChild;
    char tmpTargetIP[20];
    struct sockaddr_in targetAddr;
    pid_t pID;

    memset(&targetAddr, 0, sizeof(targetAddr));
    targetAddr.sin_family = AF_INET;

    printf("Digite o endereço IP: ");
    fgets(tmpTargetIP, 20, stdin);
    tmpTargetIP[strcspn(tmpTargetIP, "\n")]='\0';
    setbuf(stdin, NULL);

    if(inet_pton(AF_INET, tmpTargetIP, &targetAddr.sin_addr) <= 0){
        printf("[ERRO] Erro ao converter o endereço!");
        return 1;
    }

    portsChild = PORTS / CHILD;

    for(int i=0; i < CHILD; i++){
        pID = fork();

       if(pID < 0){
            printf("[ERRO] Erro no Fork!");
            return 1;
        }

        if(pID == 0){
            int init = i * portsChild + (i == 0 ? 1 : 0);
            int end = (i + 1) * portsChild;

            if(i == CHILD - 1){
                end = PORTS;
            }

            for(int j=init; j<=end; j++){
                int sockFD = socket(AF_INET, SOCK_STREAM, 0);
                if(sockFD < 0){
                    continue;
                }

                targetAddr.sin_port = htons(j);

                if(connect(sockFD, (struct sockaddr *) &targetAddr, sizeof(targetAddr)) == 0){
                    printf("[FILHO %d]: PORTA ABERTA: %d\n", i, j);
                }
                close(sockFD);
            }
            _exit(0);
        }
    }

    for(int i=0; i < CHILD; i++) {
        wait(NULL);
    }

    printf("\nPortscanning completo\n");

    return 0;
}
