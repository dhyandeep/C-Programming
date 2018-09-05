#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	int status, sock_fd;
	struct sockaddr_in server_addr;
	//store the address of server to connect
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(9002);
	server_addr.sin_addr.s_addr = INADDR_ANY;

	sock_fd  = socket(AF_INET,SOCK_STREAM,0);
	int i = 10;
	while(i--)
	{
		int status = connect(sock_fd, (struct sockaddr*)&server_addr, sizeof(server_addr));
		if(status == -1)
		{
			printf("unable to connect to the socket\n");
			sleep(2);
			continue;
		}
		else
		{
			char buff[1024];
			recv(sock_fd, &buff,sizeof(buff),0);
			printf("recieved: %s\n",buff);
			break;
		}
		
	}

	printf("exiting\n");
	exit(0);
	return 0;
}
