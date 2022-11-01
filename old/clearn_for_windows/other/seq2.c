#include "malloc.h"
#include <stdio.h>
#define maxlen 50

typedef struct{
    int data[maxlen];
    int last;
}Sequenlist;

Sequenlist *ABC(Sequenlist *A,Sequenlist *B){
    int i,j;
    Sequenlist *C;
    C=malloc(sizeof(Sequenlist));
    C->last=-1;
    for(i=0;i<=A->last;i++)
        for(j=0;j<=B->last;j++){
            if(A->data[i]==B->data[j]){
                C->last++;
                C->data[C->last]=A->data[i];
                break;
            }
        }
    return C;
}

Sequenlist *Sqlset(){
    Sequenlist* L;
    int i;
    L=malloc(sizeof(Sequenlist));
    L->last=-1;
    printf("请输入初始化个数：");
    scanf("%d",&i);
    if(i>0){
        for(L->last=0;L->last<i;L->last++)
            scanf("%d",&L->data[L->last]);
        L->last--;
    }
    return L;
}

int main(){
    Sequenlist *A,*B,*C;
    int i;
    A=Sqlset();
    B=Sqlset();
    C=ABC(A,B);
    for(i=0;i<=C->last;i++){
        printf("%4d",C->data[i]);
    }
    return 0;
}