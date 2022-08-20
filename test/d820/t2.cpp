#include<iostream>
using namespace std;

class jhc{
    public:
    int a;
    jhc(int b=0):a(b){
        cout<<"construct"<<endl;
    }
    jhc(jhc &j){
        j.a=a;
        cout<<"copyconstruct"<<endl;
    }
    jhc& operator=(jhc &rhs)=delete;
};
int main(){
    jhc jj(33);
    jhc jc(jj);
    jhc jp;
    int *a[99];
    int b;
    a[0]=&b;
    *a[0]=999;
    cout<<*a[0];
    return 9;
}