#include<stdio.h>
#include<malloc.h>

typedef struct node {
    int data;
    struct node* lchild, * rchild;
}Bitree;
typedef struct {
    int data;
    Bitree* tree;
}Treeb;
void sort(Treeb** t,int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (t[j]->data > t[j + 1]->data) {
                Treeb * tt= t[j];
                t[j] = t[j + 1];
                t[j + 1] = tt;
            }
        }
    }
}
 Bitree* createht(Treeb **treeb,int len){
     int i=0,j=len,sum;
     Treeb* t, *f,*p;
     Bitree* tree;
     while (i < len-1) {
         t = treeb[i]; f = treeb[i+1];
         p = malloc(sizeof(Treeb));
         sum= t->data + f->data;
         tree = malloc(sizeof(Bitree));
         tree->data = sum;
         tree->lchild = t->tree;
         tree->rchild = f->tree;
         p->data = sum;
         p->tree = tree;
         treeb[i+1] = p;
         i++;
         sort(treeb+i, len - i);
     }
     return treeb[len-1]->tree;
 }
 void visite(Bitree *tree){
        printf("%d,",tree->data);
}
 void treep(Bitree *tree){
    if(tree){
        visite(tree);
        treep(tree->lchild);
        treep(tree->rchild);
    }
}
int main() {
    int data[] = { 1,2,3,4,5,6,7 };
    int len = sizeof(data) / sizeof(int);
    Treeb** bitrees = malloc(sizeof(Treeb*) * len);
    for (int i = 0; i < len; i++) {
        bitrees[i] = malloc(sizeof(Treeb));
        bitrees[i]->data = data[i];
        bitrees[i]->tree = malloc(sizeof(Bitree));
        bitrees[i]->tree->data = data[i];
        bitrees[i]->tree->lchild = NULL;
        bitrees[i]->tree->rchild = NULL;
    }
    Bitree* htree=createht(bitrees,len);
    treep(htree);
    return 0;
}