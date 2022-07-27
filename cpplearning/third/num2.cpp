#include<iostream>
using namespace std;

class icount{
    int a,b;
    public:
        icount(const int &x=0,const int &y=0){
            a=x;
            b=y;
        }
        friend ostream & operator <<(ostream &os,const icount &c);
        friend istream & operator >>(istream &is,icount &c);
};
ostream &operator <<(ostream &os,const icount &c){
    os<<"a="<<c.a<<"\t"<<"b="<<c.b<<endl;
    return os;
}
istream & operator >>(istream &is,icount &c){
    is>>c.a>>c.b;
    return is;
}
int main(){
    icount cc(8,8);
    cout<<cc;
    cin>>cc;
    cout<<cc;
    return 0;
}