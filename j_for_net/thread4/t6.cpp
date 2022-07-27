#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

static const int k=1024;
static const int WRITELEN=k*1024;
int main(){
    int result=-1;
    int fd[2],nbytes;
    pid_t pid;
    char string[WRITELEN]="你好，管道！";
    char readbuffer[10*k];
    int *write_fd=fd+1;
    int *read_fd=fd;

    result=pipe(fd);
    result=pipe(fd);
    if(-1==result){
        cout<<"faulure create pipe"<<endl;
        return -1;
    }
    pid=fork();
    if(-1==pid){
        cout<<"failure to fork()"<<endl;
        return -1;
    }
    if(pid==0){
        int write_size=WRITELEN;
        result=0;
        close(*read_fd);
        while(write_size>=0){
            result=write(*write_fd,string,strlen(string));
            if(result>0){
                write_size -=result;
                cout<<"写入:"<<result<<"个数据,剩余"<<write_size<<"个数据"<<endl;

            }else{
                sleep(10);
            }
        }
        return 0;
    }
    else{
        close(*write_fd);
        while(1){
            nbytes=read(*read_fd,readbuffer,sizeof(readbuffer));
            if(nbytes<=0){
                cout<<"没有数据了"<<endl;
                break;
            }
            cout<<"接收到:"<<nbytes<<"内容为"<<readbuffer<<endl;
        }
    }
    return 0;
}