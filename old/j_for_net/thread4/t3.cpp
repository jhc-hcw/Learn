#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main(){
    int ret;

    cout<<"系统分配的进程号是“："<<getpid()<<endl;
    ret=system("ls");
    cout<<"返回值为："<<ret<<endl;
    return 0;
}