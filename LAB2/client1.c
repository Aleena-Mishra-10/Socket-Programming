#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>

int main(){
int cs,bs;
cs=socket(AF_INET,SOCK_DGRAM,0);
struct sockaddr_in x;
x.sin_family=AF_INET;
x.sin_port=ntohs(6009);

x.sin_addr.s_addr=inet_addr("127.0.0.1");

bind(cs,(struct sockaddr *)&x,sizeof(x));
struct sockaddr_in tempsenderaddr;
char buf[100];
int len=sizeof(struct sockaddr);
recvfrom(cs,buf,100,0,(struct sockaddr *)&tempsenderaddr,&len);
printf("Recieve message: %s",buf);
}
