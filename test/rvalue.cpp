#include <cstddef>
#include<iostream>
using namespace std;

struct jhc{
    int *a=nullptr;
    jhc():a(nullptr){};
    jhc(jhc const &j):a(new int(*j.a)){
        cout<<"copy construct"<<endl;
    }
    jhc(int d):a(new int(d)){
        cout<<a<<"  common"<<endl;;
    }
    jhc(jhc &&j):a(j.a){
        cout<<"rreference"<<endl;
        j.a=nullptr;
    }
    ~jhc(){
        cout<<"disconstruct"<<endl;
        delete a;
    }
};
template<typename T>  
void jhcf(T d){
    cout<<d<<endl;
    d=99;
}
int main(){
    int a=99;
    int *p=&a;
    jhc d(a);
    cout<<d.a<<" "<<*d.a<<endl;
    jhc j(move(d));
    cout<<d.a<<" "<<endl;
    cout<<j.a<<" "<<endl;
    jhc i(*p);
    return 0;
}