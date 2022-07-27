#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}LinkList;

LinkList* LLinit(LinkList *L){
     int data,flag;
     LinkList *tail=L;
    while(1){
        printf("请输入要存入的数：");
        scanf("%d",&data);
        if(data==0){
            printf("是否继续输入非零继续：");
            scanf("%d",&flag);
            if(flag==0){
                break;
            }
        }
        LinkList* next=malloc(sizeof(LinkList));
        next->data=data;
        next->next=NULL;
        tail->next=next;
        tail=next;
    }
    tail->next=L->next;
    return L->next;
}
LinkList* LLprint(LinkList *s){    
    LinkList *p;
    int k=0;
    p=s;
    while(p!=s || k==0){
        printf("%d->",p->data);
        p=p->next;
        k=1;
    }
    printf("\n");
    return  p;
} 
void Ldelete(LinkList *s){      //删除节点
    LinkList *p=s;
    while(p->next->next!=s){
        p=p->next;
    }
    LinkList *t=p->next;
    p->next=p->next->next;
    free(t);
}
void LLinsert(LinkList *s,int i,int x){     //插入节点
    LinkList *p=s,*r;
    int k=0;
    while(p->next->data!=i && (p!=s || k==0)){
        p=p->next;
        k=1;
    }
    if(p->next->data==i){
        r=malloc(sizeof(LinkList));
        r->data=x;
        r->next=p->next;
        p->next=r;
    }else{
        printf("找不到捏。\n");
    }
}
int main(){
    LinkList * head=malloc(sizeof(LinkList));
    LinkList * s=LLinit(head);
    LLprint(s);
    Ldelete(s);   //删除s前一个节点即输入的尾节点
    LLprint(s);     
    LLinsert(s,4,88);  //第四个节点前插入88
    LLprint(s);
    return 0;
}
