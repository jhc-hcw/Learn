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
int Seqdelete(Sequenlist *L,int i){
    int j;
    if(L->last<0){
        printf("顺序表为空\n");
        return 0;
    }else if(i<1 || (i>L->last+1)){
        printf("i参数错误！\n");
    }else{
        for(j=i;j<L->last+1;j++)
            L->data[j-1]=L->data[j];
        L->last--;
        return 1;
    }
}
void del_rep(Sequenlist *L){
    int i,j;
    for(i=0;i<L->last-1;i++){
        for(j=i+1;j<L->last;j++){
            if(L->data[i]==L->data[j])
                Seqdelete(L,j+1);
        }
    }
}
void Seq_print(Sequenlist *L){
    int i;
    for(i=0;i<L->last;i++)
        printf("%4d",L->data[i]);
}
int main(){
    Sequenlist *A;
    A=SqLset();
    del_rep(A);
    Seq_print(A);
    return 0;
}