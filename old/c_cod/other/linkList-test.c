#include <stdio.h>
#include <malloc.h>
typedef int datatype;
typedef struct Linklist{
    datatype data;
    struct Linklist * next;
}linklist;
linklist *L;
linklist *tail;
int insert(){
    int count;
    int data;
    while(1){
        printf("请您输入，0退出：");
        int flag;
        scanf("%d",&flag);
        if(flag==0) break;
        printf("请输入要存入的数：");
        scanf("%d",&data);
        linklist* next=(linklist*)malloc(sizeof(linklist));
        next->data=data;
        next->next=NULL;
        tail->next=next;
        tail=next;
        count++;
    }
    return count;
}
void dellink(){
    int index,i=1;
    linklist* temp,*pre;
    pre=L;
    temp=L->next;
    printf("请输入你要删除的位置：");
    scanf("%d",&index);
    while(1){
        if(temp->next!=NULL && i!=index){
            pre=temp;
            temp=temp->next;
            i++;
            continue;
        }else if(temp->next!=NULL && i==index){
            pre->next=temp->next;
            free(temp);
            break;
        }else if(temp->next==NULL && i==index){
            pre->next=NULL;
            free(temp);
            break;
        }else if(temp->next==NULL && i!=index){
            printf("没找到节点");
            break;
        }
    }
}
void linkprint(){
    linklist* temp;
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
int main(){
    L=(linklist*)malloc(sizeof(linklist));
    L->data=NULL;
    L->next=NULL;
    tail=L;
    insert();
    linkprint();
    dellink();
    linkprint();
    return 0;
}