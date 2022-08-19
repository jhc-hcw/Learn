#include <iostream>
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
            i++;
        }else{
            cache[i]=data[j];
            j++;
            i++;
        }
    }
    for(;j<mid;j++,i++) cache[i]=data[j];
    for(;k<len;k++,i++) cache[i]=data[k];
    for(int q=0;q<len;q++) data[q]=cache[q];
}
using namespace std;
int main(){
    int a[]={5,4,3,34,3,34,32,34,3,231,23,342,54,345,34,435,435,34,34,435,345,456,67,867,78,65,-2,54,45,68,453,45,56,345,56,234,345,534,2345,345,234,5346,4};
    int len = sizeof(a)/4;
    merg_parilation(a, len);
    for(int i=0;i<len;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
