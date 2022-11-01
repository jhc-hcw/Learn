#include<iostream>
using namespace std;

template<class T>
void putArray(const T *P_array,const int count){
    for(int i=0;i<count;i++){
        cout<<P_array[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int *ptr=new int(10);
    cout<<"我是"<<*ptr<<endl;
    delete ptr;
    int *p=new int[8];
    delete []p;
    int a[8]={1,2,3,4,5,6,7,8};
    double b[]={1.1,1.2,1.3,1.4,1.5,1.6,1.7,1.8,1.9};
    putArray(a,8);
    putArray(b,sizeof(b)/sizeof(double));
    return 0;
}