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
    int l=LLlenth(L),i=l-1;     //计算链表长度
    LinkList *p[l],*s=L;    //创建一个指针数组，用于存放各节点的值，
    while(s->next!=NULL){      //将所有节点倒着装进数组中
        p[i]=s->next;
        s=s->next;
        i--;
    }
    i++;
    s=L;
    while(i<l){              //将链表重组，对照着数组,顺序重新链接节点。
        s->next=p[i];
        s=s->next;
        i++;
    }
    s->next=NULL;       //最后一个节点是原先第一个节点，所以next要置空。
}

int main(){
    LinkList *head=malloc(sizeof(LinkList));
    head->data=0;
    LLinit(head);
    LLprint(head);
    LLinverse(head);
    LLprint(head);
}