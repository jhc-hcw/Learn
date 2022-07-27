#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

using namespace std;
static const int PORT = 8888;
static const int BACKLOG=2;


void process_conn_server(int s);

int main(int argc,char *argv[]){
    int sc;
    sockaddr_in server_addr={0},clien_addr={0};
    pid_t pid;
    auto ss=socket(AF_INET,SOCK_STREAM,0);
    if(ss<0){
        cout<<"socket error"<<endl;
        return -1;
    }
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htons(PORT);

    auto err=bind(ss,(sockaddr *)&server_addr,sizeof(server_addr));
    if(err<0){
        cout<<"bind error"<<endl;
        return -1;
    }
    err=listen(ss,BACKLOG);
    if(err<0){
        cout<<"listen error"<<endl;
        return -1;
    }
    for(;;){
        socklen_t addrlen=sizeof(sockaddr);
        sc=accept(ss,(sockaddr *)&clien_addr,&addrlen);
        if(ss<0){
            continue;
        }
        pid=fork();
        if(pid == 0){
            process_conn_server(sc);
            close(ss);
        }else{
            close(ss);
        }
    }
}