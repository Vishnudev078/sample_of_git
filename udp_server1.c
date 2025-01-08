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
int num,fact=1;
serversocket=socket(AF_INET,SOCK_DGRAM,0);
bzero((char*)&serveraddr,sizeof(serveraddr));
serveraddr.sin_family=AF_INET;
printf("Enter the port number");
scanf("%d",&port);
serveraddr.sin_addr.s_addr=INADDR_ANY;
serveraddr.sin_port=htons(port);
bind(serversocket, (struct sockaddr*)&serveraddr, sizeof(serveraddr));
len = sizeof(clientaddr);
recvfrom(serversocket, &num, sizeof(num), 0, (struct sockaddr*)&clientaddr, &len);
printf("Connection recieved from client");
printf("\nMessage received: %d\n", num);
for(int i=1;i<=num;i++){
 fact=fact*i;
}
printf("Factorial is %d\n",fact);
sendto(serversocket,&fact, sizeof(fact), 0, (struct sockaddr*)&clientaddr, len);
close(serversocket);
}
