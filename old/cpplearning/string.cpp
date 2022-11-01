#include<iostream>
#include<stack>
using namespace std;

template<typename T>
class stack{
    struct node{
        T data;
        struct node *next;
    };
    struct node* D;
    public:
    stack(){
        D=NULL;
    }
    bool isEmpty(){
        if(this->D==NULL){
            return true;
        }else{
            return false;
        }
    }
    T get_top(){
        if(!this->isEmpty()){
            return D->data;
        }else{
            return NULL;
        }
    }
    void push(T x){
        node *p=(node *)malloc(sizeof(node));
        p->data=x;
        p->next=D;
        D=p;
    }
    void pop(){
        if(!this->isEmpty()){
            node* p=D;
            D=D->next;
            delete(p);
        }else{
            return ;
        }
    }

};

typedef struct BitNode{
    int data;
    int bf;
    struct BitNode *lchild,*rchild;
}BitNode,*BiTree;
BiTree L_blance(BiTree *p);
BiTree R_blance(BiTree *p);
void Compute_cod(BiTree p);
BiTree R_blance(BiTree *p){
    if((*p)->lchild!=NULL && (*p)->lchild->bf<0){
        (*p)->lchild=L_blance(&(*p)->lchild);
    }
    BiTree L;
    L=(*p)->lchild;
    (*p)->lchild=L->rchild;
    L->rchild=(*p);
    (*p)=L;
    Compute_cod((*p)->rchild);
    Compute_cod(*p);
    return *p;
}
BiTree L_blance(BiTree *p){
    if((*p)->rchild !=NULL && (*p)->rchild->bf>0){
        (*p)->rchild=R_blance(&(*p)->rchild);
    }
    BiTree R;
    R=(*p)->rchild;
    (*p)->rchild=R->lchild;
    R->lchild=*p;
    (*p)=R;
    Compute_cod((*p)->lchild);
    Compute_cod(*p);
    return *p;
}

BiTree Blance_t(BiTree *p){
    if((*p)->bf>1){
        return R_blance(p);
    }else if((*p)->bf<-1){
        return L_blance(p);
    }
    return *p;
}
void Compute_cod(BiTree p){
    int l=0,r=0;
    if(p->lchild==NULL && p->rchild==NULL){
        p->bf=0;
    }else if(p->lchild==NULL && p->rchild!=NULL){
        r=p->rchild->bf;
        p->bf=(0-(r>=0? r+1 : 1-r));
    }
    else if(p->rchild==NULL && p->lchild!=NULL){
        l=p->lchild->bf;
        p->bf=((l>=0? l+1: 1-l)-0);
    }else{
        l=p->lchild->bf;
        r=p->rchild->bf;
        if(l==0 && r==0){
            return ;
        }
        p->bf=(l>=0? l:-l)-(r>=0? r:-r);
    }
}
BiTree createnode(int x){
    BiTree p=(BiTree)malloc(sizeof(BitNode));
    p->bf=0;
    p->data=x;
    p->lchild=NULL;
    p->rchild=NULL;
    return p;
}
BiTree insert(BiTree *p,int x){
     if((*p)==NULL){
        (*p)=createnode(x);
        return *p;
    }
    ::stack<BiTree *> stack;
    BiTree *t=p;
    while((*t)!=NULL){
        stack.push(t);
        if((*t)->data<x){
            t=&((*t)->rchild);
        }else if((*t)->data>x){
            t=&((*t)->lchild);
        }else{
            return *p;
        }
    }
    t=stack.get_top();
    stack.pop();
    if((*t)->data>x){
        BiTree u=createnode(x);
        (*t)->lchild=u;
        (*t)->bf++;
    }else{
        BiTree u=createnode(x);
        (*t)->rchild=u;
        (*t)->bf--;
    }
    while(!stack.isEmpty()){
        BiTree *q=stack.get_top();
        // cout<<(*q)->data<<endl;
        stack.pop();
        Compute_cod(*q);
        Blance_t(q);
    }
    return *p;
}
int main(){
    BiTree tree=NULL;
    insert(&tree,3);
    insert(&tree,2);
    insert(&tree,1);
    insert(&tree,4);
    insert(&tree,5);
    insert(&tree,6);
    // insert(&tree,7);
    // insert(&tree,10);
    // insert(&tree,9);
    // insert(&tree,8);
    cout<<tree->data<<endl;
    cout<<tree->bf<<endl;
    cout<<tree->lchild->data<<endl;
    cout<<tree->lchild->bf<<endl;
    // if(tree==NULL){
    //     cout<<"wofalsdkfj"<<endl;
    // }
    return 0;
}