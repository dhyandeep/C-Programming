#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <pthread.h>
void *connection_handler(void* arg);
int main()
{
	
	int sock_fd;
	sock_fd = socket(AF_INET, SOCK_STREAM, 0);
	//define server address of this server
	struct sockaddr_in sock_addr;
	sock_addr.sin_family = AF_INET;
	sock_addr.sin_port = htons(9002);
	sock_addr.sin_addr.s_addr = INADDR_ANY;
	//bind the socket to the above ip and port
	bind(sock_fd, (struct sockaddr*)&sock_addr,sizeof(sock_addr));

	listen(sock_fd,5);
	int client_socket;
	int client_max_count = 10;
	pthread_t conn_thread;
	while(client_max_count--)
	{
		client_socket = accept(sock_fd, NULL,NULL);
	    	if (pthread_create(&conn_thread, NULL, connection_handler, (void *)&client_socket) ) 
		{
	    		perror("pthread_create");
	    		continue;
		}	
	}
	
	printf("exiting the server");
	return 0;
}
void *connection_handler(void* arg)
{
	char server_message[256] = "hello client from server!";
	printf("entered connection handler thread\n");
	int* client_socket = (int*) arg;
	send(*client_socket, server_message, sizeof(server_message),0);
	
}
