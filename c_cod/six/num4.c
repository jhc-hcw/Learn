#include<stdio.h>
#include<malloc.h>
#define LIST_SIZE 20

typedef struct{
    int r[LIST_SIZE];
    int length;
}RecordList;

RecordList *SqLset(){
    RecordList *L;
    int i=0,a;
    L=malloc(sizeof(RecordList));
    printf("输入一个整型有序序列，输入0时结束！");
    scanf("%d",&a);
    L->length=0;
    while(a!=0){
        L->r[i]=a;
        L->length++;i++;
        if(L->length==LIST_SIZE-1) break;
        scanf("%d",&a);
    }
    return L;
}
int BinSrch(RecordList *L,int k,int low,int high){
    int mid;
    while(low<high){
        mid=(low+high)/2;
        if(k==L->r[mid])
            return mid;
        else if(k<L->r[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main(){
    RecordList *A;
    int k,low,high,m;
    A=SqLset();
    low=0;high=A->length-1;
    scanf("%d",&k);
    m=BinSrch(A,k,low,high);
    if(m==-1)
        printf("查找不成功！");
    else printf("m=%d,查找成功！",m);
    return 0;
}