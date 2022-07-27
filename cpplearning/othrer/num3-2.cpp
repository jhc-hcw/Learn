#include<iostream>
using namespace std;

class A{
    int i;
    public:
        A(int a=0){
            i=a;
        }
        void show(){
            cout<<"i="<<i<<endl;
        }
        void AddA(A &a1,A &a2){
            i=a1.i+a2.i;
        }
        A operator +(A &a){
            A t;
            t.i=i+a.i;
            return t;
        }
};

int main(){
    A a1(10),a2(20),a3;
    a1.show();
    a2.show();
    a3=a1+a2;
    a3.show();
    return 0;
}