#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<linux/in.h>
#include<iostream>
#include<string>
using namespace std;
static const int PORT =8888;

static const int BACKLOG=2;
void process_conn_server(int s);

int main(int argc,char *argv[]){
    int ss,sc;
    sockaddr_in server_addr;
    sockaddr_in client_addr;
    int err;
    pid_t pid;
    ss=socket(AF_INET,SOCK_STREAM,0);
    if(ss<0){
        cout<<"socket eror\n";
        return -1;
    }
    bzero(&server_addr,sizeof(server_addr));
    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=__constant_htonl(INADDR_ANY);
    server_addr.sin_port=__constant_htons(PORT);
    err=bind(ss,(sockaddr*)&server_addr,sizeof(server_addr));
    if(err<0){
        cout<<"bind error\n"<<endl;
        return -1;
    }
    err=listen(ss,BACKLOG);
    if(err<0){
        cout<<"listen error\n"<<endl;
        return -1;
    }
    for(;;){
        socklen_t addrlen=sizeof(sockaddr);
        sc=accept(ss,(sockaddr*) &client_addr,&addrlen);
        if(sc<0){
            continue;
        }
        pid=fork();
        if(pid==0){
            close(ss);
            process_conn_server(sc);
        }else{
            close(sc);
        }
    }
}
void process_conn_server(int s){
    size_t size=0;
    char buffer[1024];
    for(;;){
        size =read(s,buffer,1024);
        if(size==0){
            return ;
        }
        sprintf(buffer,"%ld butes altogether\n",size);
        write(s,buffer,strlen(buffer)+1);
    }
}