#include<stdio.h>
#include<string.h>
#define n 7
#define m 2*n-1
#define maxval 100.0
typedef struct{
    float weight;
    int parent,lchild,rchild;
}hufmtree;

hufmtree tree[2*n-1];
Huffman(hufmtree tree[]){
    int i,j,p1,p2;
    float small,small2,f;
    for(i=0;i<m;i++){
        tree[i].parent=0;
        tree[i].lchild=0;
        tree[i].rchild=0;
        tree[i].weight=0.0;
    }
    for(i=0;i<n;i++){
        scanf("%f",&f);
        tree[i].weight=f;
    }
    for(i=n;i<m;i++){
        p1=p2=0;
        small=small2=maxval;
        for(j=i-n;j<i-1;j++){
            if(tree[j].parent==0)
                if(tree[j].weight<small){
                    small2=small;
                    small=tree[j].weight;
                    p2=p1;p1=j;
                }else if(tree[j].weight<small2){
                    small2=tree[j].weight;p2=j;
                }
            tree[p1].parent=tree[p2].parent=i;
            tree[i].weight=tree[p1].weight+tree[p2].weight;
            tree[i].lchild=p1;
            tree[i].rchild=p2;
        }
    }
}

int main(){
    Huffman(tree);
    for(int i=0;i<m;i++){
        printf("%f,",tree[i].weight);
    }
    // int i,j,p1,p2;
    // float small,small2,f;
    // memset(a,-1,sizeof(a));
    // for(i=0;i<30;i++){
    //     printf("%d,",a[i]);
    // }
    return 0;
}