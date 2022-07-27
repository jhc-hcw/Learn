#include<stdio.h>
#include<malloc.h>
#include<time.h>
#define MAX_ZIZE 200
typedef struct node{
    int data;
    struct node *next;
}linklist;

linklist** initqu(){   //初始化队列数组。
    linklist **q=malloc(sizeof(linklist*)*10);
    for(int i=0;i<10;i++){
        linklist *t=malloc(sizeof(linklist));
        t->data=-1;
        t->next=NULL;
        q[i]=t;
    }
    return q;
}
int compare=0,move=0; //计数变量。
void distribute(linklist **q,int *a,int len,int index){  //进行一次关键字的排序。
    int t;
    linklist *p;
    for(int i=0;i<len;i++){     
        t=a[i];
        move++;
        for(int j=1;j<index;j++){   //将关键字提取出来。
            t=t/10;
        }
        t=t%10;
        p=q[t];    //对应关键字的队列取出来。
        while(p->next!=NULL) p=p->next;    
        linklist *tt=malloc(sizeof(linklist));   
        tt->data=a[i];       //尾插法入队
        tt->next=NULL; 
        move++;
        p->next=tt;
    }
    int j=0;
    for(int i=0;i<10;i++){
        while(q[i]->next!=NULL){
            linklist* t;      //出队在把数存回数组中
            t=q[i]->next;
            a[j]=t->data;
            q[i]->next=t->next;
            move++;
            j++;
            free(t);
        }
    }
}
void radixsort(linklist **q,int *a,int len,int index){
    for(int i=1;i<=index;i++){   //进行i个关键字的归并。
        distribute(q,a,len,i);
    }
    printf("基数排序，对比次数为%d，移动次数为%d  \n",compare,move);
}

int main(){
    linklist **q=initqu();
    srand(time(NULL));
    int data[MAX_ZIZE];
    for(int j=0;j<5;j++){
        compare=0,move=0;
        for(int i=0;i<MAX_ZIZE;i++)
            data[i]=rand()%1000;
        radixsort(q,data,MAX_ZIZE,3);
    }
    for(int i=0;i<MAX_ZIZE;i++){
        printf("%d,",data[i]);
    }
    return 0;
}