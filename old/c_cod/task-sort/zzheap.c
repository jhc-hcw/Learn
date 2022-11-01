#include<stdio.h>

void sife(int *data,int k,int len){
    int i,j;
    i=k;j=i*2;
    while(j<=len){
        if(j<len && data[j]<data[j+1]) j++;
        if(data[i]<data[j]){
            int t=data[i];
            data[i]=data[j];
            data[j]=t;
            i=j;j=i*2;
        }else break;
    }
}
void heapsort(int *data,int len){
    for(int i=len/2;i>=1;i--){
        sife(data,i,len);
    }
    for(int i=len;i>1;i--){
        int t=data[1];
        data[1]=data[i];
        data[i]=t;
        sife(data,1,i-1);
    }

}
int main(){
    int data[]={-1,98,77,35,62,55,14,35,48,2,1,5,99};
    int len=sizeof(data)/sizeof(int);
    heapsort(data,len-1);
    for(int i=0;i<len;i++){
        printf("%d,",data[i]);
    }
    return 0;
}