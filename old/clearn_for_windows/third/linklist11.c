#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int index,passw;
    struct node *next;
}LinkList;

LinkList* Linit(){  //创建链表，而且输入密码
    LinkList *L=malloc(sizeof(LinkList*));
    L->passw=-1;
    L->index=0;
    LinkList *p=L;
    int passw,flag,index=1;
    while(1){
        printf("输入1才能继续输入：");
        scanf("%d",&flag);
        if(flag!=1)break;
        printf("请输入密码：");
        scanf("%d",&passw);
        LinkList *t=malloc(sizeof(LinkList));
        t->passw=passw;
        t->index=index;
        p->next=t;
        p=t;
        index++;
    }
    p->next=L->next;
    return L->next;
}
LinkList* LLprint(LinkList *s){     //打印链表
    LinkList *p; 
    int k=0;
    p=s;
    while(p!=s || k==0){
        printf("%d ->",p->passw);
        p=p->next;
        k=1;
    }
    printf("\n");
    return  p;
} 
void cc(LinkList *s,int m){
    LinkList *p=s;
    int i=m;
    while(p->next->next!=p){  //保证要有两个以上节点才能在循环内部操作。
        for(int j=1;j<i-1;j++){  //找到要删除的节点的前一个节点。
        p=p->next;
    }
    printf("%d->",p->next->index);
    i=p->next->passw;    //保留节点的密码
    LinkList *t=p->next;   
    p->next=p->next->next;   //删除选中节点
    p=p->next;
    free(t);
    }
    for(int j=1;j<i-1;j++)   //只剩两个元素，最后一次报数。
        p=p->next;
    printf("%d->%d",p->index,p->next->index);     //打印最后两个元素，最后一个元素无需报数。
    free(p->next);
    free(p);
}
int main(){
    LinkList * s=Linit();
    LLprint(s);
    cc(s,20); //初值20
    return 0;
}