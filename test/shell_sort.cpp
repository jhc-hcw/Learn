#include<iostream>
using namespace std;


void shell(int *data,const int len){
    int s=len/2;
    int j;
    for(;s>0;s/=2){
        for(int i=0;i<len;i++){
            for(j=i;j+s<len;j+=s){
                if(data[j]>data[j+s]){
                    int t=data[j];
                    data[j]=data[j+s];
                    data[j+s]=t;
                }
            }
            // if(s==len-1){
            //     i=len;
            // }
        }
    }
}
void insert_sort(int *data,int len){
    for(int i=0;i<len;i++){
        int t=data[i];
        int j=i;
        for(;j>0;j--){
            if(t<data[j-1]){
                data[j]=data[j-1];
            }else{
                data[j]=t;
                break;
            }
        }
        data[j]=t;
    }
}
int main(){
    int data[]={9,8,7,6,5,4,3,2,21,1,2,3,4,5,4,3,33434,343432,23,2,1,2,3,34,2,34,213,23,2,543,23,345,23,43,23,43,23,34,23,34,231,34,354,342,342,343,2,3,45,5,6,76,7,6,5,4,4,3,3,23,32,3,3,34,4};
    int len=sizeof(data)/4;
    shell(data,len);
    for(int i=0;i<len;i++){
        cout<<data[i]<<" ";
    }
    cout<<endl;
    return 0;
}