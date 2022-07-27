#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200
void sift(int *data,int k,int len){
    int i,j;
    i=k,j=2*i;
    while(j<=len){
        if(j<len && data[j]<data[j+1]) {  //对树进行不断调整，使其成为大根堆
            j++;
        }
        if(data[i]<data[j]){
            int t=data[i];
            data[i]=data[j];
            data[j]=t;
            
            i=j;j=i*2;
        }else break;
    }
}
void heapsort(int *data,int len){
    for(int i=len/2;i>=1;--i){     //建立一个大根堆。
        sift(data,i,len);
        for(int j=0;j<len;j++){
            printf("%d ",data[j+1]);
        }
        printf("\n");
    }
    for(int i=len;i>1;i--){  //输出根部到数组最后一个位置，并将剩下的数据再调整为一个大根堆。
        int t;
        t=data[1];
        data[1]=data[i];
        data[i]=t;
        sift(data,1,i-1);
        for(int j=0;j<len;j++){
            printf("%d ",data[j+1]);
            
        }
        printf("\n");
    }
}
int main(){
    int data[MAX_ZIZE+1];
    data[0]=-1;
    int len;
    scanf("%d\n",&len);
    for(int j=0;j<len;j++){
        scanf("%d ",data+j+1);
    }
    heapsort(data,len);
    return 0;
}