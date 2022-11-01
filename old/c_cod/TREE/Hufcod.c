#include<stdio.h>
#include<malloc.h>
typedef struct node {
    float probabilities;
    char cha;
    struct node* lchild, * rchild;
}Bitree;
typedef struct node1{
    void *data;
    struct node1* next;
}Stack;
Stack *Initst(){
    Stack *s=malloc(sizeof(Stack));
    s->data=NULL;
    s->next=NULL;
    return s;
}
int isEmpty(Stack *ls){
    if(ls->next==NULL) return 1;
    else return 0;
}
void* pop(Stack *ls){
   if(!isEmpty(ls)){
       Stack* t=ls->next;
       ls->next=t->next;
       return t->data;
   }else{
       printf("出栈失败！\n");
       return NULL;
   }
}
void* getTop(Stack *ls){
    if(isEmpty(ls))
        return ls->next->data;
    else
        return NULL;
}
void push(Stack *ls,void* x){
    Stack* t=malloc(sizeof(Stack));
    t->data=x;
    t->next=ls->next;
    ls->next=t;
}
void printstack(Stack *sk,int i){
    Stack* t=sk->next;
    int* data;
    while(t){
        data=t->data;
        printf("%d",*data);
    }
    printf("%d\t",i);
}
void sort(Bitree** t, int len) {
    for (int i = 0; i < len - 1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (t[j]->probabilities > t[j + 1]->probabilities) {
                Bitree* tt = t[j];
                t[j] = t[j + 1];
                t[j + 1] = tt;
            }
        }
    }
}
Bitree* createht(Bitree** trees, int len) {
    int i = 0;
    Bitree* t, * f, * p;
    sort(trees, len);
    while (i < len - 1) {
        t = trees[i]; f = trees[i + 1];
        p = malloc(sizeof(Bitree));
        p->probabilities = t->probabilities + f->probabilities;
        p->cha = 'x';
        p->lchild = t;
        p->rchild = f;
        i++;
        trees[i] = p;
        sort(trees + i, len - i);
    }
    return trees[len - 1];
}

void cc(Bitree *t,int len){
    Bitree* p=t;
    Stack *sc=Initst();
    Stack *ss=Initst();
    Stack *ss2=Initst();
    int one=1,zero=0;
    int i=0;
    int cod=0;
    push(ss,p);
    while(i<len-1){
        p=getTop(ss); 
        if(cod==0){
            if(p==NULL) {
                printf("我地吗");
                break;
                }
            if(p->lchild->cha=='x'){
                p=p->lchild;
                push(ss,p);
                push(sc,&zero);
                cod=0;
                continue;
            }else{
                p=p->lchild;
                printf("%c:",p->cha);
                printstack(sc,0);
                cod=1;
                continue;
            }
        }else{
            if(p->rchild->cha=='x'){
                push(ss2,p);
                i++;
                push(sc,&one);
                p=p->rchild;
                push(ss,p);
                cod=0;
            }else{
                push(ss2,p);
                p=p->rchild;
                printf("%c:",p->cha);
                printstack(sc,1);
                i++;
                cod=-1;
            }
        }
        if(cod==-1){
            p=getTop(ss);
            Bitree *temp=getTop(ss2);
            while(temp==p && temp!=NULL){
                pop(ss);
                pop(ss2);
                p=getTop(ss);
                temp=getTop(ss2);
                pop(sc);
            }
            cod=1;
        }
    }
}
int main() {
    // float probabilitie[] = { 0.4,0.3,0.15,0.005,0.004,0.003,0.003 };
    // char chas[] = { 'A','B','C','D','E','F','G' };
    float probabilitie[] = { 0.05,0.1,0.15,0.08,0.01,0.2,0.18,0.13,0.03,0.07 };
    char chas[] = { 'A','B','C','D','E','F','G','H','I','J'};
    int len = sizeof(chas) / sizeof(char);
    Bitree** bitrees = malloc(sizeof(Bitree*) * len);
    for (int i = 0; i < len; i++) {
        bitrees[i] = malloc(sizeof(Bitree));
        bitrees[i]->cha = chas[i];
        bitrees[i]->probabilities = probabilitie[i];
        bitrees[i]->lchild = NULL;
        bitrees[i]->rchild = NULL;
    }
    Bitree* htree = createht(bitrees, len);
    cc(htree,len);
    return 0;
}