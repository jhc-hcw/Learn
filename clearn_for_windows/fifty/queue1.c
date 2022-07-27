#include<stdio.h>
#include<malloc.h>
#define Maxlen 50 

typedef struct {
    int data[Maxlen],front,rear;
}sequeue;

void queueinit(sequeue *q){
    q->front=0;
    q->rear=0;
}

int queuefull(sequeue *q){
    if(q->front==(q->rear+1)%Maxlen)
        return 1;
    else
        return 0;
}

int queuempty(sequeue *q){
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}
void add(sequeue *q,int x){
    if(!queuefull(q)){
        q->rear=(q->rear+1)%Maxlen;
        q->data[q->rear]=x;
    }else printf("队列满，入队失败！\n");
}
void delete(sequeue *q){
    if(!queuempty(q))
        q->front=(q->front+1)%Maxlen;
    else
        printf("队列为空，出队失败！\n");
}
int main(){
    sequeue *q=malloc(sizeof(sequeue));
    queueinit(q);
    add(q,1);
    add(q,2);
    add(q,3);
    add(q,4);
    printf("队列头为%d.尾为%d\n",q->data[q->front+1],q->data[q->rear]);
    delete(q);
    add(q,5);
    printf("队列头为%d.尾为%d\n",q->data[q->front+1],q->data[q->rear]);
    return 1;
}