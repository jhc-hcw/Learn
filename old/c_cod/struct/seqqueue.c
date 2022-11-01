#include<stdio.h>
#define maxsize 50
typedef struct {
    int data[maxsize];
    int front,rear;
}seqqueue;

void add(seqqueue *s,int x){
    if(queuefull(s)){
        printf("失败，满了");
    }else{
        s->rear=(s->rear+1)%maxsize;
        s->data[s->rear]=x;
    }
}
void queuedel(seqqueue *s){
    if(queuenull(s)){
        printf("失败，为空")
    }else{
        s->front=(s->front+1)/maxsize;
    }
}
int queuenull(seqqueue *s){
    if(s->rear=s->front)
        return 1;
    else
        return 0;
}
int queuefull(seqqueue *s){
    if(s->front=(s->rear+1)%maxsize)
        return 1;
    else
        return 0;
}


int main(){
    return 0;
}