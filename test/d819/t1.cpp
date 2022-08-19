void merg_parilation(int *data,const int len){
    const int mid=len/2;
    int cache[len];
    if(len>2){
        merg_parilation(data, mid);
        merg_parilation(data+mid, len-mid);
    }else{
        if(len==2 && data[0]>data[1]){
            auto t=data[0];
            data[0]=data[1];
            data[1]=t;
        }
        return ;
    }
    int j=0,k=mid,i=0;
    while(j<mid && k<len){
        if(data[k]<data[j]){
            cache[i]=data[k];
            k++;
        }else{
            cache[i]=data[j];
            j++;
        }
    }
    for(;j<mid;j++,i++) cache[i]=data[j];
    for(;k<len;k++,i++) cache[i]=data[k];
    for(int q=0;q<len;q++) data[q]=cache[q];
}
#include<iostream>
using namespace std;
int main(){
    int a[]={3,2,3,4,5,6,7,8,9,0,1,1,2,23,23,2,23,3,23,23,3,423,45,65,65,756,654,435,324234,345,564,456,456,4235,234,3124,231,324,435,453,342,231};
    int len = sizeof(a)/4;
    //merg_parilation(a, len);
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}