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

    iovec *v =new iovec[3];
    if(!v){
        cout<<"create array error"<<endl;
        return ;
    }

    vs=v;
    v[0].iov_base=buffer;
    v[1].iov_base=buffer+10;
    v[2].iov_base=buffer+20;
    v[0].iov_len = v[2].iov_len=v[1].iov_len=10;

    for(;;){
        size = readv(s,v,3);
        if(0== size){
            return;
        }

        sprintf((char *)v[0].iov_base,"%ld  ", size);
        sprintf((char *)v[1].iov_base,"bytes alt");
        sprintf((char *)v[2].iov_base,"ogether\n");
        v[0].iov_len=string((char*)v[0].iov_base).length();
        v[1].iov_len=string((char*)v[1].iov_base).length();
        v[2].iov_len=string((char*)v[2].iov_base).length();
        write(s,v,3);

    }
        
}

void process_conn_client(int s){
    char buffer[30];
    ssize_t size={0};

    iovec * v=new iovec[3];

    if(!v){
        cout<<"error"<<endl;
        return ;
    }

    vc=v;

    v[0].iov_base=buffer;
    v[1].iov_base=buffer+10;
    v[2].iov_base=buffer+20;
    v[0].iov_len = v[2].iov_len=v[1].iov_len=10;


    for(;;){
        size = read(0,v[0].iov_base,10);
        if(size > 0){
            v[0].iov_len=size;
            writev(s,v,1);
            v[0].iov_len = v[2].iov_len=v[1].iov_len=10;
            size =readv(s,v,3);
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
    delete[] vc;
    delete[] vs;
    _exit(0);

}

void sig_pipe(int sign){
    cout<<"Catch a SIGPIP signal"<<endl;
    delete[] vc;
    delete[] vs;
    _exit(0);
}