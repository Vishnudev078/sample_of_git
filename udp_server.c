#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<netdb.h>
int main(){
int serversocket,port;
struct sockaddr_in serveraddr,clientaddr;
struct hostnet*server;
socklen_t len;
char msg[50];
serversocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
printf("Enter the port number");
scanf("%d",&port);
serveraddr.sin_addr.s_addr=INADDR_ANY;
serveraddr.sin_port=htons(port);
bind(serversocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
len = sizeof(clientaddr);
recvfrom(serversocket, msg, sizeof(msg), 0, (struct sockaddr*)&clientaddr, &len);
printf("Connection recieved from client");
printf("\nMessage received: %s\n", msg);
sendto(serversocket, "HI I AM SERVER", sizeof("HI I AM SERVER"), 0, (struct sockaddr*)&clientaddr, len);
close(serversocket);
}
