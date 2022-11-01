#include<iostream>
using namespace std;
template<typename T>
struct tree_node{
    T data;
    struct node *lchild,*rchild;
};
template<typename T> using Bitree = tree_node<T>*;


int main(){
    cout<<sizeof(tree_node<int>);
    return 0;
}