#include<stdio.h>
#include<malloc.h>
#define maxsize 50
typedef struct node {
    float probabilities;
    char cha;
    struct node* lchild, * rchild;
}Bitree;
typedef struct {    //保存哈夫曼编码的栈
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
int isEmpty(Stack* s) {
    if (s->top == -1) return 1;
    else return 0;
}
void InitStack(Stack* s) {
    s->top = -1;
}
Bitree* getTop(Stack *s){
    if(!isEmpty(s)){
        return s->data[s->top];
    }else return NULL;
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
void printstack(stackc *sc,int i){
    
    for(int j=0;j<=sc->top;j++)
        printf("%d",sc->data[j]);
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
    stackc *sc=malloc(sizeof(stackc));
    sc->top=-1;
    Stack *ss=malloc(sizeof(Stack));
    Stack *ss2=malloc(sizeof(Stack));
    InitStack(ss2);
    InitStack(ss); //保存已经遍历过的栈
    int i=0;
    int cod=0; //0代表左，1代表右
    push(ss,p);
    while(i<len-1){
        p=getTop(ss); 
        if(cod==0){
            if(p->lchild->cha=='x'){
                p=p->lchild;
                push(ss,p);
                sc->top++;
                sc->data[sc->top]=0;
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
                sc->top++;
                sc->data[sc->top]=1;
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
                Pop(ss);
                Pop(ss2);
                p=getTop(ss);
                temp=getTop(ss2);
                sc->top--;
            }
            cod=1;
        }
    }
}
int main() {
    float probabilitie[] = { 0.1,0.3,0.2,0.15,0.05,0.04,0.03,0.13 }; //权值
    char chas[] = { 'A','B','C','D','E','F','G','H' };   //字符
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