#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
#include<stdio.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main(int argc,char *argv[]){
    int s;
    sockaddr_in addr_serv={0};
    sockaddr_in local;
    socklen_t len=sizeof(local);

    s=socket(AF_INET,SOCK_DGRAM,0);
    addr_serv.sin_family=AF_INET;
    addr_serv.sin_addr.s_addr=inet_addr("127.0.0.1");
    addr_serv.sin_port=htons(8888);

    connect(s,(sockaddr*)&addr_serv,sizeof(addr_serv));

    getsockname(s,(sockaddr*)&local,&len);
    cout<<"UDP local addr:"<<inet_ntoa(local.sin_addr)<<endl;

    close(s);
    return 0;
}