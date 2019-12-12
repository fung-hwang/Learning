#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <pthread.h>
#include <sys/socket.h>

#define SERVPORT 3333	//监听端口
#define BACKLOG 10
#define PTHREAD_MAX 10

int i = 0;
int sockfd, client_fd[PTHREAD_MAX];


void *client_func(void *arg)
{
	i++;
	int recv_len = 0;
	char recv_buf[256] = ""; // 接收缓冲区
	int client_fd = (int)arg; // 传过来的已连接套接字
	while ((recv_len = recv(client_fd, recv_buf, sizeof(recv_buf), 0)) > 0)
	{
		printf("recv_buf: %s\n", recv_buf); // 打印数据
		send(connfd, recv_buf, recv_len, 0); // 给客户端回数据
	}
	printf("Client closed!\n");
	close(client_fd); 
	return NULL;
}

int main()
{
	pthread_t thread[PTHREAD_MAX];
	struct sockaddr_in my_addr;
	struct sockaddr_in remote_addr;
	int sin_size;
	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
		perror("create socket error");
		exit(1);
	}
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(SERVPORT);
	my_addr.sin_addr.s_addr = INADDR_ANY;
	bzero(&(my_addr.sin_zero), 8);
	if (bind(sockfd, (struct sockaddr*)&my_addr, sizeof(struct sockaddr)) == -1) {
		perror("bind error");
		exit(1);
	}
	if (listen(sockfd, BACKLOG) == -1) {
		perror("listen error");
		exit(1);
	}
	while (1) {
		sin_size = sizeof(struct sockaddr_in);
		if ((client_fd[i] = accept(sockfd, (struct sockaddr*)&remote_addr, &sin_size)) == -1) {
			perror("accept error");
			continue;
		}
		printf("receive connection from:&s\n", inet_ntoa(remote_addr.sin_addr));
		
		while (i < PTHREAD_MAX - 1) {
			int temp;
			if (temp = pthread_create(&thread[i], NULL, client_func, (void*)client_fd[i]) != 0) {
				printf("create thread error");
			}
			
			pthread_detach(&thread);
			i--;
		}
		close(client_fd);
	}
}
