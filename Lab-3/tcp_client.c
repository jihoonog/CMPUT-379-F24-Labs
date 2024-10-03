#include <stdio.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>

#define MAX_LINE 256
#define SERV_PORT 2000

int main() {
    int clientfd;
    struct sockaddr_in servaddr; 
    clientfd = socket(AF_INET, SOCK_STREAM, 0);  /* create a socket */
    servaddr.sin_family = AF_INET;   /* use IPv4 protocol */
    servaddr.sin_port = htons(SERV_PORT); /* set to server port */

    inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr); /* set the ip address to localhost*/

    connect(clientfd, (struct sockaddr*)&servaddr, sizeof(servaddr));
    
    char* msg = "Hello World";
    char recv_msg[MAX_LINE] = {0};
    printf("Sending %s to server\n", msg);
    write(clientfd, msg, strlen(msg));
    read(clientfd, recv_msg, MAX_LINE);
    printf("Got %s from server\n", recv_msg);

    close(clientfd);
    return 0;
}

