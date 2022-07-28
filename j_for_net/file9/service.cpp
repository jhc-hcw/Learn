#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<signal.h>
using namespace std;
extern void sig_process(int signo);
void process_conn_server(int s);
const extern int PORT= 8888;
const extern int BACKLOG =2;
int main(int argc, char *argv[]){
    int sc;
    sockaddr_in server_addr={0},client_addr={0};

    signal(SIGINT,sig_process);
    signal(SIGPIPE,sig_process);

    auto ss=socket(AF_INET,SOCK_STREAM,0);
    if(ss<0){
        cout<<"socket error!"<<endl;
        return -1;
    }

    server_addr.sin_family=AF_INET;
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
    server_addr.sin_port=htons(PORT);

    auto err=bind(ss,(sockaddr*)&server_addr,sizeof(server_addr));
    if(err<0){
        cout<<"bind error!"<<endl;
        return -1;
    }
    listen(ss,BACKLOG);
    if(err<0){
        cout<<"listen error"<<endl;
        return -1;
    }

    for(;;){
        socklen_t addrlen = sizeof(sockaddr);

        auto sc= accept(ss,(sockaddr*)&client_addr,&addrlen);
        if(sc<0){
            continue;
        }
        auto pid=fork();
        if(pid==0){
            close(ss);
            process_conn_server(sc);

        }else{
            close(sc);
        }
        
    }
}