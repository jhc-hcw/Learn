#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<iostream>
#include<stdio.h>
#include<unistd.h>
using namespace std;

const int PORT_SERVER = 8888;
const int BUFF_LEN= 256;
static void udpcliet_echo(int s,sockaddr* to){
    char buffer[BUFF_LEN]="UDP JHC";
    sockaddr_in from;
    socklen_t len=sizeof(*to);
    sendto(s,buffer,BUFF_LEN,0,to,len);
    recvfrom(s,buffer,BUFF_LEN,0,(sockaddr *)&from,&len);

    cout<<"recved:"<<buffer<<endl;
}
int main(int argc,char *argv[]){
	int s;
	sockaddr_in addr_server={0};
	s=socket(AF_INET,SOCK_DGRAM,0);
	addr_server.sin_family = AF_INET;
    addr_server.sin_addr.s_addr = htonl(INADDR_ANY);
    addr_server.sin_port = htons(PORT_SERVER);

    udpcliet_echo(s,(sockaddr*)&addr_server);

    close(s);
    return 0;
	
}