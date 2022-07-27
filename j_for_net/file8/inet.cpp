#include <ios>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<iostream>
#include<string.h>

using namespace std;

int main(int argc,char * argv[]){
    in_addr ip,local,network;
    string addr1="192.168.1.1";
    //char ad[]="192.168.1.1";
    string addr2="255.255.255.255";
    string addr3="192.168.1";
    string str,str2;
    auto err=inet_aton(addr1.c_str(),&ip);
    cout<<hex;
    if(err){
        cout<<"inet_atonl:string "<<addr1<<" values is :ox"<<ip.s_addr<<endl;
    }else{
        cout<<"inet_aton:string " <<addr1<<" error "<<endl;
    }
    ip.s_addr=inet_addr(addr1.c_str());
    if(ip.s_addr!=-1){
        cout<<"inet_addr:string "<<addr1<<" values is :ox"<<ip.s_addr<<endl;
    }else{
        cout<<"inet_addr:string " <<addr1<<" error "<<endl;
    }
    ip.s_addr=inet_addr(addr2.c_str());
    if(ip.s_addr!= -1){
        cout<<"inet_addr:string "<<addr2<<" values is :ox"<<ip.s_addr<<endl;
    }else{
        cout<<"inet_addr:string " <<addr2<<"error"<<endl;
    }


    ip.s_addr = 192<<24|168<<16|1<<8|1;
    str = inet_ntoa(ip);
    ip.s_addr = 255<<24|255<<16|255<<8|255;
    str2 = inet_ntoa(ip);
    cout<<"inet_ntoa:ip 0x"<<ip.s_addr<<" string1"<<str2<<",pre is"<<str<<endl;
    ip.s_addr =inet_addr(addr3.c_str());
    if(ip.s_addr!=-1){
        cout<<"inet_addr:string "<<addr3<<" values is :0x"<<ip.s_addr<<endl;
    }else{
        cout<<"inet_addr:string "<<addr3<<" error"<<endl;
    }
    str = inet_ntoa(ip);
    cout<<"inet_ntoa:string "<<str <<"ip :0x"<<ip.s_addr<<endl;
    inet_aton(addr1.c_str(),&ip);
    local.s_addr=htonl(ip.s_addr);
    local.s_addr=inet_lnaof(ip);
    str = inet_ntoa(local);
    cout<<"inet_lnaof:string "<<str<<" ip:0x"<<local.s_addr<<endl;
    network.s_addr=inet_netof(ip);
    cout<<"inet_netof:value:0x"<<network.s_addr<<endl;
    return 0;
}