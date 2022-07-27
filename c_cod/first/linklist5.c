#include<stdio.h>
#include<malloc.h>

typedef struct dnode{
    int data;
    struct dnode *next,*prior;
}DLinkList;

DLinkList * insert(DLinkList *head,int i,int x){
    DLinkList *s,*p;int j;
    s=malloc(sizeof(DLinkList));
    s->data=x;
    if(i==0){
        s->next=head;
        head->prior=s;
        head=s;
    }else{
        p=head;
        j=0;
        while(p!=NULL && j<i){
            j=j+1;
            p=p->next;
        }

        if(p!=NULL){
            if(p->next==NULL){
                p->next=s;s->next==NULL;
                s->prior=p;
            }else{
                s->next=p->next;
                p->next->prior=s;
                p->next=s;
                s->prior=p;
            }
        }else printf("can not find node");
    }
}

void DLLinit(DLinkList *L){
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
        s->prior=tail;
        tail=tail->next;
    }
}

void DLLprint(DLinkList *head){
    DLinkList *p;
    p=head->next;
    while(p!=NULL){
        printf("%d->",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    DLinkList *p=malloc(sizeof(DLinkList));
    DLLinit(p);
    DLLprint(p);
    insert(p,1,99);
    DLLprint(p);
    return 0;
}