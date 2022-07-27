#include<netdb.h>
#include<string>
#include<iostream>
using namespace std;

int main(){
    char* host="www.baidu.com";
    hostent *ht=nullptr;
    ht=gethostbyname(host);
    if(ht){
        int i=0;
        cout<<"get the host :"<<host<< "addr"<<endl;
        cout<<"name:"<<ht->h_name<<endl;
        cout<<"type:"<< ht->h_addrtype  <<endl;
        cout<<"length:"<<ht->h_length<<endl;
    }
    return 0;
}