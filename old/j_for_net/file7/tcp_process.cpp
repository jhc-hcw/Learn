#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<iostream>
using namespace std;

void process_conn_client(int s){
    ssize_t size=0;
    char buffer[1024];

    for(;;){
        size=read(0,buffer,1024);
        if(size>0){
            write(s,buffer,size);
            size=read(s,buffer,1024);
            cout<<buffer<<endl;
        }
    }
}

void process_conn_server(int s){
    ssize_t size=0;
    char buffer[1024];
    for(;;){
        size = read(s,buffer,1024);
        if(size ==0){
            return  ;
        }
        if(size>0)
        cout<<"接受到信息："<<buffer<<endl;
        sprintf(buffer,"%ld bytes altogether\n", size);
        write(s,buffer,strlen(buffer)+1);
    } 
}