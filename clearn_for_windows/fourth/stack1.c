#include <stdio.h>
#include<malloc.h>

#define maxlen 100

typedef  int Datatype;
typedef  int datatype;

typedef struct{
     Datatype data[maxlen];
     int top;
}SeqStack;

SeqStack * Sskinit(){
    SeqStack *ssk=malloc(sizeof(SeqStack));
    
}
Datatype getTop(SeqStack *ssk){
    if()
}
Datatype Pop(SeqStack *ssk){
    if(ssk->top==-1){
        printf("空空如也！");
        return;
    }
    ssk->top--;
    return ssk->data[ssk->top+1];
}
void push(SeqStack *ssk,Datatype x){
    if(ssk->top==maxlen-1){
        printf("插入失败！栈满捏！\n");
        return;
    }
    ssk->data[ssk->top+1]=x;
    ssk->top++;
}
void stackprintf(SeqStack *ssk){
    printf("|-");
    for(int i=0;i<ssk->top+1;i++){
        printf("%d->",ssk->data[i]);
    }
    printf("\n");
}
int main(){
    SeqStack *ssk=malloc(sizeof(SeqStack));
    ssk->top=-1;
    int data;
    while(printf("是否入栈："),scanf("%d",&data),data){
        printf("请输入入栈数据：");
        scanf("%d",&data);
        push(ssk,data);
    }
    stackprintf(ssk);
    printf("%d出栈\n",Pop(ssk));
    printf("%d出栈\n",Pop(ssk));
    printf("%d出栈\n",Pop(ssk));
    stackprintf(ssk);
    return 0;
}

