#include<stdio.h>
#include<malloc.h>
#define maxsize 50
typedef struct node {
    int key;
    char cha;
    struct node* lchild, * rchild;
}Bitree;

Bitree *DeleteBST(Bitree *t,int k){
    Bitree *p,*f=NULL,*s,*q;
    int cod=0,type=0;
    p=t;
    while(p){
        if(p->key==k) break;
        f=p;
        if(p->key>k) p=p->lchild,cod=0;
        else p=p->rchild,cod=1;
    }
    if(p==NULL)return t;
    if(p->rchild!=NULL){
        if(f==NULL){
            f=q->rchild;
            q=findr(q->rchild);
            q->lchild=p->lchild;
            free(p);
            return f;
        }else{
            q=findr(q->rchild);
            q->lchild=p->lchild;
            if(cod==0) f->lchild=q->rchild;
            else f->rchild=q->rchild;
            free(q);
            return t;
        }
    }else{
        if(f==NULL){
            f=p->lchild;
            free(p);
            return f;
        }else{
            if(cod==0) f->lchild=q->lchild;
            else f->rchild=q->lchild;
            free(p);
            return t;
        }
    }
}
Bitree *findr(Bitree *t){
    Bitree *p=t,*f=t;
    while(p){
        f=p;
        p=p->lchild;
    }
    return f;
}
Bitree *DeleteBST1(Bitree *t,int k){
    Bitree *p,*f=NULL,*s,*q;
    int cod=0,type=0;
    p=t;
    while(p){
        if(p->key==k) break;
        f=p;
        if(p->key>k) p=p->lchild,cod=0;
        else p=p->rchild,cod=1;
    }
    if(p==NULL)return t;
    if(f==NULL && p->rchild==NULL){
        f=p->lchild;
            free(p);
            return f;
    }else if(f==NULL && p->rchild!=NULL){
            f=q->rchild;
            q=findr(q->rchild);
            q->lchild=p->lchild;
            free(p);
            return f;
    }
    if(p->rchild!=NULL){
            q=findr(q->rchild);
            q->lchild=p->lchild;
            if(cod==0) f->lchild=q->rchild;
            else f->rchild=q->rchild;
            free(q);
            return t;
    }else{
            if(cod==0) f->lchild=q->lchild;
            else f->rchild=q->lchild;
            free(p);
            return t;
    }
}