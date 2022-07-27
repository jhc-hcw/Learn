#include<stdio.h>
#include<malloc.h>
#define Maxsize 100
typedef struct {
    int data[Maxsize];
    int Top;
}SeqStack;

int StackEmpty(SeqStack *s){
    if(s->Top==0){
        return 1;
    }else{
        return 0;
    }
}
void InitStack(SeqStack *s){
    s->Top=0;
}
void Push(SeqStack *s,int x){
    s->data[s->Top]=x;
    s->Top++;
}

int GetTop(SeqStack *s){
    if(s->Top==0){
        printf("栈空！");
        return NULL;
    }
    return s->data[s->Top-1];
}
int Pop(SeqStack *s){
    if(s->Top==0){
        printf("栈空！");
        return NULL;
    }
    s->Top--;
    return s->data[s->Top];
}
void cc(long num,int i){
    SeqStack s;
    InitStack(&s);
    while(num){
        int k=num%i;
        Push(&s,k);
        num=num/i;
    }
    while(!StackEmpty(&s)){
        int x=GetTop(&s);
        if(x<10)
            printf("%d",x);
        Pop(&s);
    }
    printf("\n");
}

int main(){
    int d,i;
    printf("请输入你要转化的数和进制：");
    scanf("%d %d",&d,&i);
    printf("\n转化结果为：");
    cc(d,i);
    return 0;
}