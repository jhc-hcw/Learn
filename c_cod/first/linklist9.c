#include<stdio.h>
#include<malloc.h>

typedef struct dnode{
    int data;
    struct dnode *next,*prior;
}DLinkList;

DLinkList* DLLinit(DLinkList *L){
     int data,flag;
     DLinkList * tail=L;;
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
        DLinkList* s=malloc(sizeof(DLinkList));
        s->data=data;
        s->next=NULL;
        tail->next=s;
        tail=tail->next;
    }
    tail->next=L->next;
    return L->next;
}
void DLLprint(DLinkList *head){
    DLinkList *p=head;
    int k=0;
    while(p!=head || k==0){
        printf("%d->",p->data);
        p=p->next;
        k=1;
    }
    printf("\n");
}
void reDLLprint(DLinkList *head){
    DLinkList *p=head;
    int k=0;
    while(p!=head || k==0){
        printf("%d->",p->data);
        p=p->prior;
        k=1;
    }
    printf("\n");
}
void DLLrelink(DLinkList *head){
    DLinkList *p=head,*l=p->next;
    int k=0;
    while(l!=head->next || k==0){
        l->prior=p;
        p=p->next;
        l=l->next;
        k=1;
    }
}
int main(){
    DLinkList *head,*s;
    head=malloc(sizeof(DLinkList));
    s=DLLinit(head);
    DLLprint(s);
    DLLrelink(s);
    reDLLprint(s);
    return 0;
}