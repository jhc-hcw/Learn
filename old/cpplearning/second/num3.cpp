#include<iostream>
using namespace std;
int main(){
    int i,j,k;
    for(i=0;i<20;i++){
        for(j=0;j<33;j++){
            k=(100-i*5-j*3)*3;
            if(i+k+j==100){
                cout <<"公鸡："<<i<<" 母鸡："<<j<<" 小鸡："<<k<<endl;
            }
        }
    }
    return 0;
}