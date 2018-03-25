// this is for the server. as for the client i used the same as assigment 1 
#include<stdio.h>

#include<netinet/in.h>

#include<sys/types.h>

#include<sys/socket.h>

#include<netdb.h>

#include<string.h>

#include<stdlib.h>

#include<arpa/inet.h>

#include<unistd.h>

#include<sys/ioctl.h>
#include<net/if.h>
#include<time.h>
#define MAX 100

#define PORTNUMBER 36812

#define SA struct sockaddr

void func(int listenfd)



{

//int connfd =0;

char chat[MAX];

    char hostbuffer[256];

    char *IPbuffer;

    struct hostent *host_entry;
   // int sock=socket(AF_NET,SOCK_STREAM,0);
    	
	struct ifreq ifr;
	ifr.ifr_addr.sa_family=AF_INET;
    int hostname;

// To retrieve hostname

    hostname = gethostname(hostbuffer, sizeof(hostbuffer));

  //  checkHostName(hostname);

 

    // To retrieve host information

    host_entry = gethostbyname(hostbuffer);

    //checkHostEntry(host_entry);

 

    // To convert an Internet network

    // address into ASCII string

    IPbuffer = inet_ntoa(*((struct in_addr*)

                           host_entry->h_addr_list[0]));


strcpy(ifr.ifr_name,"em0");
time_t ticks;
char info1[]="ipaddress";
char info2[]="hostname";
char info3[]="mtu";
//char info4[]="time";
int n;

for(;;)

{

bzero(chat,MAX);

read(listenfd,chat,MAX);

printf("\nFrom client: %s",chat);

if(strncmp(chat,info1,9)==0)

{

	//char chat[]="waalaikumussalam";
	strcpy(chat,IPbuffer);
	write(listenfd,chat,sizeof(chat));
	printf("\t To client :%s ",chat);

}

else if(strncmp(chat,info2,8)==0)
{

	//char chat[]="are you a muslim";
	strcpy(chat,hostbuffer);
	write(listenfd,chat,sizeof(chat));
	printf("\t To client :%s ",chat);
	char setname[]="nhishak.localdomain";
	sethostname(setname,sizeof(setname));

}
else if(strncmp(chat,info3,3)==0)
{
	int mtu=ifr.ifr_mtu;
	sprintf(chat,"%d",mtu);
	write(listenfd,chat,sizeof(chat));
	printf("\t To Client: %s",chat);
	ifr.ifr_mtu=512;
}

//else if(strncmp(chat,info4,4)==0)
//{
	//connfd = accept(listenfd,(struct sockaddr*)NULL,NULL);
	//ticks =time(NULL);
	//sprintf(chat,"%.24s\r\n",ticks);
	//write(listenfd,chat,sizeof(chat));
	//printf("\t To Client: %s",chat);
//}
else
{
	char chat[]= "No info about that";
	write(listenfd,chat,sizeof(chat));
	printf("\t To client: %s",chat);
}

bzero(chat,MAX);
n=0;

while((chat[n++]=getchar())!='\n');



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


