#include<stdio.h>
#include<malloc.h>
#define maxsize 100
typedef struct node{ //数的结构体类型
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
Bitree* InsertBST(Bitree *t,int x){  //二叉排序树的插入操作
    Bitree *s,*p,*f;
    p=t;
    while(p!=NULL){
        f=p;
        if(x==p->data) return t;
        if(x<p->data) p=p->lchild;
        else p=p->rchild;
    }
    s=malloc(sizeof(Bitree));
    s->data=x;
    s->lchild=NULL;s->rchild=NULL;
    if(t==NULL) return s;
    if(x<f->data) f->lchild=s;
    else f->rchild=s;
    return t;
}
Bitree* CreateBST(int *data,int len){  //用一个存放权值的数组构建一个二叉排序树
    Bitree *t,*f,*p;
    int i;
    t=malloc(sizeof(Bitree));
    t->data=data[0];
    t->lchild=NULL;t->rchild=NULL;
    for(i=1;i<len;i++){
        InsertBST(t,data[i]);
    }
    return t;
}
Bitree* Bserch(Bitree *t,int x){   //二叉排序树查找方法。
    Bitree *p;int flag=0;
    p=t;
    while(p!=NULL){
        if(p->data==x){
            flag=1;
            break;
        }
        if(x<p->data) p=p->lchild;
        else p=p->rchild;
    }
    if(flag=1){
        return p;
    }else {
        printf("找不到点");
        return NULL;
    }
}
void findf(Bitree *t,int x,int y){  //找到两结点的最近公共祖先
    Bitree *p,*ss;
    Stack *s=Initst();  //存放所有祖先的栈
    if(Bserch(t,x)!=NULL && Bserch(t,y)!=NULL){    //如果两个站都在排序树中找的到
        p=t;
        while(p!=NULL){  //对x的寻找，并且记录x的所有祖先，且入栈。
            if(p->data==x){
                push(s,p);
                break;
            }
            if(x<p->data){
                push(s,p);
                p=p->lchild;
            }else{
                push(s,p);
                p=p->rchild;
            }
        }
        while(Bserch(getTop(s),y)==NULL){ 
            pop(s);  //如果栈顶元素不是y的祖先就出栈
        }
        ss=getTop(s);  
        printf("他们的最近公共祖先为：%d\n",ss->data);
    }else{
        printf("他俩都不在里面");
    }
}
int main(){
    int data[maxsize];
    int data1[]={5,2,3,4,1,6,7,8,9,10,11,12,13,15,16};
    int data2[]={12,65,99,2,36,78,16,49,37,5,11,22,33};
    int len=sizeof(data1)/sizeof(int);
    Bitree *t1= CreateBST(data1,len);
    int len2=sizeof(data2)/sizeof(int);
    Bitree *t2= CreateBST(data2,len2);
    findf(t1,9,15);
    findf(t2,16,5);
    return 0;
}