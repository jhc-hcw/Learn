#include<iostream>
using namespace std;

template<typename Tg>
void func(Tg* a){
    *a=19;
    cout<<a;
}
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
    // jhc jj(33);
    // jhc jc(jj);
    // jhc jp;
    // int *a[99];
    // int b;
    // a[0]=&b;
    // *a[0]=999;
    // cout<<*a[0];
    const int csint=8;
    const int*ptn=&csint;
    int iint=99;
    int *castint=const_cast<int*>(ptn);
    *castint=9999;
    cout<<*castint<<"numoa"<<iint<<endl;
    func(&iint);
    //func(&csint)
    return 9;
}