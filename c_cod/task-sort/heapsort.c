#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200
int compare=0,move=0;
void sift(int *data,int k,int len){
    int i,j;
    i=k,j=2*i;
    while(j<=len){
        if(j<len && data[j]<data[j+1]) {  //对树进行不断调整，使其成为大根堆
            j++;
            compare++;
        }
        compare++;
        if(data[i]<data[j]){
            int t=data[i];
            data[i]=data[j];
            data[j]=t;
            move+=3;
            i=j;j=i*2;
        }else break;
    }
}
void heapsort(int *data,int len){
    for(int i=len/2;i>=1;--i){     //建立一个大根堆。
        sift(data,i,len);
    }
    for(int i=len;i>1;i--){  //输出根部到数组最后一个位置，并将剩下的数据再调整为一个大根堆。
        int t;
        t=data[1];
        data[1]=data[i];
        data[i]=t;
        move+=3;
        sift(data,1,i-1);
    }
    printf("堆排序，对比次数为%d，移动次数为%d  \n",compare,move);
}
int main(){
    srand(time(NULL));
    int data[MAX_ZIZE+1];
    data[0]=-1;
    for(int j=0;j<5;j++){
        compare=0;move=0;
        for(int i=1;i<MAX_ZIZE+1;i++)
            data[i]=rand()%1000;
        heapsort(data,MAX_ZIZE+1);
    }
    for(int i=1;i<MAX_ZIZE+1;i++){
        printf("%d,",data[i]);
    }
    return 0;
}