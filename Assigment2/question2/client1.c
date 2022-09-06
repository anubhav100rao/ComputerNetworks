#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<unistd.h>

int main()
{
    int client1_socket;
    int error_check;
    struct sockaddr_in client1_address;
    socklen_t server_len;
    char client1_message[2];

    server_len = sizeof(client1_address);

    client1_socket = socket(AF_INET, SOCK_DGRAM, 0);
    if(client1_socket == -1)
    {
        printf("Error creating socket\n");
        exit(1);
    }

    client1_address.sin_family = AF_INET;
    client1_address.sin_port = htons(9002);
    client1_address.sin_addr.s_addr = INADDR_ANY;
    
    printf("Enter character to send\n");
    fgets(client1_message, sizeof(client1_message), stdin);
    
    error_check = sendto(client1_socket, client1_message, sizeof(client1_message),0, (struct sockaddr *) &client1_address, server_len);
    if(error_check == -1)
    {
        printf("Error sending message\n");
        exit(1);
    }

    printf("message sent by client1\n");

    close(client1_socket);

    return 0;
}