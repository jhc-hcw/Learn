#include<iostream>
using namespace std;


template<typename T>
T abs(T x){
    T y;
    y=x<0?-x:x;
    return y;
}
int main(){
    int n=-5;
    double d=-5.5;
    cout<<abs(n)<<endl;
    cout<<abs(d)<<endl;
    cout<<"我是回车王";
    return 0;
}