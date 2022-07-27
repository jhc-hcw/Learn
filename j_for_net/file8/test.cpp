#include <cstddef>
#include<netdb.h>
#include<string.h>
#include<iostream>
#include<arpa/inet.h>
#include <sys/socket.h>
using namespace std;

int main(){
    string host="www.google.com";
    hostent *ht=nullptr;
    char str[30];
    ht = gethostbyname(host.c_str());
    if (ht){
        int i=0;
        cout<<"get the host:"<<host<<endl;
        cout<<"name:"<<ht->h_name<<endl;
        auto s=ht->h_addrtype==AF_INET ?"AF_INET":"AFINET6";
        cout<<"type:"<<s<<endl;
        cout<<"length:"<<ht->h_length<<endl;
        for(int i=0;;i++){
            if(ht->h_addr_list[i]!=NULL){
                cout<<"IP:"<<inet_ntop(ht->h_addrtype,ht->h_addr_list[i],str,30);
            }else{
                break;
            }
        }
        for(int i=0;;i++){
            if(ht->h_aliases[i]!=NULL){
                cout<<"alias "<<i<<":"<<ht->h_aliases[i];
            }else{
                break;
            }
        }
    }
}