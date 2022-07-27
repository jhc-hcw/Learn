#include<iostream>
using namespace std;


void cc(){
    int i=0;
    int j=1,sum=1;
    cout << sum << " "<< endl;
    for(int k=0;k<20;k++){
        sum=i+j;
        i=j;
        j=sum;
        cout << sum << " "<< endl;
    }
}
int fib(int n){
    if(n<=2) return 1;
    return fib(n-1)+fib(n-2);
}

void dd(int i,int j,int n,int s){
    int sum=i+j;
    if(n<s){
        // cout << j << endl;
        i=j;
        j=sum;
        n++;
        dd(i,j,n,s);
    }else{
        cout << j << endl;
    }
}

int main(){
    int n;
    cout << "请输入那要打印个数：";
    cin >> n;
    cout << endl;
    //dd(0,1,1,n);
    int k=fib(n);
    cout<<k<<endl;
    return 0;
}