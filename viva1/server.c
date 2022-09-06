#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX 80

const int INTERNET_PROTOCOL = 0;


void func(int connfd)
{
    char buff[MAX];
    int n;
    // infinite loop for chat
    for (;;) {
        bzero(buff, MAX);
   
        // read the message from client and copy it in buffer
        read(connfd, buff, sizeof(buff));
        // print buffer which contains the client contents
        printf("From client: %s\t To client : ", buff);
        bzero(buff, MAX);
        n = 0;
        // copy server message in the buffer
        while ((buff[n++] = getchar()) != '\n')
            ;
   
        // and send that buffer to client
        write(connfd, buff, sizeof(buff));
   
        // if msg contains "Exit" then server exit and chat ended.
        if (strncmp("exit", buff, 4) == 0) {
            printf("Server Exit...\n");
            break;
        }
    }
}


int main() {

    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli;

    sockfd = socket(AF_INET, SOCK_STREAM, INTERNET_PROTOCOL);
    if(sockfd == -1) {
        perror("Server creation failed\n");
        exit(0);
    } else {
        printf("Socket created successfully\n");
    }


    bzero(&servaddr, sizeof servaddr); // setting second_arg bytes of first_arg 0

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    int bind_socket_status = bind(sockfd, (struct sockaddr*) &servaddr, sizeof servaddr);
    
    if(bind_socket_status == 0) {
        printf("Server binded successfully\n");
    } else {
        printf("Server not binded\n");
        return -1;
    }

    int listen_status = listen(sockfd, 6);

    if(listen_status != 0) {
        printf("Not listening any more\n");
        return -1;
    } else {
        printf("Server is ready to listen\n");
    }
    len = sizeof cli;
    connfd = accept(sockfd, (struct sockaddr*) &cli, &len);

    if(connfd < 0) {
        printf("Server acceptance failed\n");
        return -1;
    } else {
        printf("Server is accepting client's request\n");
    }

    func(connfd);
    close(sockfd);

    return 0;
}