#include<stdio.h>
#include<malloc.h>

typedef struct node {
    int data;
    struct node* lchild, * rchild;
}Bitree;
void sort(Bitree** t,int len) {
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len - 1 - i; j++) {
            if (t[j]->data > t[j + 1]->data) {
                Bitree * tt= t[j];
                t[j] = t[j + 1];
                t[j + 1] = tt;
            }
        }
    }
}
 Bitree* createht(Bitree **trees,int len){
     int i=0,j=len,sum;
     Bitree *t, *f,*p;
     Bitree* tree;
     sort(trees,len);
     while (i < len-1) {
         t=trees[i];f=trees[i+1];
         i++;
         sort(trees+i, len - i);
     }
     return trees[len-1];
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
    Bitree** bitrees = malloc(sizeof(Bitree*) * len);
    for (int i = 0; i < len; i++) {
        bitrees[i] = malloc(sizeof(Bitree));
        bitrees[i]->data=data[i];
        bitrees[i]->lchild=NULL;
        bitrees[i]->rchild=NULL;
    }
    Bitree* htree=createht(bitrees,len);
    treep(htree);
    return 0;
}