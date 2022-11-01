#include<stdio.h>

void shellinsert(int *data,int d,int l){//d为每次对比的相隔区间
    int i,k;
    for(i=0;i+d<=l-1;i++){  //当最后一个数参与对比循环结束
        if(data[i]>data[i+d]){    //前面小就换到后面去
            k=data[i];
            data[i]=data[i+d];
            data[i+d]=k;
        }
    }
}
void shellsort(int *data,int l){
    for(int i=l/2;i>=1;i--){     //多次循环，直到对比区间为1，结束。
        shellinsert(data,i,l);
    }
}
int main(){
    int a[]={44,33,22,11,7,6,5,4,3,2,1};
    long l=sizeof(a)/sizeof(int);
    shellsort(a,l);
    for(int i=0;i<l;i++){
        printf("%d,",a[i]);
    }
    return 0;
}