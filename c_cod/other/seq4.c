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
void maxmin(Sequenlist *L){
    int min, max,i;
    if(L->last>0){
        max=min=L->data[0];
        for(i=1;i<=L->last-1;i++){
            if(max<L->data[i])
                max=L->data[i];
            if(min>L->data[i])
                max=L->data[i];
        }
    }
    printf("max=%d,min=%d\n",max,min);
}
int main(){
    Sequenlist *A;
    A=SqLset();
    maxmin(A);
    return 0;
}