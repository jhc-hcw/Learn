#include<iostream>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<signal.h>
using namespace std;
extern void sig_process(int signo);
extern void sig_pipe(int signo);
static const s;
void sig_process_client(int signo){
    cout<<"Catch a exit signal"<<endl;
    close(s);
    exit(0);
}
int main(int argc,char * argv[]){
    
}