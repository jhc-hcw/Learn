#include<stdio.h>
#include<malloc.h>
typedef struct Pnode{
    int coef;
    int exp;
    struct Pnode* next;
}Polynode;

Polynode *H,*R,*S;


void Plprint(){
    if(H->next==NULL){
        printf("空空如也！");
        return;
    }
    R=H->next;
    while(1){
        if(R->next!=NULL){
            printf("%d*X^%d+",R->coef,R->exp);
            R=R->next;
        }else{
            printf("%d*X^%d",R->coef,R->exp);
            break;
        }
    }
    return;
}

int Plinit(){
    R=H;
    int coef,exp,flag;
    int sum=0;
    printf("输入扣非0继续输入:");
    scanf("%d",&flag);
    while(flag){
        printf("请输入系数与指数：");
        scanf("%d %d",&coef,&exp);
        R->next=(Polynode*)malloc(sizeof(Polynode));
        R->next->coef=coef;
        R->next->exp=exp;
        R->next->next=NULL;
        R=R->next;
        sum++;
        printf("输入扣非0继续输入:");
        scanf("%d",&flag);
    }
    return sum;
}



int main(){
    H=(Polynode*)malloc(sizeof(Polynode));
    H->coef=-1;
    H->exp=-1;
    H->next=NULL;
    S=H;
    Plinit();
    Plprint();
    return 0;
}