#include<iostream>
using namespace std;

template<typename Tg>
void func(Tg* a){
    cout<<a<<endl;
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
    const int const_int=8;
    const int*ptn=&const_int;
    int *p=const_cast<int*>(ptn);
    func(&const_int);
    func(p);
    func(&const_int);
    func(ptn);
    *p=99;
    cout<<&*p<<endl;
    cout<<const_int<<endl;
    int i = 3;                 // 不声明 i 为 const
    const int& rci = i; 
    const_cast<int&>(rci) = 4; // OK：修改 i
    std::cout << "i = " << i << '\n';

    return 9;
}