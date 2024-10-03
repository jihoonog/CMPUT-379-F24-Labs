#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAXLINE 256
#define SERV_PORT 2000

void echo(int sockfd) {
    /* read content into a buffer, and write them back */
    ssize_t n;
    char buf[MAXLINE] = {0};
    /* sockets can also use read(), write() and close() */
    while ((n = read(sockfd, buf, MAXLINE)) > 0) {
        printf("From client: %s\n", buf);
	write(sockfd, buf, n);
        if (n < 0) perror("write");
    }
    return;
}

int main() {
    int listenfd, connfd;
    struct sockaddr_in cliaddr, servaddr; 
    socklen_t clilen;
    listenfd = socket(AF_INET, SOCK_STREAM, 0);  /* create a listen socket */
    servaddr.sin_family = AF_INET;   /* use IPv4 protocol */
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); /* accept any incoming address */
    servaddr.sin_port = htons(SERV_PORT); /* set server port */
    bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr)); /* bind address */
    listen(listenfd, 10); /* start listening */
    while (1) { 
        connfd = accept(listenfd, (struct sockaddr*) &cliaddr, &clilen);/*accept incoming conn*/ 
        echo(connfd);
        close(connfd); /* close connection */
    }
}

