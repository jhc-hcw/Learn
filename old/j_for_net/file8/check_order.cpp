#include<iostream>
#include<stdio.h>
using namespace std;

union to{
    unsigned short int value;
    unsigned char byte[2];
};
int main(){
    to typeorder;
    typeorder.value=0xabcd;
    if(typeorder.byte[0]==0xcd && typeorder.byte[1] == 0xab){
        cout<<hex;
        cout<<"Low endian byte order"<<"byte[0]:0x"<<(unsigned int)typeorder.byte[0]<<" byte[1]:0x"<<(unsigned int)typeorder.byte[1];
    }
    if(typeorder.byte[0]==0xab && typeorder.byte[1] == 0xcd){
        cout<<"High endian byte order"<<"byte[0]:0x"<<(unsigned int)typeorder.byte[0]<<" byte[1]:0x"<<(unsigned int)typeorder.byte[1];
    }
    // cout<<sizeof(short int);
    // cout<<hex;
    // cout<<(unsigned int)typeorder.byte[0]<<"   "<<(unsigned int)typeorder.byte[1]<<endl;
    // cout<<typeorder.value<<endl;
    // printf("%x",typeorder.byte[1]);
    return 0;
}