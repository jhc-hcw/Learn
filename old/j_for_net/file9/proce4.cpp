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
const int BL=5000;
void process_conn_server(int s){
    ssize_t size ={0};
    char buffer[BL];

    for(;;){
        size = recv(s,buffer,BL,0);

        if(0==size){
            return ;
        }
        //string message = string(buffer).length() +"bytes altogether\n";
        cout<<buffer<<endl;
        sprintf(buffer,"%ld bytes altogether by jhc\n",size);
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
           // send(s,buffer,size,0);
            string ss="GET /adm/getOrNot HTTP/1.1\nHost:jhc\n\n";
            send(s,ss.c_str(),ss.length(),0);
            cout<<ss.c_str()<<endl;
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