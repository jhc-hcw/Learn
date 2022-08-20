#include<iostream>
using namespace std;

int main(){
    const int a=4;
    const int * p=&a;
    *const_cast<int*>(p)=99;
    cout<<a;
    return 0;

}