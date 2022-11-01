#include<iostream>
using namespace std;

int cc(int a,int b,int c){
    return a*a*a+b*b*b+c*c*c;
}
int dd(int a,int b,int c){
    return a*100+b*10+c;
}
int main(){
    int a=0,b=0,c=0;
    for(a=1;a<=9;a++)
        for(b=0;b<=9;b++)
            for(c=0;c<=9;c++){
                int sum1=a*a*a+b*b*b+c*c*c;
                int sum2=a*100+b*10+c;
                if(sum1==sum2){
                    cout << sum2 << "   ";
                }
            }
    return 0;
}