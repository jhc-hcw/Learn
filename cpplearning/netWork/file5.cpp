#include<iostream>
using namespace std;
union to{
    unsigned short int value;
    unsigned char byte[2];
};
int main(){
    to typeorder;
    typeorder.value=0xabcd;
    if(typeorder.byte[0]==0xab && typeorder.byte[1]==0xcd){
        cout<<"yes";
    }else if(typeorder.byte[0]==0xcd  && typeorder.byte[1]==0xab){
        cout<<"no";
    }
}