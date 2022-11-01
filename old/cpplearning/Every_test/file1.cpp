#include<iostream>
using namespace std;

int main(){
    int a=8;
    int *aa=&a;
    int b=23;
    int *bb=&b;
    a=a ^ b;
    b=b ^ a;
    a=b ^ a;
    cout<<a<<endl;
    cout<<b<<endl;
}