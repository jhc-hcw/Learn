#include<stdio.h>
#include<malloc.h>
#define maxsize 100
typedef struct node{ //二叉树类型
    int data;
    struct node* lchild,*rchild;
}Bitree;
typedef struct node1{   //链栈的定义
    void *data;       //Void*类型指针当泛型指针，实现栈的泛型功能
    struct node1* next;
}Stack;
Stack *Initst(){    //完成栈的初始化并返回一个栈。
    Stack *s=malloc(sizeof(Stack)); 
    s->data=NULL;
    s->next=NULL;
    return s;
}
int isEmpty(Stack *ls){    //栈的判空
    if(ls->next==NULL) return 1;
    else return 0;
}
void* pop(Stack *ls){     //出栈操作
   if(!isEmpty(ls)){
       Stack* t=ls->next;
       ls->next=t->next;
       return t->data;
   }else{
       return NULL;
   }
}
void* getTop(Stack *ls){    //取栈顶元素
    if(!isEmpty(ls)){
        return ls->next->data;
        }
    else
        return NULL;
}
void push(Stack *ls,void* x){   //入栈操作
    Stack* t=malloc(sizeof(Stack));
    t->data=x;
    t->next=ls->next;
    ls->next=t;
}
void printstack(Stack *sk){
    Stack *p=Initst();
    Stack* t=sk->next;
    int* data;
    while(t){
        push(p,t->data);
        t=t->next;
    }
    t=p->next;
    while(t){
        data=t->data;
        printf("%d,",*data);
        t=t->next;
    }
    free(p);
    printf("\t");
}
void findf(Bitree *t,int x){  //找到节点所有祖先
    Bitree *p=t,*f=t;
    Stack *s=Initst();   //存储所有祖先的栈
    push(s,p);
    while(!isEmpty(s)){
        p=getTop(s);
        if(p->lchild!=NULL && p->lchild!=f && p->rchild!=f ){
            push(s,p->lchild);
        }else if(p->rchild!=NULL && p->rchild!=f){
            push(s,p->rchild);
        }else{
            p=pop(s);
            if(p->data==x){
                printf("公共祖先为：");
                printstack(s);
                break;
            }
            f=p;
        }
    }
}
Bitree* create_tree(){   //通过输入构建一个二叉树
    int front= 1;
    int rear =0;
    Bitree **Q=malloc(sizeof(Bitree)*maxsize);
    int data;
    Bitree *T,*s;
    T=NULL;
    printf("请输入节点:");
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


int main(){
    Bitree *t= create_tree();
    findf(t,9);
    return 0;
}