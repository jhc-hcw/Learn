#include<stdio.h>
#include<malloc.h>
#define maxsize 50
typedef struct node {
    float probabilities;
    char cha;
    struct node* lchild, * rchild;
}Bitree;
typedef struct {
    int data[maxsize];
    int top;
}stackc;
typedef struct {
    Bitree* data[maxsize];
    int top;
}Stack;
typedef struct {
    Bitree* tree;
    int cod[10],len;
}trunk;
Stack* stackInit(){
    Stack *p=malloc(sizeof(Stack));
    p->top=-1;
    return p;
}
int isEmpty(Stack* s) {
    if (s->top == -1) return 1;
    else return 0;
}
void InitStack(Stack* s) {
    s->top = -1;
}
Bitree* Pop(Stack* s) {
    if (!isEmpty(s)) {
        s->top--;
        return s->data[s->top + 1];
    }
    else {
        return NULL;
    }
}
void push(Stack* s, Bitree* t) {
    if (s->top < 49) {
        s->top++;
        s->data[s->top] = t;
    }
    else {
        printf("error");
    }
}
void printstack(stackc s) {
    if (s.top != -1)
        for (int i = 0; i <= s.top; i++) {
            printf("%d", s.data[i]);
        }
    printf("  ");
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
void cc(Bitree* tree, int len) {
    trunk *t=malloc(sizeof(trunk)*(len-1));
    int i = 0;
    stackc sc;
    sc.top = -1;
    Bitree* p = tree;
    Stack* ss = malloc(sizeof(Stack));
    InitStack(ss);
    push(ss, p);
    t[i].tree=p;
    t[i].len=-1;
    while (!isEmpty(ss)) {
        p=Pop(ss);
        if(isEmpty(ss)){
            i++;
        }else{
            sc.top--;
        }
        if(p->lchild->cha!='x'&&p->rchild->cha=='x'){
            push(ss,p->rchild);
            sc.top++;
            sc.data[sc.top]=1;
            t[i].tree=p->rchild;
            t[i].len=sc.top;
            for(int j=0;j<=sc.top;j++)
                t[i].cod[j]=sc.data[j];
        }else if(p->lchild->cha=='x' && p->rchild->cha!='x'){
            push(ss,p->lchild);
            sc.top++;
            sc.data[sc.top]=0;
            t[i].tree=p->lchild;
            t[i].len=sc.top;
            for(int j=0;j<=sc.top;j++)
                t[i].cod[j]=sc.data[j];
        }else if(p->lchild->cha=='x' && p->lchild->cha=='x'){
            push(ss,p->rchild);
            push(ss,p->lchild);
            t[i].tree=p->lchild;
            sc.top++;
            sc.data[sc.top]=0;
            t[i].len=sc.top;
            for(int j=0;j<=sc.top;j++)
                t[i].cod[j]=sc.data[j];
            t[i+1].tree=p->rchild;
            i++;
            sc.data[sc.top]=1;
            t[i].len=sc.top;
            for(int j=0;j<=sc.top;j++)
                t[i].cod[j]=sc.data[j];
        }
    }
    for(int i=0;i<len-1;i++){
        if(t[i].tree->lchild->cha!='x' && t[i].tree->rchild->cha=='x'){
            printf("%c:",t[i].tree->lchild->cha);
            for(int j=0;j<=t[i].len;j++)
                printf("%d",t[i].cod[j]);
            printf("0\t");
        }else if(t[i].tree->rchild->cha!='x' && t[i].tree->lchild->cha=='x'){
            printf("%c:",t[i].tree->rchild->cha);
            for(int j=0;j<=t[i].len;j++)
                printf("%d",t[i].cod[j]);
            printf("1\t");
        }else if(t[i].tree->lchild->cha!='x' && t[i].tree->rchild->cha!='x'){
            printf("%c:",t[i].tree->lchild->cha);
            for(int j=0;j<=t[i].len;j++)
                printf("%d",t[i].cod[j]);
            printf("0\t");
            printf("%c:",t[i].tree->rchild->cha);
            for(int j=0;j<=t[i].len;j++)
                printf("%d",t[i].cod[j]);
            printf("1\t");
        }
    }
}
int main() {
    float probabilitie[] = { 0.4,0.3,0.15,0.005,0.004,0.003,0.003 };
    char chas[] = { 'A','B','C','D','E','F','G' };
    // float probabilitie[] = { 0.05,0.1,0.15,0.08,0.01,0.2,0.18,0.13,0.03,0.07 };
    // char chas[] = { 'A','B','C','D','E','F','G','H','I','J'};
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