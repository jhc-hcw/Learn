#include <stdio.h>
#include<malloc.h>
#define maxlen 100
typedef  int Stacktype;
typedef struct{
    Stacktype data[maxlen];
    int top;
}Stack;
Stacktype *createStack(){
    Stack *s=malloc(sizeof(Stack));
    s->top=-1;
}
int isEmpty(Stack *s){
    if(s->top==-1) return 1;
    else return -1;
}
Stacktype *getTop(Stack *s){
    if(!isEmpty(s)) return s->data[s->top];
    else return NULL;
}
int *push(Stack *s,Stacktype d){
    if(s->top<maxlen-1){
        s->top++;
        s->data[s->top]=d;
        return 1;
    }else printf("栈满，入栈失败"),return 0;
}
Stacktype *pop(Stack *s){
    if(!isEmpty(s)){
        s->top--;
        return s->data[s->top+1];
    }else return 0;

}