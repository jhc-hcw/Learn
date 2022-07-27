#include<stdio.h>
#include<malloc.h>
#include<time.h>
#define MAX_ZIZE 200
int length;

int compare=0,move=0;
void merge(int *R,int *R1,int low,int mid,int high){   //两个有序数组合并成一个有序数组的一次排序算法。
    int i,j,k=0;
    i=low,j=mid+1;k=low;
    while(i<=mid && j<=high){
        if(R[i]<=R[j]){
            R1[k]=R[i];
            i++;
        }else{
            R1[k]=R[j];
            j++;
        }
        move++;
        compare++;
        k++;
    }
    while(i<=mid) R1[k++]=R[i++],move++;
    while(j<=high) R1[k++]=R[j++],move++;
}
void mergepass(int *R,int *R1,int len){   //将一个数组拆成若干有序数组进行合并。
    int j,i=0;
    while(i+len*2<length){
        merge(R,R1,i,i+len-1,i+len*2-1);
        i=i+len*2;
    }
    if(i+len-1<length-1) merge(R,R1,i,i+len-1,length-1);
    else
        for(j=i;j<length;j++) R1[j]=R[j];
}
void mergesort(int *L,int l){   //不断扩大合并的区间，当区间大于数组长度停止。
    length=l;
    int len=1;                  
    int *R1=malloc(sizeof(int)*length);   //创建一个临时数组存储合并好的数组。
    while(len<=length/2+1){
        mergepass(L,R1,len);
        len=2*len;
        mergepass(R1,L,len);
        len=2*len;
    }
    free(R1);
    printf("归并排序，对比次数为%d，移动次数为%d  \n",compare,move);
}
int main(){
    srand(time(NULL));
    int data[MAX_ZIZE];
     for(int j=0;j<5;j++){
        compare=0;move=0;
        for(int i=0;i<MAX_ZIZE;i++)
            data[i]=rand()%1000;
        mergesort(data,MAX_ZIZE);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}