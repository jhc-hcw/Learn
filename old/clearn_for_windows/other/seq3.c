#include <malloc.h>
#include <stdio.h>
#define maxlen 50

typedef struct{
    int data[maxlen];
    int last;
}Sequenlist;


Sequenlist * SqLset(){
    Sequenlist *L;
    int i;
    L=malloc(sizeof(Sequenlist));
    L->last=-1;
    printf("请输入初始化个数：");
    scanf("%d",&i);
    if(i>0){
        for(L->last=0;L->last<i;L->last++)
            scanf("%d",&L->data[L->last]);
    }
    return L;
}

Sequenlist *reverse(Sequenlist * L){
    int i,j,x;
    for(i=0,j=L->last-1;i<=j;j--,i++){
        x=L->data[i];L->data[i]=L->data[j];L->data[j]=x;
    }
    return L;
}

int main(){
    Sequenlist *A;
    int i;
    A=SqLset();
    for(i=0;i<A->last;i++)
        printf("%4d",A->data[i]);
    printf("\n");
    reverse(A);
    for(i=0;i<A->last;i++)
        printf("%4d",A->data[i]);
    printf("\n");
    return 0;
}