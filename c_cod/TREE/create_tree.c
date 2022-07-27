#include<stdio.h>
#include<malloc.h>
#define maxsize 50
typedef struct node{
    int data;
    struct node *lchild,*rchild;
}Bitree;
typedef struct {
    Bitree *data[maxsize];
    int top;
}Stack;
int isEmpty(Stack *s){
    if(s->top==-1) return 1;
    else return 0;
}
void InitStack(Stack *s){
    s->top=-1;
}
Bitree *Pop(Stack *s){
    if(!isEmpty(s)){
        s->top--;
        return s->data[s->top+1];
    }else{
        return NULL;
    }
}
void push(Stack *s,Bitree* t){
    if(s->top<49){
        s->top++;
        s->data[s->top]=t;
    }else{
        printf("error");
    }
}

Bitree **Q;

Bitree* create_tree(){
    int front= 1;
    int rear =0;
    Q=malloc(sizeof(Bitree)*maxsize);
    int data;
    Bitree *T,*s;
    T=NULL;
    printf("请输入节点：");
    scanf("%d",&data);
    while(data!=-1){
        s=NULL;
        if(data!=0){
            s=malloc(sizeof(Bitree));
            s->data=data;
            s->lchild=NULL;
            s->rchild=NULL;
        }
        rear++;Q[rear]=s;
        if(rear==1) T=s;
        else{
            if(s!=NULL && Q[front]!=NULL)
            if(rear%2==0) Q[front]->lchild=s;
            else Q[front]->rchild=s;
            if(rear%2==1) front++;
        }
        scanf("%d",&data);
    }
    return T;
}
void visite(Bitree *tree){
        printf("%d,",tree->data);
}
void preorder(Bitree *T){
    Bitree* p=T;
    Stack *s=malloc(sizeof(Stack));
    InitStack(s);
    while(p!=NULL || !isEmpty(s)){
        if(p!=NULL){
            visite(p);
            push(s,p);
            p=p->lchild;
        }else{
            p=Pop(s);
            p=p->rchild;
        }
    }
}
void inorder(Bitree *T){
    Bitree *p=T;
    Stack *s=malloc(sizeof(Stack));
    InitStack(s);
    while(p!=NULL || !isEmpty(s)){
        if(p!=NULL){
            push(s,p);
            p=p->lchild;
        }else{
            p=Pop(s);
            visite(p);
            p=p->rchild;
        }
    }
}
void treep(Bitree *tree){
    if(tree){
        visite(tree);
        treep(tree->lchild);
        treep(tree->rchild);
    }
}
int main(){
    Bitree *tree=create_tree();
    treep(tree);
    return 0;
}