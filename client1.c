#include<stdio.h>

#include<netinet/in.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netdb.h>

#include<string.h>

#include<stdlib.h>

#include<unistd.h>

#include<arpa/inet.h>

#define MAX 100

#define PORT 36812

#define SA struct sockaddr

void func(int listenfd)

{

char chat[MAX];
char endingsession[]="exit";
int n;
char muslim[]="waalaikumussalam";

for(;;)

{

bzero(chat,MAX);
printf("\nTo Server : ");

n=0;
while((chat[n++]=getchar())!='\n');

write(listenfd,chat,sizeof(chat));
if(strncmp(chat,endingsession,4)==0)

{

printf("Client Exit the Connection...\n");

break;

}
bzero(chat,MAX);
read(listenfd,chat,sizeof(chat));
if(strncmp(chat,endingsession,4)==0)

{

printf("Server Exit the Connection\n");

break;

}

printf("\tFrom Server : %s",chat);
}

}
int main()

{

int listenfd=0;
int connfd=0;

struct sockaddr_in servaddr,cli;

listenfd=socket(AF_INET,SOCK_STREAM,0);



if(listenfd==-1)

{

printf("SOCKET CREATION FAILED :( !\n");

exit(0);

}

else

printf("SOCKET CREATION SUCCESS :) YEAY!!\n");



memset(&servaddr,'0',sizeof(servaddr));
servaddr.sin_family=AF_INET;

servaddr.sin_addr.s_addr=inet_addr("192.168.81.131");

servaddr.sin_port=htons(PORT);



if(connect(listenfd,(SA *)&servaddr,sizeof(servaddr))!=0)

{

printf("CONNECTION TO THE SERVER FAILED :( !\n");

exit(0);

}

else

printf("CONNECTION TO THE SERVER SUCCESS :) YEAYY!!\n");



func(listenfd);

close(listenfd);

}


 # Project
