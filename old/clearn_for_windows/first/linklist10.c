#include<stdio.h>
#include<malloc.h>
typedef struct LinkList{
    char data;
    struct LinkList * next;
}SLinkList;

void SLLinit(SLinkList *L){
     char data,flag;
    //  int flag;
     SLinkList * tail=L;;
     
    while(1){
        printf("请输入要存入的字符以a0结尾：");
        scanf("%c",&data);
        fflush(stdin);
        if(data=='a'){
            printf("是否继续输入非a继续：");
            scanf("%c",&flag);
            fflush(stdin);
            if(flag=='a'){
                break;
            }
        }
        SLinkList* next=malloc(sizeof(SLinkList));
        next->data=data;
        next->next=NULL;
        tail->next=next;
        tail=next;
    }
}
void SLLprint(SLinkList *head){
    SLinkList *p;
    p=head->next;
    while(p!=NULL){
        printf("%c->",p->data);
        p=p->next;
    }
    printf("\n");
}
void subSll(SLinkList *s,int i,int k){
    SLinkList *p=s,*q=s;
    int ii=0;
    if(i>k){
        printf("删除位置错误！");
        return;
    }
    while(ii<i-1 && p!=NULL){
        p=p->next;
        q=q->next;
        ii++;
    }
    ii--;
    while(ii<k-1 && q!=NULL){
        q=q->next;
        ii++;
    }
    if(p!=NULL && q!=NULL){
        p->next=q->next;
    }else{
        printf("删除位置错误！");
    }
}
int main(){
    int i,k;
    SLinkList *head=malloc(sizeof(SLinkList));
    SLLinit(head);
    SLLprint(head);
    printf("请输入你要删除起始：");
    scanf("%d %d",&i,&k);
    subSll(head,i,k);
    SLLprint(head);
}