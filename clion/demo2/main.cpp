#include <iostream>
#include"create_tree.h"
#include"matrix.h"
using namespace std;
using namespace creat_tree;

//int main(){
//    //Bitree<char> bitree=creat_new_tree<char>();
//    //meanu();
//    //Bitree<char> bitree=stack_create_tree<char>();
//    //end_order(bitree);
//    //cout<<layer_order(bitree);
//    maxt();
//    return 0;
//}
//
//
//

//
//#define MAXSIZE 100  /*非零元素的个数最多为100*/
//#include <iostream>
//#include <stdlib.h>
//#include <malloc.h>
//using namespace std;
//typedef int ElementType;
//
//typedef struct
//{
//    int row, col;  /*该非零元素的行下标和列下标*/
//    ElementType e; /*该非零元素的值*/
//}Triple;
//
//typedef struct
//{
//    Triple data[MAXSIZE+1];   /* 非零元素的三元组表。data[0]未用*/
//    int m, n, len;            /*矩阵的行数、列数和非零元素的个数*/
//}TSMatrix;
//
//
//
//void FastTransposeTSMatrix(TSMatrix  A,  TSMatrix  & B)//快速转置
//{ /*基于矩阵的三元组表示，采用快速转置法，将矩阵A转置为B所指的矩阵*/
//    //请填充
//    B.len=A.len;
//    B.m=A.n;
//    B.n=A.m;
//    for(int i=1;i<=A.len;i++){
//        B.data[i].col=A.data[i].row;
//        B.data[i].row=A.data[i].col;
//        B.data[i].e=A.data[i].e;
//    }
//}
//
//
//
//
//void output(TSMatrix M)//输出三元组对应的原始矩阵
//{
//    int oldM[100][100];
//
//    for(int i=1;i<=M.m;i++)
//        for(int j=1;j<=M.n;j++)
//            oldM[i][j]=0;
//
//    for(int k=1;k<=M.len;k++)
//        oldM[M.data[k].row][M.data[k].col]=M.data[k].e;
//    for(int i=1;i<=M.m;i++)
//    {
//        for(int j=1;j<=M.n;j++)
//            cout<<oldM[i][j]<<" ";
//        cout<<endl;
//    }
//
//}
//
//int main()
//{
//    //声明一个稀疏矩阵
//    TSMatrix M;
//    int i=0,j=0;
//
//    //通过键盘输入构造一个稀疏矩阵
//    cout<<"请输入一个稀疏矩阵的三元组表示："<<endl;
//    cout<<"请输入矩阵的行数、列数和非零元素的个数：";
//    cin>>M.m>>M.n>>M.len;
//
//    for(i=1;i<=M.len;i++)
//    {
//        cout<<"请输入第"<<i<<"个非零元素的行号、列号和值：";
//        cin>>M.data[i].row>>M.data[i].col>>M.data[i].e;
//    }
//
//    //验证构造出的稀疏矩阵是否正确，输出原矩阵
//    cout<<"构造好的矩阵如下："<<endl;
//    output(M);
//
//    //稀疏矩阵的转置
//    TSMatrix MM;//转置后的矩阵
//    FastTransposeTSMatrix(M,MM);//快速转置算法
//    cout<<"转置后的稀疏矩阵的三元组表示为："<<endl;
//
//    for(i=1;i<=MM.len;i++)
//    {
//        cout<<MM.data[i].row<<" "<<MM.data[i].col<<" "<<MM.data[i].e<<endl;
//    }
//
//    //验证转置后的稀疏矩阵是否正确
//    cout<<"转置后的矩阵如下："<<endl;
//
//    output(MM);
//
//}


// NO81.cpp : Defines the entry point for the console application.
//



#include<stdio.h>
/*swap()函数的作用是将a[i]和a[j]互换*/
void swap(int a[], int i, int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void sift ( int r[ ], int k, int m )
{//要筛选结点的编号为k，堆中最后一个结点的编号为m
    int i,j;
    i=k;  j=2*i;  ;  //将筛选记录暂存
    while (j<=m )           //筛选还没有进行到叶子
    {
        if (j<m && r[j]<r[j+1]) j++;  //左右孩子中取较大者
        if (r[i]>r[j]) break;
        else {
            swap(r,i,j);  i=j;   j=2*i;
        }
    }
       //将筛选记录移到正确位置
}
void  HeapSort ( int  r[], int n)
{
    for (int i=n/2; i>=1; i--)      //初建堆
        sift(r, i, n) ;

    printf("第1次建堆后的结果是: ");
    for(int i=1;i<=n;i++) printf("%d ",r[i]);
    printf("\n\n");
    int c=2;

    for (int i=1; i<n; i++ )
    {
        swap(r,1,n-i+1);           //移走堆顶
        sift(r, 1, n-i);               //重建堆
        printf("第%d次建堆后的结果是: ",c++);
        for(int j=1;j<=n-i;j++)printf("%d ",r[j]);
        printf("\n\n");
    }
}

//int main()
//{
//    int i;
//    int a[10]={0, 13,38,27,49,76,65,49,97}; //保证结点编号从1开始
//    printf("排序前：");
//    for(i=1;i<=8;i++)
//    {
//        printf("%d ",a[i]);
//    }
//    printf("\n\n");
//    HeapSort(a, 8);
//    printf("排序后：");
//    for(i=1;i<=8;i++)
//    {
//        printf("%d ",a[i]);
//    }
//    printf("\n\n");
//    return 0;
//}

int main(){
    Bitree<char> t= creat_new_tree<char>();
    cout<<"深度是"<<dfs_h(t);
}