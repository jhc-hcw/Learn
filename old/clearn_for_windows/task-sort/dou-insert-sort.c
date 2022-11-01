#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200

void dou_insert_sort(int *data,int len){
    int a[len];   //建立一个循环数组，存放排好序的元素。
    int i,j,k,t,h=0,r=0;
    int compare=0,move=0;
    a[0]=data[0];
    for(i=1;i<len;i++){    //根据关键字大小，不断把数送到循环数组中排队。
        if(data[i]<a[h]){    //插入循环数组头部
            compare++;
            h=(h-1+len)%len;
            a[h]=data[i];
            move++;
        }else if(data[i]>a[r]){   //插入循环数组尾部
            compare++;
            r=(r+1)%len;
            a[r]=data[i];
            move++;
        }else{
            if(data[i]<a[(h+i/2)%len]){   //从循环数组中间开始查找插入位置。
                compare++;
                for(k=h;a[k]<data[i];k=(k+1)%len){
                    a[(k-1+len)%len]=a[k];
                    move++;
                    compare++;
                }
                a[(k-1+len)%len]=data[i];
                move++;
                h=(h-1+len)%len;
            }else{
                compare++;
                for(k=r;a[k]>data[i];k=(k-1+len)%len){
                    a[(k+1)%len]=a[k];
                    move++;
                    compare++;
                }
                a[(k+1)%len]=data[i];
                move++;
                r=(r+1)%len;
            }
        }
    }
    for(j=0,k=h;j<len;j++,k=(k+1)%len){  //将循环数组中的数据再送回数组中。
        data[j]=a[k];
        move++;
    }
    printf("二路插入排序，对比次数为%d，移动次数为%d  \n",compare,move);
}

int main(){
    srand(time(NULL));
    int data[MAX_ZIZE];
    for(int j=0;j<5;j++){
        for(int i=0;i<MAX_ZIZE;i++)
            data[i]=rand()%1000;
        dou_insert_sort(data,MAX_ZIZE);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}