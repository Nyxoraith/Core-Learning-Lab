#include <stdio.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define PORTS 65535
#define THREADS 100

pthread_mutex_t printLock;

typedef struct ThreadArgs {
    char targetIP[20];
    int initPort;
    int endPort;
}ThreadArgs;

void* portScanningThread(void *threadArgs);

int main(){
    int status;
    ThreadArgs threadArgs[THREADS];
    pthread_t threads[THREADS];

    int portsThreads = PORTS / THREADS;

    pthread_mutex_init(&printLock, NULL);

    for(int i=0; i<THREADS; i++){
        strcpy(threadArgs[i].targetIP, "127.0.0.1");
        threadArgs[i].initPort = i * portsThreads + (i == 0 ? 1 : 0);
        threadArgs[i].endPort = (i + 1) * portsThreads;

        if(i == THREADS - 1){
            threadArgs[i].endPort = PORTS;
        }

        status = pthread_create(&threads[i], NULL, portScanningThread, (void*) &threadArgs[i]);
        if(status != 0){
            return 1;
        }
    }

    for(int i=0; i<THREADS; i++){
        pthread_join(threads[i], NULL);
    }
    printf("\nScan Finalizado.\n");

    pthread_mutex_destroy(&printLock);

    return 0;
}

void* portScanningThread(void *threadArgs){
    struct sockaddr_in localTargetAddr;
    ThreadArgs *localThreadArgs = (ThreadArgs*) threadArgs;

    memset(&localTargetAddr, 0, sizeof(localTargetAddr));
    localTargetAddr.sin_family = AF_INET;
    if(inet_pton(AF_INET, localThreadArgs->targetIP, &localTargetAddr.sin_addr) != 1){
        printf("[ERRO] Erro ao converter o endereço!");
        pthread_exit(NULL);
    }

    for(int i=localThreadArgs->initPort; i<=localThreadArgs->endPort; i++){
        int sockFD = socket(AF_INET, SOCK_STREAM, 0);
        if(sockFD < 0){
            continue;
        }

        int flags = fcntl(sockFD, F_GETFL, 0);
        fcntl(sockFD, F_SETFL, flags | O_NONBLOCK);

        localTargetAddr.sin_port = htons(i);

        if(connect(sockFD, (struct sockaddr *) &localTargetAddr, sizeof(localTargetAddr)) < 0){
            if(errno == EINPROGRESS){
                fd_set writeFDS;
                struct timeval timeout;

                FD_ZERO(&writeFDS);
                FD_SET(sockFD, &writeFDS);

                timeout.tv_sec = 1;
                timeout.tv_usec = 500000;

                int selectResult = select(sockFD+1, NULL, &writeFDS, NULL, &timeout);
                if(selectResult > 0 && FD_ISSET(sockFD, &writeFDS)){
                    int socketError;
                    socklen_t len = sizeof(socketError);

                    getsockopt(sockFD, SOL_SOCKET, SO_ERROR, &socketError, &len);

                    if(socketError == 0){
                        pthread_mutex_lock(&printLock);

                        printf("[PORTA ABERTA]: %d\n", i);

                        pthread_mutex_unlock(&printLock);
                    }
                }
            }
        }else{
            pthread_mutex_lock(&printLock);

            printf("[PORTA ABERTA]: %d\n", i);

            pthread_mutex_unlock(&printLock);
        }
        close(sockFD);
    }
    return NULL;
}
