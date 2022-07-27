#include<stdio.h>
#include<malloc.h>

typedef struct node{
    void *data;
    struct node* next;
}linkstack;
linkstack *Initst(){
    linkstack *s=malloc(sizeof(linkstack));
    s->data=NULL;
    s->next=NULL;
    return s;
}
int isEmpty(linkstack *ls){
    if(ls->next==NULL) return 1;
    else return 0;
}
void* pop(linkstack *ls){
   if(!isEmpty(ls)){
       linkstack* t=ls->next;
       ls->next=t->next;
       return t->data;
   }else{
       printf("出栈失败！\n");
       return NULL;
   }
}
void* getTop(linkstack *ls){
    if(isEmpty(ls))
        return ls->data;
    else
        return NULL;
}
void push(linkstack *ls,void* x){
    linkstack* t=malloc(sizeof(linkstack));
    t->data=x;
    t->next=ls->next;
}