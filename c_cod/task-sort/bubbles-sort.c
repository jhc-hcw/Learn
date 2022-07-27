#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200
void bubble_sort(int *data,int len){
    int i,j,t,flag;
    int compare=0,move=0;
    for(i=0;i<len-1;i++){
        flag=0;
        for(j=0;j<len-1-i;j++){
            if(data[j]>data[j+1]){
                t=data[j];
                data[j]=data[j+1];
                data[j+1]=t;
                flag=1;
                move+=3;
            }
            compare++;
        }
        if(flag==0)
            break;
    }
    printf("起泡排序，对比次数为%d，移动次数为%d  \n",compare,move);
}

int main(){
    srand(time(NULL));
    int data[MAX_ZIZE];
    for(int j=0;j<5;j++){
        for(int i=0;i<MAX_ZIZE;i++)
            data[i]=rand()%1000;
        bubble_sort(data,MAX_ZIZE);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}