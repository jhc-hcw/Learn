#include<iostream>
#include<stack>
using namespace std;


void print_bit(unsigned int num){
    stack<unsigned int> s;
    unsigned int n;
    unsigned int size=1;
    unsigned int changed =0;
    for(int i=0;i<32;i++){
        changed+=(num & size);
        size=size<<1;
    }
    size=1;
    for(int i=0;i<32;i++){
        unsigned int temp=changed & size;
        s.push(temp);
    }
    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }
}

int main(){
    unsigned int size=1;
    int neg=1;
    unsigned int num=0;
    print_bit(neg);
    //cout<<num;
}