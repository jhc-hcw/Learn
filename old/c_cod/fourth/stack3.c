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
void dectohex(long num){
    SeqStack s;
    InitStack(&s);
    while(num){
        int k=num%16;
        Push(&s,k);
        num=num/16;
    }
    while(!StackEmpty(&s)){
        int x=GetTop(&s);
        if(x<10)
            printf("%d",x);
        else{
            switch(x){
                case 10:printf("A");break;
                case 11:printf("B");break;
                case 12:printf("C");break;
                case 13:printf("D");break;
                case 14:printf("E");break;
                case 15:printf("F");break;
            }
        }
        Pop(&s);
    }
    printf("\n");
}
int main(){
    int data;
    printf("请输入十进制数：");
    scanf("%d",&data);
    printf("十六进制为:");
    dectohex(data);
    return 0;
}