#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}linklist;
typedef struct {
    linklist *front,*rear;
}linkqueue;

linkqueue * setlinkqueue(){
    linkqueue *q=malloc(sizeof(linkqueue));
    q->front=malloc(sizeof(linklist));
    q->front->next=NULL;q->rear=q->front;
    return q;
}

int linkqueueempty(linkqueue *q){
    if(q->front==q->rear)
        return 1;
    else 
        return 0;
}

void add(linkqueue *q,int x){
    linklist *t=malloc(sizeof(linklist));
    t->data=x;
    t->next=NULL;
    q->rear->next=t;
    q->rear=t;
}
void delete(linkqueue *q){
    if(!linkqueueempty(q)){
        linklist *t=q->front->next;
        q->front->next=q->front->next->next;
        free(t);
    }else printf("队列为空！\n");
}

void linkqueuefull(linkqueue *q){
}

int main(){
    linkqueue *q=setlinkqueue();
    add(q,1);
    add(q,2);
    add(q,3);
    add(q,4);
    printf("队列头为%d.尾为%d\n",q->front->next->data,q->rear->data);
    delete(q);
    add(q,5);
    printf("队列头为%d.尾为%d\n",q->front->next->data,q->rear->data);
    return 1;
}