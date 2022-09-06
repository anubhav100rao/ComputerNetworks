#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#define PORT 8080
#define MAX 80


char* SERVER_IP = "127.0.0.1";

void func(int sockfd)
{
    char buff[MAX];
    int n;
    for (;;) {
        bzero(buff, sizeof(buff));
        printf("Enter the string : ");
        n = 0;
        while ((buff[n++] = getchar()) != '\n')
            ;
        write(sockfd, buff, sizeof(buff));
        bzero(buff, sizeof(buff));
        read(sockfd, buff, sizeof(buff));
        printf("From Server : %s", buff);
        if ((strncmp(buff, "exit", 4)) == 0) {
            printf("Client Exit...\n");
            break;
        }
    }
}


int main() {
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in servaddr, cli;

    if(sockfd == -1) {
        printf("socket creation failed\n");
        printf("good night\n");
        exit(0);
    } else {
        printf("Client's socket created\n");
    }

    //bzero(&servaddr, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(SERVER_IP);
    servaddr.sin_port = htons(PORT);

    int connect_status = connect(sockfd, (struct sockaddr*) &servaddr, sizeof servaddr);

    printf("connect_status %d\n", connect_status);

    if(connect_status != 0) {
        printf("Connection failed\n");
        return -1;
    } else {
        printf("Connected...\n");
    }

    printf("Bhai chal le\n");

    func(sockfd);
    close(sockfd);
}