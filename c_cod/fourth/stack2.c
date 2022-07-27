#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node * next;
}linkstack;

linkstack * pop(linkstack *ls){
    linkstack * rst;
    if(ls==NULL){
        printf("栈为空！");
        return NULL;
    }
    rst=ls->next;
    free(ls);
    return rst;
}
int getTop(linkstack *ls){
    if(ls!=NULL)
        return ls->data;
    else
        printf("栈空");

}
linkstack* push(linkstack *ls,int x){
    linkstack* t=malloc(sizeof(linkstack));
    t->data=x;
    t->next=ls;
    return t;
}

void stackpritn(linkstack *ls){
    linkstack *t=ls;
    printf("<-");
    while(t!=NULL){
        printf("%d<-",t->data);
        t=t->next;
    }
    printf("-|\n");
}

int main(){
    linkstack *ls=NULL;
    int data;
    while(printf("继续输入吗"),scanf("%d",&data,data),data){
        printf("输入要入栈的数：");
        scanf("%d",&data);
        ls=push(ls,data);
    }
    stackpritn(ls);
    ls=pop(ls);
    stackpritn(ls);
    ls=pop(ls);
    stackpritn(ls);
    ls=pop(ls);
    stackpritn(ls);
    return 0;
}