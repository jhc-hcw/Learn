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
LinkList * insert(LinkList *la,int i, int b){
    LinkList *p,*s;
    int j;
    p=la;
    j=1;
    while(p!=NULL && j<i){
        p=p->next;
        j=j+1;
    }
    if(p==NULL || i<=0) printf("No this positon");
    else{
        s=malloc(sizeof(LinkList));
        s->data=b;
        s->next=p->next;
        p->next=s;
    }
    return la;
}
int main(){
    LinkList *head=malloc(sizeof(LinkList));
    int a,b;
    LLinit(head);
    printf("请输入你要插入的位置与数值：");
    scanf("%d %d",&a,&b);
    insert(head,a,b);
    LLprint(head);
    return 0;
}