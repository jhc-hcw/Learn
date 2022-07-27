#include<iostream>
using namespace std;

class A{
    int a;
    public :
    A(int aa){
        cout<<"没想到吧我先来"<<endl;
        a=aa;
    }
    int & getA(){
        return a;
    }
    ~A(){
        cout<<"我死了！"<<endl; 
    }
};
A a1(33);
int main(){
    A a(99);
    int aa=a.getA();
    cout<<aa<<endl;
    aa=9999;
    int &pp=a.getA();
    pp=777;
    cout<<a.getA()<<endl;
    a.getA()=888;
    cout<<a.getA()<<endl;
    cout<<pp<<endl;
    return 0;
}