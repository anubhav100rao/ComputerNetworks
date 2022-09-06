// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <unistd.h>
// #include <string.h>

// int main(){
//     int error_check;
//     char server_message[256];
//     socklen_t client;
//     int server_socket;
//     server_socket = socket(AF_INET, SOCK_STREAM, 0); 

//     struct sockaddr_in server_address;
//     server_address.sin_family = AF_INET;
//     server_address.sin_port = htons(9002);
//     server_address.sin_addr.s_addr = INADDR_ANY;

//     struct sockaddr_in client_address;
//     client = sizeof(client_address);

//     error_check = bind(server_socket), (struct sockaddr *)&server_address,sizeof(server_address);

//     if(error_check==-1){
//     printf("Some error in binding\n\n");
//     exit(1);
//     }

//     error_check = listen(server_socket, S);
//     printf("Some error in listening\n\n");
//     exit(1);

//     int client socket;
//     client socket = accept(server_socket, (struct sockadder *)&client_address, &client);

//     if(client_socket == -1){
//     printf("unexpected error occured\n\n")
//     }

//     while(1){
//     error_check = recv(client_socket, server_message. sizeof(server_message),0);

//     if(error_check == -1){
//     printf("error in receiving from client\n\n");
//     exit(1);
//     }
//     }

//     printf("Client: %s\n, server_message");
//     printf("Server: ");
    
//     fgets(server_message, sizeof(server_message), stdin);

//     if(strncmp(server_message, "bye", 3)==0){
//     break;
//     }

//     error_check = send(client_socket, server_message, sizeof(server_message),0);

//     if(error_check == -1){
//     printf("error in sending message\n");
//     exit(1);
//     }

//     close(server_socket);

//     return 0;
// }

// Question 1: Client Code
// #include <stdio.h>
// #include <stdlib.h>
// #include <sys/types.h>
// #include <sys/socket.h>
// #include <netinet/in.h>
// #include <unistd.h>
// #include <string.h>

// int main(){
//     int network_socket;
//     int error_check;
//     network_socket = socket(AF_INET, SOCK_STREAM,0);

//     struct sockaddr_in server_address;
//     server_address.sin_family = AF_INET;
//     server_address.sin_port = htons(9002);
//     server_address.sin_addr.s_addr = INADDR_ANY;

//     int connection_status = connect(network_socket, (struct sockaddr*)&server_address, sizeof(server_address));

//     if(connection_status == -1){
//     printf("There was an error making a connection to the remote socket\n\n");

//     }

//     char server_response[256];
//     while(1){
//     printf("Client: ");

//     fgets(server_response, sizeof(server_response), stdin);

//     if(strncmp(server_response, "bye", 3)==0){
//     break;
//     }

//     error_check = send(network_socket, &server_response, sizeof(server_response), 0);

//     if(error_check=-1){
//     printf("error sending message\n");
//     exit(1);
//     }

//     error_check = recv(network_socket, &server_response), sizeof(server_response), 0);

//     if(error_check == -1){
//     printf("error receiving message\n");
//     exit(1);
//     }

//     printf("Server: %s", server_response):
//     }

//     close(network_socket);

//     return 0;

// }

// Question 2a: Client 1
//  #include<stdio.h>
// #include<stdlib.h>
// #include<sys/socket.h>
// #include<sys/types.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #define IP "10.42.0.219"

// int main()
// {
//     int client_socket;
//     int error_check;
//     struct sockaddr_in client_address;
//     socklen_t server_len;
//     char client_message[2];

//     server_len = sizeof(client_address);

//     client_socket = socket(AF_INET, SOCK_DGRAM, 0);
//     if(client_socket == -1)
//     {
//     printf("Error creating socket\n");
//     exit(1);
//     }

//     client_address.sin_family = AF_INET;
//     client_address.sin_port = htons(9002);
//     client_address.sin_addr.s_addr = INADDR_ANY;
//     // client_address.sin_addr.s_addr = inet_addr(IP);

//     printf("Enter character to send\n");
//     // taking input from client1
//     fgets(client_message, sizeof(client_message), stdin);
    
//     error_check = sendto(client_socket, client_message, sizeof(client_message),0, (struct sockaddr *) &client_address, server_len);
//     if(error_check == -1)
//     {
//     printf("Error sending message\n");
//     exit(1);
//     }

//     printf("message sent by client\n");

//     close(client_socket);

//     return 0;
// }



// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/socket.h>
// #include<sys/types.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #define IP "10.42.0.219"

// int main()
// {
//     int client_socket;
//     int error_check;
//     struct sockaddr_in client_address;
//     socklen_t server_len;
//     char client_message[1024];

//     server_len = sizeof(client_address);

//     client_socket = socket(AF_INET, SOCK_DGRAM, 0);
//     if(client_socket == -1)
//     {
//     printf("Error creating socket\n");
//     exit(1);
//     }

//     client_address.sin_family = AF_INET;
//     client_address.sin_port = htons(9002);
//     client_address.sin_addr.s_addr = INADDR_ANY;
//     // client_address.sin_addr.s_addr = inet_addr(IP);

//     error_check = sendto(client_socket, client_message, sizeof(client_message),0, (struct sockaddr *) &client_address, server_len);
//     if(error_check == -1)
//     {
//     printf("Error sending message\n");
//     exit(1);
//     }

