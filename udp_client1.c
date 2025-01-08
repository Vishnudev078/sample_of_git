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
int n,result;
clientsocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
len=sizeof(serveraddr);
serveraddr.sin_family=AF_INET;
printf("Enter the port number");
scanf("%d",&port);
serveraddr.sin_port=htons(port);
printf("Enter the number to calculate");
scanf("%d",&n);
printf("Sending msgs for server connection\n");
sendto(clientsocket,&n,sizeof(n),0,(struct sockaddr*)&serveraddr,sizeof(serveraddr));
printf("Recieving fact from server\n");
recvfrom(clientsocket,&result,sizeof(result),0,(struct sockaddr*)&serveraddr,&len);
printf("Factorial rcvd :\t %d\n",result);
close(clientsocket);
}
