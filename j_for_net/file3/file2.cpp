#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<iostream>
using namespace std;

int main(){
    int fd=-1;
    ssize_t size=-1;
    char buf[10];
    static const string filename="test.txt";

    fd=open(filename.c_str(),O_RDONLY);
    if(-1==fd){
        cout<<"failure"<<endl;
    }else{
        cout<<"success fd:"<<fd<<endl;
    }

    while(size){
        size=read(fd,buf,10);
        if(-1==size){
            close(fd);
            cout<<"read error"<<endl;
            return -1;
        }else{
            if(size>0){
                cout<<"read"<<size<<"bytes"<<endl;
                cout<<buf<<endl;

            }else{
                cout<<"read end of file"<<endl;
            }
        }
    }
    return 0;
}