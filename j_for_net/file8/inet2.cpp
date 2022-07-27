#include <netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<iostream>
using namespace std;
static const int ADDRLEN =16;
int main(){
    in_addr ip;
    string ipstr="192.168.1.1";
    char addr[ADDRLEN];
    string str;
    auto err=inet_pton(AF_INET,ipstr.c_str(),&ip);
    if(err>0){
        cout<<"inet_pton:ip,"<<ipstr<<" value is 0x"<<hex<<ip.s_addr<<endl;
    }
    ip.s_addr = htonl(192<<24|168<<16|12<<8|255);
    str=inet_ntop(AF_INET,(void*)&ip,addr,ADDRLEN);
    if(!str.empty()){
        cout<<"inet_ntop:ip,0x"<<ip.s_addr<<" is "<<str<<endl;
    }
    return 0;
}