#include<iostream>
using namespace std;

class A{
    int a,b;
    public :
    int uu=99;
    A(int x,int y){
        a=x;b=y;
    }
};
class B:public A{
    int c;
    public:
    B(int x,int y):A(x,y){
        c=y;
    }
    void printff(){
        cout<<c<<this->uu<<endl;
    }
};
int main(){
    return 0;
}