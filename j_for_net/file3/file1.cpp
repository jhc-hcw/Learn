#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    int fd=-1;
    fd=open("test.txt",O_RDWR);
    if(-1==fd){
        cout<<"open file failure"<<"test.txt"<<"fd:"<<fd<<endl;
    }else{
        cout<<"open file success,fd :"<<fd<<endl;
    }
    return 0;
}