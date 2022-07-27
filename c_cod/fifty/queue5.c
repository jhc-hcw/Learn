#include<stdio.h>
#include<malloc.h>
#define maxlen 50
typedef struct{
     int data[maxlen];
     int top,front,rear,flag;
}sta_and_que;


void queueinit(sta_and_que *q){
    q->front=0;
    q->rear=0;
    q->flag=0;
}

int queuefull(sta_and_que *q){
    if(q->front==q->rear && q->flag==1)
        return 1;
    else
        return 0;
}

int queuempty(sta_and_que *q){
    if(q->front==q->rear && q->flag==0)
        return 1;
    else
        return 0;
}
void add(sta_and_que *q,int x){
    if(!queuefull(q)){
        q->rear=(q->rear+1)%maxlen;
        q->data[q->rear]=x;
        q->flag=1;
    }else printf("队列满，入队失败！\n");
}
void delete(sta_and_que *q){
    if(!queuempty(q)){
        q->front=(q->front+1)%maxlen;
        q->flag=0;
    }
    else
        printf("队列为空，出队失败！\n");
}
int getfront(sta_and_que *q){
    if(!queuempty(q)){
        return q->data[(q->front+1)%maxlen];
    }else {
        printf("队列为空\n");
        return -1;
    }
}
void stackprintf(sta_and_que *ssk){
    printf("|-");
    for(int i=0;i<ssk->top+1;i++){
        printf("%d->",ssk->data[i]);
    }
    printf("\n");
}

void change(sta_and_que *s){
    int i=0,k=1;
    sta_and_que * q=malloc(sizeof(sta_and_que));
    queueinit(q);
    while(s->rear!=maxlen/2-1){
        int t=getfront(s);
        if(k==1){
            delete(s);
            add(s,t);
            k=0;
        }else{
            delete(s);
            add(q,t);
            k=1;
        }
    }
    while(!queuempty(q)){
        add(s,getfront(q));
        delete(q);
    }
}

int main(){
    sta_and_que *s=malloc(sizeof(sta_and_que));
    for(int i=0;i<maxlen;i++){
        s->data[i]=(1+i);
    }
    s->top=maxlen-1;
    s->front=maxlen-1;
    s->rear=maxlen-1;
    s->flag=1;
    stackprintf(s);
    change(s);
    stackprintf(s);
}