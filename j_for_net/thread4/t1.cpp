#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<iostream>
using namespace std;

int main(){
    pid_t pid,ppid;

    pid=getpid();
    ppid=getppid();
    cout<<"current thread ID is"<<pid<<endl;
    cout<<"current thread father's ID is "<<ppid<<endl;
    return 0;
}