#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}LinkList;

LinkList *create(LinkList * head){
    LinkList *p,*q;
    int k;
    q=head;
    scanf("%d",&k);
    while(k>0){
        p=malloc(sizeof(LinkList));
        scanf("%d",&p->data);
        q->next=p;
        q=q->next;
        scanf("%d",&k);
    }
    q->next=NULL;
}

LinkList * mergelink(LinkList* p,LinkList* q){
    LinkList *h,*r;
    h=malloc(sizeof(LinkList));
    h->next=NULL;
    r=h;
    while(p!=NULL && q!=NULL){
        if(p->data<=q->data){
            r->next=p;
            r=p;
            p=p->next;
        }
        else{
            r->next=q;
            r=q;
            q=q->next;
        }
    }
    if(p==NULL)r->next=q;
    else  r->next=p;
    return h;
}
void LLprint(LinkList *head){
    LinkList *p;
    p=head->next;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("\n");
}
void LLinit(LinkList *L){
     int data,flag;
     LinkList * tail=L;;
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
}
int main(){
    LinkList *head1,*head2,*head3;
    head1=malloc(sizeof(LinkList));
    head2=malloc(sizeof(LinkList));
    // create(head1);
    // create(head2);
    LLinit(head1);
    LLinit(head2);
    LLprint(head1);
    LLprint(head2);
    head3=mergelink(head1->next,head2->next);
    LLprint(head3);
    return 0;
}