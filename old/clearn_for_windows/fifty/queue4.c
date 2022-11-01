#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}linklist;

typedef struct{
    linklist *head,*rear;
}linkqueue;


linkqueue * setlinkqueue(){
    linklist *q=malloc(sizeof(linklist));
    q->data=-1;
    q->next=q;
    linkqueue *lq=malloc(sizeof(linkqueue));
    lq->head=q;
    lq->rear=q;
    return lq;
}

int linkqueueempty(linkqueue *lq){
    if(lq->rear==lq->head)
        return 1;
    else 
        return 0;
}

void add(linkqueue *lq,int x){
    linklist *t=malloc(sizeof(linklist));
    t->data=x;
    t->next=lq->head;
    lq->rear->next=t;
    lq->rear=t;
}
void delete(linkqueue *lq){
    if(!linkqueueempty(lq)){
        linklist *t=lq->rear->next->next;
        lq->rear->next->next=lq->rear->next->next->next;
        free(t);
    }else printf("队列为空！\n");
}
linklist * getfront(linkqueue *lq){
    if(!linkqueueempty(lq)){
        return lq->rear->next->next;
    }else printf("队列为空！\n");
}

int main(){
    linkqueue *lq=setlinkqueue();
    add(lq,1);
    add(lq,2);
    add(lq,3);
    add(lq,4);
    printf("队列头为%d.尾为%d\n",getfront(lq)->data,lq->rear->data);
    delete(lq);
    add(lq,5);
    printf("队列头为%d.尾为%d\n",getfront(lq)->data,lq->rear->data);
    return 1;
}