#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    char *args[]={"/bin/ls",NULL};
    cout<<"ID： "<<getpid()<<endl;
    if(execve("/bin/ls",args,NULL)<0)
        printf("faulture");
    return 0;
}