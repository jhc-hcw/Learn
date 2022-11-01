#include<stdio.h>
#include<malloc.h>
#define Maxlen 50 

typedef struct {
    int data[Maxlen],num,rear;
}sequeue;

void queueinit(sequeue *q){
    q->num=0;
    q->rear=0;
}

int queuefull(sequeue *q){
    if(q->num==Maxlen)
        return 1;
    else
        return 0;
}

int queuempty(sequeue *q){
    if(q->num==0)
        return 1;
    else
        return 0;
}
void add(sequeue *q,int x){
    if(!queuefull(q)){
        q->rear=(q->rear+1)%Maxlen;
        q->data[q->rear]=x;
        q->num++;
    }else printf("队列满，入队失败！\n");
}
int delete(sequeue *q){
    if(!queuempty(q)){
       q->num--;
    }
    else
        printf("队列为空，出队失败！\n");
}
int getfront(sequeue *q){
    if(!queuempty(q)){
       if(q->num<=q->rear)
           return q->data[(q->rear-q->num)+1];
        else
           return q->data[(q->rear-q->num)+Maxlen+1];
    }
    else{
        printf("队列为空！\n");
        return NULL;
    }
}
int main(){
    sequeue *q=malloc(sizeof(sequeue));
    queueinit(q);
    add(q,1);
    add(q,2);
    add(q,3);
    add(q,4);
    printf("队列头为%d.尾为%d\n",getfront(q),q->data[q->rear]);
    delete(q);
    printf("队列头为%d.尾为%d\n",getfront(q),q->data[q->rear]);
    add(q,5);
    printf("队列头为%d.尾为%d\n",getfront(q),q->data[q->rear]);
    return 1;
}

