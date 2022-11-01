#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<iostream>
#include<sys/mman.h>
#include<string.h>
using namespace std;

int main(){
    int fd=-1;
    string buf="quick brown fox jumps over the lazy dog";
    char buf1[]="quick brown fox jumps over the lazy dog";
    char *ptr=nullptr;
    static const int FILELENGTH=80;

    fd=open("mmap.txt",O_RDWR|O_CREAT|O_TRUNC,S_IRWXU);
    if(-1==fd){
        return -1;
    }
    lseek(fd,FILELENGTH-1,SEEK_SET);
    write(fd,"a",1);

    ptr=(char*)mmap(nullptr,FILELENGTH,PROT_READ|PROT_WRITE,MAP_SHARED,fd,0);
    if(ptr==nullptr || (char*)-1==ptr){
        cout<<"mmap failure"<<endl;
        close(fd);
        return -1;
    }
   // memcpy(ptr+16,buf.c_str(),buf.length());
    memcpy(ptr+16,buf1,strlen(buf1));
    munmap(ptr,FILELENGTH);
    close(fd);
    return 0;
}