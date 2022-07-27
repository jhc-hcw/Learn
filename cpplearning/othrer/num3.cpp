#include<iostream>
using namespace std;

class A{
    int i;
    public:A(int a=0){
        i=a;
    }
    void show(){
        cout<<"i="<<i<<endl;
    }
    void AddA(A &a,A &b){
        i=a.i+b.i;
    }
};
int main(){
    A a1(10),a2(20),a3;
    a1.show();
    a2.show();
    a3.AddA(a1,a2);
    a3.show();
    return 0;
}