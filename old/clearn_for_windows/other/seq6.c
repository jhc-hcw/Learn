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
void Seq_print(Sequenlist *L){
    int i;
    for(i=0;i<L->last;i++)
        printf("%4d",L->data[i]);
}
void Seq_sortinsert(Sequenlist *L ,int data){
    int i,j,k=0;
    for(i=0;i<L->last;i++){
        if(L->data[i]>=data){
            for(j=L->last;j>=i+1;j--){
                L->data[j]=L->data[j-1];
            }
            L->data[i]=data;
            k=1;
            break;
        }
    }
    L->last++;
    if(k==0){
        L->data[L->last-1]=data;
    }
}
int main(){
    int i=0;
    Sequenlist *A;
    A=SqLset();
    printf("请输入要插入的数：");
    scanf("%d",&i);
    Seq_sortinsert(A,i);
    Seq_print(A);
    return 0;
}