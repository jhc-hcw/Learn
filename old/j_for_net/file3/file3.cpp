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
    static const string buf="quick brown fox jumps over the lazy dog";
    const static string filename="test.txt";

    fd=open(filename.c_str(),O_RDWR);
    if(fd==-1){
        cout<<"error" <<endl;
        return -1;
    }else{
        cout<<"open the file fd:"<<fd<<endl;
    }

    size=write(fd,buf.c_str(),buf.length());
    cout<<"write"<<size<<"bytes to file"<<endl;
    close(fd);
    return 0;
}