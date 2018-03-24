#include<stdio.h>

#include<netinet/in.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netdb.h>

#include<string.h>

#include<stdlib.h>

#include<arpa/inet.h>

#include<unistd.h>

#define MAX 100

#define PORTNUMBER 36812

#define SA struct sockaddr

void func(int listenfd)

{

char chat[MAX];
char endingsession[]="exit";
char muslim[]="assalamualaikum";
char nonmuslim[]="hai";

int n;

for(;;)

{

bzero(chat,MAX);
read(listenfd,chat,MAX);
if(strncmp(chat,endingsession,4)==0)

{

printf("Client Exit the Connection\n");

break;

}
if(strncmp(chat,muslim,15)==0)
{
char chat[]="waalaikumussalam";
write(listenfd,chat,sizeof(chat));
}
if(strncmp(chat,nonmuslim,3)==0)
{
char chat []="are you a muslim?";
write(listenfd,chat,sizeof(chat));
}

printf("From client: %s\t To client : ",chat);
bzero(chat,MAX);
n=0;

while((chat[n++]=getchar())!='\n');

write(listenfd,chat,sizeof(chat));

if(strncmp(endingsession,chat,4)==0)

{

printf("Server Exit the Connection\n");

break;

}

}

}

int main()

{

int listenfd,connfd,len;

struct sockaddr_in servaddr,cli;

listenfd=socket(AF_INET,SOCK_STREAM,0);



if(listenfd==-1)

{

printf("SOCKET CREATON FAIL :( !\n");

exit(0);

}

else

printf("SOCKET SUCCESSFULLY CREATED :)!.\n");

memset(&servaddr,'0',sizeof(servaddr));
servaddr.sin_family=AF_INET;

servaddr.sin_addr.s_addr=htonl(INADDR_ANY);

servaddr.sin_port=htons(PORTNUMBER);



if((bind(listenfd,(SA*)&servaddr, sizeof(servaddr)))!=0)

{

printf("SOCKET BIND FAILED :( !\n");

exit(0);

}

else

printf("SOCKET SUCCESSFULLY BIND :) !\n");




if((listen(listenfd,5))!=0)

{

printf("LISTEN FAILED :( !\n");

exit(0);

}

else

printf("SERVER LISTENING :) !!...\n");

len=sizeof(cli);

connfd=accept(listenfd,(SA *)&cli,&len);

if(connfd<0)

{

printf("server acccept failed...\n");

exit(0);

}

else

printf("server acccept the client...\n");



func(connfd);

close(listenfd);

}




 # Project
 # Project
