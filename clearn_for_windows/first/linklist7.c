#include<stdio.h>
#include<malloc.h>

typedef struct node{
    int data;
    struct node *next;
}LinkList;



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
int LLlenth(LinkList *L){
    int lenth=0;
    LinkList *temp=L->next;
    while(temp!=NULL){
        lenth++;
        temp=temp->next;
    }
    return lenth;
}

void LLinverse(LinkList *L){
    int l=LLlenth(L),i=l-1;
    LinkList *p[l],*s=L;
    while(s->next!=NULL){
        p[i]=s->next;
        s=s->next;
        i--;
    }
    i++;
    s=L;
    while(i<l){
        s->next=p[i];
        s=s->next;
        i++;
    }
    s->next=NULL;
}

int main(){
    LinkList *head=malloc(sizeof(LinkList));
    head->data=0;
    LLinit(head);
    LLprint(head);
    LLinverse(head);
    LLprint(head);
}