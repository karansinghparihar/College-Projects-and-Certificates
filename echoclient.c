//echo client ./echoclient 127.0.0.1  v10000
#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<errno.h>
#include<string.h>

#include <arpa/inet.h>
#include <unistd.h>



void main(int argc,char *argv[])
{
int sock;
struct sockaddr_in server;
int datalen;
int serveraddlen = sizeof(struct sockaddr_in);
char output[1024],input[1024];

if((sock = socket(AF_INET, SOCK_STREAM, 0))==-1)
{
perror("socket : ");
exit(-1);
}

server.sin_family = AF_INET;
server.sin_port = htons(atoi(argv[2]));
server.sin_addr.s_addr = inet_addr(argv[1]);
bzero(&server.sin_zero, 8);



if((connect(sock, (struct sockaddr *)&server, serveraddlen)) == -1)
{
perror("connect : ");
exit(-1);
}



while(1)
{
fgets(input,1024,stdin);

send(sock ,input ,strlen(input),0);

datalen = recv(sock, output,1024,0);
output[datalen] = '\0';

printf("recieved mesg : %s " ,output);
}

close(sock);


}
