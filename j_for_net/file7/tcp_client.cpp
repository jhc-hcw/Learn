#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
using namespace std;
static const int PORT=8080;
void process_conn_client(int s);
int main(int argc,char *argv[]){
    sockaddr_in server_addr={0};
    auto s=socket(AF_INET,SOCK_STREAM,0);
    if(s<0){
        cout<<"socket error"<<endl;
        return -1;
    }
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htons(PORT);

    inet_pton(AF_INET,argv[1],&server_addr.sin_addr);
    connect(s,(sockaddr*)&server_addr,sizeof(sockaddr));
    process_conn_client(s);
    close(s);
    return 0;
}