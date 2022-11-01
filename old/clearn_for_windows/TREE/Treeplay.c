#include <stdio.h>
#include<malloc.h>
#define maxlen 100
typedef  int Stacktype;
typedef int Bitreetype;

typedef struct node{
    Bitreetype data;
    struct node *lchild,*rchild;
}Bitree;
typedef struct{
    Bitree* data[maxlen];
    int top;
}Stack;
Stack* stackInit(){
    Stack *p=malloc(sizeof(Stack));
    p->top=-1;
    return p;
}
int isEmpty(Stack *s){
    if(s->top==-1) return 1;
    else return 0;
}
Bitree *getTop(Stack *s){
    if(!isEmpty(s)) return s->data[s->top];
    else return NULL;
}
int push(Stack *s,Bitree* d){
    if(s->top<maxlen-1){
        s->top++;
        s->data[s->top]=d;
        return 1;
    }else {printf("栈满，入栈失败");return 0;}
}
Bitree *pop(Stack *s){
    if(!isEmpty(s)){
        s->top--;
        return s->data[s->top+1];
    }else return 0;
}
void visited(Bitree *t){
    printf("%d",t->data);
}
void afterbianli(Bitree *t){
    Bitree *h=t,*c;
    Stack *s=stackInit();
    if(h!=NULL){
        push(s,h);
        while(!isEmpty(s)){
            c=getTop(s);
            if(c->lchild!=NULL && h!=c->lchild && h!=c->rchild){
                push(s,c->lchild,c);
            }else if(c->rchild!=NULL && h!=c->rchild){
                push(c->rchild,c);
            }else {
                visited(pop(h));
                h=c;
            }
        }
    }
}
void afterbianli(Bitree *t){
    Bitree *h=t,*c;
    Stack *s=Initst();
    if(h!=NULL){
        push(s,h);
        while(!isEmpty(s)){
            c=getTop(s);
            if(c->lchild!=NULL && h!=c->lchild && h!=c->rchild){
                push(s,c->lchild);
            }else if(c->rchild!=NULL && h!=c->rchild){
                push(s,c->rchild);
            }else {
                visited(pop(s));
                h=c;
            }
        }
    }
}
int main(){
    return 0;
}