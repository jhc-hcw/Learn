#include<iostream>
#include<string>
using namespace std;
int sum=100;
int main(){
    int a=8;
     if(true){
         int a=7;
         int sum=9;
         cout<<::sum<<a<<endl;
     }
    return 0;
}