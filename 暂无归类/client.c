#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define MAXDATASIZE 256
#define SERVPORT 3333

//client
int main(int argc, char* argv[]) {
    	char buf[MAXDATASIZE];
	int sockfd, recvbytes;
	struct hostent *host;
    	struct sockaddr_in serverAddr;

	if (argc < 2) {
		fprintf(stderr, "please enter the server's hostname!");
	}
	if ((host = gethostbyname(argv[1])) == NULL) {
		herror("gethostname error");
		exit(1);
	}

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Create socket error");
        exit(-1);
    }

    /*init*/
    serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(SERVPORT);
	serverAddr.sin_addr = *((struct in_addr *)host->h_addr);
	bzero(&(serverAddr.sin_zero), 8);

    if (connect(sockfd, (struct sockaddr*)&serverAddr,sizeof(serverAddr)) == -1) {
        perror("Connect error");
        exit(1);
    }
	if ((recvbytes = recv(sockfd, buf, MAXDATASIZE, 0)) == -1) {
		perror("Connect error");
		exit(1);
	}

	buf[recvbytes] = '\0';
	printf("receive:%s", buf);
    close(sockfd);
    return 0;
}
