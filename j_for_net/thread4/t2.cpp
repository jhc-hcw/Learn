#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    pid_t pid;

    pid=fork();
    if(-1==pid){
        cout<<"failture"<<endl;
        return -1;
    }else if(pid == 0){
        cout<<"子进程，fork返回值 ID:"<<pid<<"父进程ID："<<getpid()<<endl;
    }else{
        cout<<"父进程，fork返回值 ID:"<<pid<<"父进程ID："<<getpid()<<endl;
    }
    return 0;
}