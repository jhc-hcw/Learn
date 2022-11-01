#include<stdio.h>
#include<malloc.h>
#include<string.h>
# define maxsize 50
typedef struct{
     char data[maxsize];
     int top;
}SeqStack;

void pop(SeqStack *s){
    if(s->top==-1){
        printf("空空如也！");
        return ;
    }
    s->top--;
}
char getTop(SeqStack *s){
    if(s->top==-1)
        printf("栈空！");
    else
        return s->data[s->top];
}
void push(SeqStack *s,char x){
    if(s->top==maxsize-1){
        printf("插入失败！栈满捏！\n");
        return ;
    }
    s->data[s->top+1]=x;
    s->top++;
}
SeqStack* stackinit(){
    SeqStack *s=malloc(sizeof(SeqStack));
    s->top=-1;
    return s;
}
int cc(char *s){
    int l=strlen(s),i=l/2,j,res=1;
    SeqStack *ss=stackinit();
    if(l%2==0)
        j=l/2;
    else 
        j=l/2+1;
    for(int d=0;d<i;d++){
        push(ss,s[d]);
    }
    for(;j<l;j++){
        if(s[j]!=getTop(ss)){
            res=0;
            break;
        }
        pop(ss);
    }
    return res;
}

int main(){
    char *s;
    printf("请输入你要测试的字符串：");
    scanf("%s",s);
    for(int i=0;s[i]!='\0';i++){
        printf("%c",s[i]);
    }
    if(cc(s)==1){
        printf("哇偶，是的呢");
    }else{
        printf("压根不是");
    }
    return 1;
}