#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200
int compare=0,move=0;
int partition(int *data,int left,int right){   //经过一次排序，将关键字放在正确位置，切左边数都小于关键字，右边数都大于关键字。
    int low,high,x; 
    x=data[left];
    low = left;
    high = right;
    while(low<high){
        while(data[high]>x){   
            compare++;
            high--;
        }
        if(low<high){
            data[low]=data[high];
            move++;
            low++;
        }
        while(data[low]<x && low<high){
            low++;
            compare++;
        }
        if(low<high){
            data[high]=data[low];
            move++;
            high--;
        }
    }
    data[low]=x;
    move++;
    return low;
}
void quicksort(int *data,int low,int high){
    int mid;
    if(low<high){        //运用递归，将排序区间不断虽小，最后为0结束。
        mid=partition(data,low,high);
        quicksort(data,low,mid-1);
        quicksort(data,mid+1,high);
    }
}
int main(){
    srand(time(NULL));
    int data[MAX_ZIZE];
     for(int j=0;j<5;j++){
        compare=0;move=0;
        for(int i=0;i<MAX_ZIZE;i++)
            data[i]=rand()%1000;
        quicksort(data,0,MAX_ZIZE-1);
        printf("快速排序，对比次数为%d，移动次数为%d  \n",compare,move);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}