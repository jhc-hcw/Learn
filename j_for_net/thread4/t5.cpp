#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;


int main(){
    int result=-1;
    int fd[2],nubytes;
    pid_t pid;
    char string[]="hellow pipe!";
    char readbuffer[80];
    int *write_fd=fd+1;
    int *read_fd=fd;
    
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
    if(0==pid){
        close(*read_fd);
        result=write(*write_fd,string,strlen(string));
        return 0;
    }else{
        close(*write_fd);
        nubytes=read(*read_fd,readbuffer,sizeof(readbuffer));
        cout<<"recevie "<<nubytes<<" byte  and content is "<<readbuffer<<endl;
        printf("接收到%d个数据，内容为:”%s“\n",nubytes,readbuffer);	
    }
    return 0;

}