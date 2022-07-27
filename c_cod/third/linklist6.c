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

void sortinsert(LinkList *L,int x){
    LinkList *s=L,*t=malloc(sizeof(LinkList));
    t->data=x;
    int k=0;
    while(s->next!=NULL){
        if(x>s->data && x<=s->next->data){
            t->data=x;
            t->next=s->next;
            s->next=t;
            k=1;
            break;
        }
        s=s->next;
    }
    if(k==0){
        t->next=NULL;
        s->next=t;
    }
}

int main(){
    LinkList *head=malloc(sizeof(LinkList));
    head->data=0;
    LLinit(head);
    sortinsert(head,4); //插入数字四到一个有序链表中
    LLprint(head);
    return 0;
}