#include<stdio.h>
#include<malloc.h>
#define maxlen 51
typedef struct{
     int data[maxlen];
     int top,front,rear;
}sta_and_que;

typedef struct {
    int data[maxlen],front,rear;
}sequeue;

void queueinit(sta_and_que *q){
    q->front=0;
    q->rear=0;
}

int queuefull(sta_and_que *q){
    if(q->front==(q->rear+1)%maxlen)
        return 1;
    else
        return 0;
}

int queuempty(sta_and_que *q){
    if(q->front==q->rear)
        return 1;
    else
        return 0;
}
void add(sta_and_que *q,int x){
    if(!queuefull(q)){
        q->rear=(q->rear+1)%maxlen;
        q->data[q->rear]=x;
    }else printf("队列满，入队失败！\n");
}
void delete(sta_and_que *q){
    if(!queuempty(q))
        q->front=(q->front+1)%maxlen;
    else
        printf("队列为空，出队失败！\n");
}

sta_and_que * Sskinit(){
    sta_and_que *ssk=malloc(sizeof(sta_and_que));
    ssk->top=-1;
    return ssk;
}
int Pop(sta_and_que *ssk){
    if(ssk->top==0){
        printf("空空如也！");
        return;
    }
    ssk->top--;
    return ssk->data[ssk->top+1];
}
void push(sta_and_que *ssk,int x){
    if(ssk->top==maxlen-1){
        printf("插入失败！栈满捏！\n");
        return;
    }
    ssk->data[ssk->top+1]=x;
    ssk->top++;
}
void stackprintf(sta_and_que *ssk){
    printf("<-");
    for(int i=1;i<ssk->top+1;i++){
        printf("%d->",ssk->data[i]);
    }
    printf("-|\n");
}

void change(sta_and_que *s){
    int i=0;
    sta_and_que * q=malloc(sizeof(sta_and_que));
    queueinit(q);
    while(s->rear!=maxlen/2){
        int t=s->data[s->front+1];
        if(t%2==1){
            delete(s);
            add(s,t);
        }else{
            add(q,t);
            delete(s);
        }
    }
    while(!queuempty(q)){
        add(s,q->data[q->front]);
        delete(q);
    }
}

int main(){
    sta_and_que *s=malloc(sizeof(sta_and_que));
    for(int i=1;i<maxlen;i++){
        s->data[i]=i;
    }
    s->top=maxlen-1;
    s->front=0;
    s->rear=maxlen-1;
    change(s);
    stackprintf(s);
}