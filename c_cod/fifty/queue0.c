#include<stdio.h>
#include<malloc.h>
#define Maxlen 50 

typedef struct {
    char data[Maxlen];
    int front,rear;
}sequeue;

sequeue* InitQueue(sequeue *q){
    q=malloc(sizeof(sequeue));
    q->front=0;
    q->rear=0;
    return q;
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
char GetHead(sequeue *q){
    if(!queuempty(q)){
        return q->data[q->front+1];
    }else{
        printf("队列空！");
        return NULL;
    }
}
void add(sequeue *q,char x){
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
void print(){
    sequeue *q;
    char x,y;
    x='e'; y='c';
    q=InitQueue(q);
    add(q,'h');
    add(q,'r');
    add(q,y);
    x=GetHead(q);
    delete(q);
    add(q,x);  x=GetHead(q);
    delete(q);   add(q,'a');
    while(queuempty(q)==0){
        y=GetHead(q);
        delete(q);
        printf("%c",y);
    }
    printf("%c\n",x);
}

int main(){
    print();
    return 0;
}
