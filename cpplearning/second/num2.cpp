#include<iostream>
using namespace std;
int main(){
    int a[10]={0,0,0,0,0,0,0,0,0,0};
    cout <<"请输入投票数据："<<endl;
    int r;
    for(int i=0;i<15;i++){
        cin >>r;
        a[r-1]++;
    }
    cout <<"请输入投票结果为："<<endl;
    for(int i=1;i<11;i++){
        cout<<i<<",";
    }
    cout<<endl;
    for(int i=0;i<10;i++){
        cout<<a[i]<<",";
    }
}