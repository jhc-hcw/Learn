#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200
void dir_insert_sort(int *data,int len){
    int t,j,i;
    int compare=0,move=0;
    for(i=1;i<len;i++){
        j=i-1;
        t=data[i];
        move++;
        while(t<data[j]){   //将后一个数插入前面已经排好的数中。
            compare++;
            data[j+1]=data[j];
            move++;
            j--;
        }
        data[j+1]=t;
        move++;
    }
    printf("直接插入排序，对比次数为%d，移动次数为%d  \n",compare,move);
}

int main(){
    srand(time(NULL));
    int data[MAX_ZIZE];
     for(int j=0;j<5;j++){
        for(int i=0;i<MAX_ZIZE;i++)
            data[i]=rand()%1000;
        dir_insert_sort(data,MAX_ZIZE);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}