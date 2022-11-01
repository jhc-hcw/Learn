#include<stdio.h>
#include<malloc.h>
typedef char datatype;


typedef struct node{
    datatype data;
    struct node *lchild,*rchild;
}Bitree;

Bitree  *f;

typedef struct node1{
    Bitree *data;
    struct node1 *next;
}linklist;
typedef struct {
    linklist *front,*rear;
}linkqueue;

linkqueue* q;

linkqueue * setlinkqueue(){
    linkqueue *q=malloc(sizeof(linkqueue));
    q->front=malloc(sizeof(linklist));
    q->front->next=NULL;q->rear=q->front;
    return q;
}

int linkqueueempty(linkqueue *q){
    if(q->front==q->rear)
        return 1;
    else 
        return 0;
}

void add(linkqueue *q,Bitree* x){
    linklist *t=malloc(sizeof(linklist));
    t->data=x;
    t->next=NULL;
    q->rear->next=t;
    q->rear=t;
}
void delete(linkqueue *q){
    if(!linkqueueempty(q)){
        linklist *t=q->front->next;
        q->front->next=q->front->next->next;
        free(t);
    }else printf("队列为空！\n");
}
Bitree *gettop(linkqueue *q){
    if(!linkqueueempty(q)){
        return q->front->next->data;
    }else printf("队列为空！\n");
}


void addtree(Bitree *tree){
    char a;
    printf("请输入左孩子：");
    fflush(stdin);
    a=getchar();
    if(a!='#'){
        Bitree *t=malloc(sizeof(Bitree));
        t->lchild=NULL;
        t->rchild=NULL;
        tree->lchild=t;
        t->data=a;
        add(q,t);
    }
    printf("请输入右孩子：");
    fflush(stdin);
    a=getchar();
    if(a!='#'){
        Bitree *t=malloc(sizeof(Bitree));
        t->lchild=NULL;
        t->rchild=NULL;
        tree->rchild=t;
        t->data=a;
        add(q,t);
    }
    delete(q);
}
void cc(Bitree *tree){
    int a;
    f=tree;
    add(q,f);
    printf("插入节点吗：");
    scanf("%d",&a);
    while(a==1){
        addtree(f);
        f=gettop(q);
        printf("插入节点吗：");
        scanf("%d",&a);
    }
}

void visite(Bitree *tree){
        printf("%c",tree->data);
}

void treep(Bitree *tree){
    if(tree){
        visite(tree);
        treep(tree->lchild);
        treep(tree->rchild);
    }
}

int main(){
    Bitree *tree=malloc(sizeof(Bitree));
    tree->lchild=NULL;
    tree->rchild=NULL;
    char a;
    q=setlinkqueue();
    printf("请输入根节点：");
    scanf("%c",&a);
    tree->data=a;
    cc(tree);
    treep(tree);
    return 0;
}