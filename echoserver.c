//echo server ./echoserver 10000
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
int sock,cli;
struct sockaddr_in server,client;
int datalen;
int serveraddlen = sizeof(struct sockaddr_in);
char message[1024];
int sent;
if((sock = socket(AF_INET, SOCK_STREAM, 0))==-1)
{
perror("socket : ");
exit(-1);
}

server.sin_family = AF_INET;
server.sin_port = htons(atoi(argv[1]));
server.sin_addr.s_addr = INADDR_ANY;
bzero(&server.sin_zero, 8);



if((bind(sock, (struct sockaddr *)&server, serveraddlen)) == -1)
{
perror("bind : ");
exit(-1);
}

 if((listen(sock, 5))==1)
{
perror("listen");
exit(-1);
}

while(1)
{

if(( cli = accept(sock, (struct sockaddr *)&client, &serveraddlen))==-1)
{
perror("accept");
exit(-1);
}

//sent=send(cli ,message ,strlen(message),0);
printf("Sent %d bytes to client : %s\n", sent, inet_ntoa(client.sin_addr));

datalen = 1;
while(datalen)
{
datalen = recv(cli,message,1024,0);

if(datalen)
{
send(cli ,message ,datalen,0);
message[datalen] = '\0';
printf("sent mesg : %s " ,message);
}
}
printf("client disconnected\n");
close(cli);

}
}
