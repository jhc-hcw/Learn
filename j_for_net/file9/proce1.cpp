#include <cstdio>
#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<signal.h>
using namespace std;
const int BL=1024;
void process_conn_server(int s){
    ssize_t size ={0};
    char buffer[BL];

    for(;;){
        size = recv(s,buffer,BL,0);

        if(0==size){
            return ;
        }
        //string message = string(buffer).length() +"bytes altogether\n";
        sprintf(buffer,"%ld bytes altogether\n",size);
        send(s,buffer,strlen(buffer),0);
    }
    return ;
}

void process_conn_client(int s){
    ssize_t size =0;
    char buffer[BL];

    for(;;){
        size = read(0 , buffer , BL);

        if(size >0 ){
            send(s,buffer,size,0);
            size = recv(s,buffer,BL,0);
            write(1,buffer,size);
        }
    }
}

void sig_process(int signo){
    cout<<"Catch a exit signa"<<endl;
    _exit(0);
}

void sig_pipe(int sign){
    cout<<"Catch a SGPIP signal"<<endl;
    return ;
}