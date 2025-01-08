#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
int main()
{
int clientsocket,port;
struct sockaddr_in serveraddr,clientaddr;
socklen_t len;
struct hostnet *server;
char msg[50];
clientsocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
printf("Enter the port number");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
fgets(msg,2,stdin);
printf("Sending msgs for server connection\n");
sendto(clientsocket,"HI I AM CLIENT",sizeof("HI I AM CLIENT"),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("Recieving msg from server\nn");
recvfrom(clientsocket,msg,sizeof(msg),0,(struct sockaddr*)&serveraddr,&len);
printf("Message rcvd :\t %s\n",msg);
close(clientsocket);
}


