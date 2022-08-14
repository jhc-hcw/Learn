#include<iostream>
using namespace std;

void b_sort(int *data,int len){
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i-1;j++){
            if(data[j]>data[j+1]){
                int t=data[j];
                data[j]=data[j+1];
                data[j+1]=t;
            }
        }
    }
}
void select_sort(int *data,int len){
    int t=0;
    int p=t;
    for(int i=0;i<len;i++){
        p=i;
        for(int j=i;j<len;j++){
            if(data[p]>data[j]){
                p=j;
            }
        }
        t=data[i];
        data[i]=data[p];
        data[p]=t;
    }
}
template<typename T,int N>
int array_len(T data[N]){
    return N;
}
int main(){
    int dat[]={9,8,7,6,5,45,4,3,2,1,3,2,4,5,4,3,3,4554,456,43,32,32,32,43,534,54,54,43,234,32,43,534,54,534,34,4,43,435,54,645,345,345};
    select_sort(dat,sizeof(dat)/4);
    for(int i=0;i<sizeof(dat)/4;i++){
        cout<<dat[i]<<" ";
    }
    return 0;
}