// gcc -Wall -pedantic -std=gnu99 -Og -o main main.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCKET_NAME "/tmp/9Lq7BNBnBycd6nxy.socket"

int main(int argc, char *argv[]) {

    FILE * fp;
    char * line = NULL;
    size_t len = 0;
    ssize_t readf;

    fp = fopen("gen_prices.txt", "r");
    if (fp == NULL)
        exit(EXIT_FAILURE);

    int sock = 0, connfd = 0;
    char sendBuff[1025];
	char recvBuff[1025];
	memset(sendBuff, '0', sizeof(sendBuff));

    /*
     * In case the program exited inadvertently on the last run,
     * remove the socket.
     */
    unlink(SOCKET_NAME);

	sock = socket(AF_UNIX, SOCK_STREAM, 0);

    struct sockaddr_un name;
    memset(&name, 0, sizeof(struct sockaddr_un));
    name.sun_family = AF_UNIX;
    strncpy(name.sun_path, SOCKET_NAME, sizeof(name.sun_path) - 1);
   
    bind(sock, (const struct sockaddr *) &name, sizeof(struct sockaddr_un));

    /* Prepare for accepting connections. */
    listen(sock, 20);
    connfd = accept(sock, (struct sockaddr*)NULL, NULL);

    while(1) {

        while ((readf = getline(&line, &len, fp)) != -1) {

            printf("Enviando valor: %f \n", atof(line));
            
            // write
            snprintf(sendBuff, sizeof(sendBuff), line);
            write(connfd, sendBuff, strlen(sendBuff));

            // read and print
            int n = 0;
            if ((n = read(connfd, recvBuff, sizeof(recvBuff)-1)) > 0) {
                recvBuff[n] = 0;
                printf("Ordem Recebida: ");
                fputs(recvBuff, stdout);
            }

        }

        fclose(fp);
        if (line)
            free(line);
        exit(EXIT_SUCCESS);

        
    }

    close(connfd);
}