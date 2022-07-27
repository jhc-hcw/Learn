#include<iostream>
using namespace std;

void change(int *p,int *o){
    int *t=p;
    t=o;
}


int main(){
    int a=0;
    int b=99;
    change(&a,&b);
    int *p=new int(33);
    delete(p);
    if(!p){
        cout<<"yes"<<endl;
    }
    cout<<a;
}