//     error_check = recvfrom(client_socket, client_message, sizeof(client_message), 0, (struct sockaddr *) &client_address, &server_len);
//     if(error_check == -1)
//     {
//     printf("Error receiving message\n");
//     exit(1);
//     }
//     printf("Server sent following character:\n");
//     printf("%s\n", client_message);

//     close(client_socket);

//     return 0;
// }



// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/types.h>
// #include<sys/socket.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #define IP "172.26.47.229"

// int main()
// {
//     int server_socket;
//     int error_check;
//     char server_message[256];
//     char ping[10];
//     struct sockaddr_in client_address;
//     socklen_t client_len;
    
//     client_len = sizeof(client_address);

//     server_socket = socket(AF_INET, SOCK_DGRAM, 0);

//     struct sockaddr_in server_address;
//     server_address.sin_family = AF_INET;
//     server_address.sin_port = htons(9002);
//     server_address.sin_addr.s_addr = INADDR_ANY;
//     // server_address.sin_addr.s_addr = inet_addr(IP);

//     error_check = bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address));
//     if(error_check == -1)
//     {
//     printf("Error while binding\n");
//     exit(1);
//     }

//     // get message from client 1
//     error_check = recvfrom(server_socket,server_message,sizeof(server_message),0, (struct sockaddr *) &client_address, &client_len);
//     if(error_check == -1)
//     {
//     printf("error receiving message from client.\n");
//     exit(1);
//     }

//     printf("Client sent character: %s\n", server_message);
    
//     // process the message and decrement the character sent by client 1
//     if(server_message[0] == 'a')
//     {
//     server_message[0] = 'z';
//     }
//     else if (server_message[0] == 'A')
//     {
//     server_message[0] == 'Z';
//     }
//     else
//     {
//     server_message[0] = server_message[0] - 1;
//     }

//     // client 2 pings so that its ip address and port can be known and response can be sent.
//     error_check = recvfrom(server_socket,ping,sizeof(ping),0, (struct sockaddr *) &client_address, &client_len);
//     if(error_check == -1)
//     {
//     printf("error receiving message from client.\n");
//     exit(1);
//     }

//     error_check = sendto(server_socket, server_message, sizeof(server_message), 0, (struct sockaddr *) &client_address, client_len);
//     if(error_check == -1)
//     {
//     printf("Error while sending message.\n");
//     exit(1);
//     }

//     printf("Server says I am done.\n");

//     close(server_socket);
//     return 0;
// }

// Question 2b: Client 1
// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/socket.h>
// #include<sys/types.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #define IP "10.42.0.203"

// int main()
// {
//     int client_socket;
//     int error_check;
//     struct sockaddr_in client_address;
//     socklen_t server_len;
//     // char client_message[2];
//     int dat[1];

//     server_len = sizeof(client_address);

//     client_socket = socket(AF_INET, SOCK_DGRAM, 0);
//     if(client_socket == -1)
//     {
//     printf("Error creating socket\n");
//     exit(1);
//     }

//     client_address.sin_family = AF_INET;
//     client_address.sin_port = htons(9002);
//     // client_address.sin_addr.s_addr = INADDR_ANY;
//     client_address.sin_addr.s_addr = inet_addr(IP);
    
//     printf("Enter character to send\n");
//     // fgets(dat, sizeof(dat[0]), stdin);
//     scanf("%d",&dat[0]);
//     // dat[1]  = 0;
//     error_check = sendto(client_socket, dat, sizeof(dat),0, (struct sockaddr *) &client_address, server_len);
//     if(error_check == -1)
//     {
//     printf("Error sending message\n");
//     exit(1);
//     }

//     printf("message sent by client\n");

//     close(client_socket);

//     return 0;
// }

// Question 2b: Client 2
// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/socket.h>
// #include<sys/types.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #define IP "10.42.0.203"

// int main()
// {
//     int client_socket;
//     int error_check;
//     struct sockaddr_in client_address;
//     socklen_t server_len;
//     char client_message[1024];
//     int d;

//     server_len = sizeof(client_address);

//     client_socket = socket(AF_INET, SOCK_DGRAM, 0);
//     if(client_socket == -1)
//     {
//     printf("Error creating socket\n");
//     exit(1);
//     }

//     client_address.sin_family = AF_INET;
//     client_address.sin_port = htons(9002);
//     // client_address.sin_addr.s_addr = INADDR_ANY;
//     client_address.sin_addr.s_addr = inet_addr(IP);

//     error_check = sendto(client_socket, &d, sizeof(d),0, (struct sockaddr *) &client_address, server_len);
//     if(error_check == -1)
//     {
//     printf("Error sending message\n");
//     exit(1);
//     }

//     error_check = recvfrom(client_socket, &d, sizeof(d), 0, (struct sockaddr *) &client_address, &server_len);
//     if(error_check == -1)
//     {
//     printf("Error receiving message\n");
//     exit(1);
//     }
//     printf("Server sent following character:\n");
//     printf("%d\n", d);

//     close(client_socket);

//     return 0;
// }

// Question 2b: Server
// #include<stdio.h>
// #include<stdlib.h>
// #include<sys/types.h>
// #include<sys/socket.h>
// #include<netinet/in.h>
// #include<unistd.h>
// #define IP "10.42.0.203"

// int main()
// {
//     int server_socket;
//     int error_check;
//     char server_message[256];
//     int dat[1];
//     char ping[10];
//     struct sockaddr_in client_address;
//     socklen_t cl