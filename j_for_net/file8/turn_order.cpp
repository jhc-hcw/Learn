#include<iostream>
#include<arpa/inet.h>
#include <netinet/in.h>
using namespace std;
union to16 {
    unsigned short int value;
    unsigned char byte[2];
};

union to32{
    unsigned long int value;
    unsigned char byte[4];
};

const static int BITS16 = 16;
const static int BITS32 = 32;

void showvalue(unsigned char * begin, int flag){
    int num=0, i=0;
    if(flag == BITS16){
        num = 2;
    }else if(flag == BITS32){
        num =4;
    }
    for(int i=0;i<num;i++){
        cout<<hex<<(unsigned  int)*(begin+i)<<" ";
    } 
    cout<<endl;
}

int main(int argc,char *argv[]){
    to16 v16_orig,v16_turn1,v16_turn2;
    to32 v32_orig,v32_turn1,v32_turn2;

    v16_orig.value = 0xabcd;
    v16_turn1.value = htons(v16_orig.value);
    v16_turn2.value = ntohs(v16_turn1.value);

    v32_orig.value= 0x12345678;
    v32_turn1.value = htonl(v32_orig.value);
    v32_turn2.value=ntohl(v32_turn1.value);

    cout<<"16 host to network byte order change : "<<endl;
    cout<<"\torig:";showvalue(v16_orig.byte,BITS16);
    cout<<"\t1 times:";showvalue(v16_turn1.byte, BITS16);
    cout<<"\t2 times:";showvalue(v16_turn2.byte,BITS16);

    cout<<"32 host to network byte order change : "<<endl;
    cout<<"\torig:";showvalue(v32_orig.byte,BITS32);
    cout<<"\t1 times:";showvalue(v32_turn1.byte, BITS32);
    cout<<"\t2 times:";showvalue(v32_turn2.byte,BITS32);

    return 0;
}
