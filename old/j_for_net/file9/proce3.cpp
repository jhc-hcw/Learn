#include <cstddef>
#include <cstdio>
#include<iostream>
#include <ostream>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<signal.h>
#include<sys/uio.h>
#include<stdio.h>
using namespace std;
static iovec * vs =nullptr,*vc=nullptr;
const int BL=1024;
void process_conn_server(int s){
    char buffer[30];
    ssize_t size ={0};
    msghdr msg;

    iovec *v = new iovec[3];
    if(!v){
        cout<<"error to allocate memory";
        return ;
    }
    vs =v;

    msg.msg_name = nullptr;
    msg.msg_namelen =0;
    msg.msg_control = nullptr;
    msg.msg_controllen = 0;
    msg.msg_iov = v;
    msg.msg_iovlen=30;
    msg.msg_flags =0;

    v[0].iov_base=buffer;
    v[1].iov_base = buffer +10;
    v[2].iov_base = buffer +20;
    v[0].iov_len = v[2].iov_len=v[1].iov_len=10;

    for(;;){
        size = recvmsg(s,&msg,0);
        if(0 == size ){
            return ;
        }

        sprintf((char *)v[0].iov_base,"%ld  ", size);
        sprintf((char *)v[1].iov_base,"bytes alt");
        sprintf((char *)v[2].iov_base,"ogether\n");
        v[0].iov_len=strlen((char *)v[0].iov_base);
        v[1].iov_len=strlen((char *)v[1].iov_base);
        v[2].iov_len=strlen((char *)v[2].iov_base);
        sendmsg(s,&msg, 0);

    }

        
}

void process_conn_client(int s){
    char buffer[30];
    ssize_t size={0};
    msghdr msg;

       iovec *v = new iovec[3];
    if(!v){
        cout<<"error to allocate memory";
        return ;
    }
    vs =v;

    msg.msg_name = nullptr;
    msg.msg_namelen =0;
    msg.msg_control = nullptr;
    msg.msg_controllen = 0;
    msg.msg_iov = v;
    msg.msg_iovlen=30;
    msg.msg_flags =0;

    v[0].iov_base=buffer;
    v[1].iov_base = buffer +10;
    v[2].iov_base = buffer +20;
    v[0].iov_len = v[2].iov_len=v[1].iov_len=10;

    for(;;){
        size = read(0, v[0].iov_base,10);
        if(size > 0){
            v[0].iov_len = size;
            sendmsg(s,&msg,0);
            v[0].iov_len = v[1].iov_len = v[2].iov_len = 10;
            size = recvmsg(s,&msg,0);  
            for(int i=0;i<3;i++){
                if(v[i].iov_len> 0){
                    write(1,v[i].iov_base,v[i].iov_len);
                } 
            }
        }
    }
}

void sig_process(int signo){
    cout<<"Catch a exit signa"<<endl;
    delete [] vc;
    delete [] vs;
    _exit(0);

}

void sig_pipe(int sign){
    cout<<"Catch a SIGPIP signal"<<endl;
    delete [] vc;
    delete [] vs;
    _exit(0);
}