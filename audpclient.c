#include <stdio.h>

#include <string.h>

#include <stdlib.h>

#include <sys/socket.h>

#include <sys/types.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#define port 7777
int main()

{

int listenfd,r;

char buff[1024];

struct sockaddr_in servaddr,cliaddr;

socklen_t servlen;

listenfd = socket(AF_INET,SOCK_DGRAM,0);

if(listenfd==-1)

{

perror("Socket");

return 0;

}

//printf("\n Enter the port no:");

//scanf("%d",&port);

//printf("The port no is:%d\n",port);

servaddr.sin_family = AF_INET;

servaddr.sin_port = htons(port);

servaddr.sin_addr.s_addr =inet_addr("192.168.81.131");

sendto(listenfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,sizeof(servaddr));

r=recvfrom(listenfd,buff,sizeof(buff),0,(struct sockaddr*)&servaddr,&servlen);

buff[r]=0;

printf("\n The time received from the server:%s\n",buff);

exit(0);

return 0;

}
