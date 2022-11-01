#include <cstddef>
#include<iostream>
#include<stdio.h>
#include <sys/select.h>
#include<sys/time.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;
int main(){
    fd_set rd;
    timeval tv;
    int err;

    FD_ZERO(&rd);
    FD_SET(0, &rd);

    tv.tv_sec=5;
    tv.tv_usec=0;

    err= select(1,&rd,NULL,NULL,&tv);
    if(err==-1){
        perror("select");

    }else if(err){
        cout<<"data is available now"<<endl;
    }else{
        cout<<"no data within five seconds."<<endl;
    }
    return 0;
}