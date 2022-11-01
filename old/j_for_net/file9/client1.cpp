#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<signal.h>
#include<arpa/inet.h>
using namespace std;
extern void sig_process(int signo);
extern void sig_pipe(int signo);
extern void process_conn_client(int s);
static int s;
void sig_process_client(int signo){
    cout<<"Catch a exit signal"<<endl;
    close(s);
    exit(0);
}
const static int PORT=8888;
int main(int argc,char * argv[]){
    sockaddr_in server_addr={0};
    int err;
    if(argc==1){
        cout<<"PLS input server addr"<<endl;
        return 0;
    }
    signal(SIGINT,sig_process);
    signal(SIGPIPE,sig_pipe);
    s=socket(AF_INET,SOCK_STREAM,0);
    if(s<0){
        cout<<"socket error"<<endl;
        return -1;
    }
    server_addr.sin_addr.s_addr=htonl(INADDR_ANY);;
    server_addr.sin_family=AF_INET;
    server_addr.sin_port=htons(PORT);
    inet_pton(AF_INET,argv[1],&server_addr.sin_addr);
    connect(s,(sockaddr *)&server_addr,sizeof(sockaddr));
    process_conn_client(s);
    close(s);
}