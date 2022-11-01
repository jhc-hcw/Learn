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
float tree2[m];
Huffman(hufmtree tree[]){
    int i,j,p1,p2;
    float small,small2,f,temp;
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
        for(i=n;i<m;i++){
            p1,p2;

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