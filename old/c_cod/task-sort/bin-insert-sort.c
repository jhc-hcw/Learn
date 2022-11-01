#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200
void bin_insert_sort(int *data,int len){
    int t,i,j,low,high,mid;
    int compare=0,move=0;
    for(i=1;i<len;i++){
        t=data[i];
        move++;
        low=0;high=i-1;
        while(low<=high){   //用二分查找法找到关键字插入位置
            mid=(low+high)/2;
            if(t>data[mid]){ 
                low=mid+1;
                compare++;
            }
            else{
                high=mid-1;
                compare++;
                }
        }
        for(j=i-1;j>=high+1;j--){   //将关键字插入到找到的位置。
            data[j+1]=data[j];
            move++;
        }
        data[high+1]=t;
    }
    printf("折半折入排序，对比次数为%d，移动次数为%d  \n",compare,move);
}

int main(){
    srand(time(NULL));
    int data[MAX_ZIZE];
    for(int j=0;j<5;j++){
        for(int i=0;i<MAX_ZIZE;i++)
            data[i]=rand()%1000;
        bin_insert_sort(data,MAX_ZIZE);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}