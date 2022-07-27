#include<iostream>
using namespace std;
class A{
    int a,b;
    public :
    A(int a,int b){
        this->a=a;
        this->b=b;
    }
    void getA(int *a){
        //a=&this->a;
        *a=this->a;
    }
    void setb(int &b){
        b=this->b;
    }
    int getb(){
        return b;
    }
};

int main(){
    A a(88,99);
    int p,x;
    a.getA(&p);
    a.setb(x);
    cout<<x<<endl;
    x=100;
    cout<<x<<endl;
    cout<<a.getb()<<endl;
    cout<<p<<endl;
    return 0;
}