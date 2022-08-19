#include<iostream>
using namespace std;

void sif(int *data,int k,const int len){
    int j=2*k;
    while(j<=len){
        if(j<len && data[j]<data[j+1]){
            j++;
        }
        if(data[k]<data[j]){
            auto t=data[k];
            data[k]=data[j];
            data[j]=t;
            k=j;
            j=k*2;
        }else 
            break;
    }
}

void heapsort(int *data,const int len){
    for(int i=len/2;i>0;i--){
        sif(data,i,len);
    }
    for(int i=len;i>1;i--){
        auto t=data[i];
        data[i]=data[1];
        data[1]=t;
        sif(data,1,i-1);
    }
}
int main(){
    int a[]={9,3,23,34,54,234,23,21,23,43,54,34,23,12,234,54,65,675,76,456,34,23,32,43,45,65,54,453,23,213,23,34,54,567,6756,};
    auto len=sizeof(a);
    heapsort(a, len/4);
    for(int i=1;i<len/4;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}