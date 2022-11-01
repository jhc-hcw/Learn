#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}LinkLilst;

LinkLilst *create(LinkLilst * head){
    LinkLilst *p,*q;
    int k;
    q=head;
    scanf("%d",&k);
    while(k>0){
        p=malloc(sizeof(LinkLilst));
        scanf("%d",&p->data);
        q->next=p;
        q=q->next;
        scanf("%d",&k);
    }
    q->next=NULL;
}

int main(){
    LinkLilst *head=malloc(sizeof(LinkLilst));
    head->data=0;
    head->next=NULL;
    create(head);
    LinkLilst *p=head->next;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    return 0;
}