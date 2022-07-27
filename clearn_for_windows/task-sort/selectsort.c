#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200

void selectsort(int *data,int l){
    int i,k,j,x;
    int compare=0,move=0;
    for(i=0;i<l;i++){
        k=i;
        for(j=i;j<l;j++){
            if(data[k]>data[j]){    //对比找到后部分最小数的位置。
                k=j;
            }
            compare++;
        }
        if(k!=i){
            x=data[i];
            data[i]=data[k];    
            data[k]=x;
            move+=3;
        }
    }
    printf("简单选择排序，对比次数为%d，移动次数为%d  \n",compare,move);
}

int main(){
    srand(time(NULL));
    int data[MAX_ZIZE];
    for(int j=0;j<5;j++){
        for(int i=0;i<MAX_ZIZE;i++)
            data[i]=rand()%1000;
        selectsort(data,MAX_ZIZE);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}