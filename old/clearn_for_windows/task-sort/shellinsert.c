#include<stdio.h>
#include<time.h>
#define MAX_ZIZE 200
int compare=0,move=0;
void shellinsert(int *data,int d,int l){//d为每次对比的相隔区间
    int i,k;
    for(i=0;i+d<=l-1;i++){  //当最后一个数参与对比循环结束
        if(data[i]>data[i+d]){    //前面大就换到后面去
            k=data[i];
            data[i]=data[i+d];
            data[i+d]=k;
            move+=3;
        }
        compare++;
    }
}
void shellsort(int *data,int l){
    for(int i=l/2;i>=1;i--){     //多次循环，直到对比区间为1，结束。
        shellinsert(data,i,l);
    }
    printf("希尔排序，对比次数为%d，移动次数为%d  \n",compare,move);
}
void shellsort2(int *data,int l){   //l为数组长度
    int d=l/2,k,i;
    while(d>=1){      //切割区间小于1就停止
        for(i=0;i+d<=l-1;i++){   //将跨度为d的两个数据对比   
            if(data[i]>data[i+d]){   //前面数大就交换。
                k=data[i];
                data[i]=data[i+d];
                data[i+d]=k;
            } 
        }
        d--;    //下一趟两数对比间隔减小1
    }
}
int main(){
    srand(time(NULL));
    int data[MAX_ZIZE];
    for(int j=0;j<1;j++){
        compare=0,move=0;
        for(int i=0;i<MAX_ZIZE;i++)    
            data[i]=rand()%1000;
        shellsort2(data,MAX_ZIZE);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}