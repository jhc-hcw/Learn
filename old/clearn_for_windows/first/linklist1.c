#include<stdio.h>
#include<malloc.h>
typedef struct LinkList{
    int data;
    struct LinkList * next;
}LinkList;

LinkList *setnull(LinkList *L){
    LinkList *temp=L->next;
    L->next==NULL;
    while(temp!=NULL){
        LinkList *d=temp;
        temp=temp->next;
        free(d);
    }
    return L;
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

LinkList * Get(LinkList *L,int i){
    LinkList* temp=L->next;
    for(int j=1;temp!=NULL;j++){
        if(i==j)
            return temp;
        temp=temp->next;
    }
    return NULL;
}

LinkList *LLlocate(LinkList *L,int x){
    LinkList* temp=L->next;
    int i;
    while(temp!=NULL){
        if(temp->data==x)
            return temp;
        temp=temp->next;
    }
    return NULL;
}
void LLinsert(LinkList *L,int i,int x){
    LinkList* p=L,*s;
    int j=0;
    while(p!=NULL && j<j-1){
        p=p->next;
        j++;
    }
    if(p==NULL)printf("序号错误");
    else{
        s=(LinkList*)malloc(sizeof(LinkList));
        s->data=x;
        s->next=p->next;
        p->next=s;
    }
}

void LLdelete(LinkList *L,int i){
    LinkList *p=L,*u;
    int j=0;
    while(p!=NULL && j<j-1){
        p=p->next;
        j++;
    }
    if(p!=NULL && p->next!=NULL){
        u=p->next;
        p->next=u->next;
        free(u);
    }
}

void LLprint(LinkList *L){
    LinkList* temp;
    temp=L->next;
    if(temp==NULL){
        printf("嘛都没有，怎么打印");
        return;
    }
    while(1){
        if(temp->next!=NULL){
            printf("%d->",temp->data);
            temp=temp->next;
        }else{
            printf("%d->",temp->data);
            break;
        }
    }
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
    LinkList *head;
    head =malloc(sizeof(LinkList));
    head->data=0;
    head->next=NULL;
    LLinit(head);
    LLprint(head);
    printf("\n--%d--\n",Get(head,3)->data);
    printf("\n--%d--\n",LLlocate(head,3));
    return 0;
}