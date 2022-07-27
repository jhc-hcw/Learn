#include<iostream>
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


BiTree* L_blance(BiTree *p);
BiTree* R_blance(BiTree *p);
BiTree* avlBlance(BiTree *p);
int compute_h(BiTree p);


BiTree* R_blance(BiTree *p){
    if(compute_h((*p)->lchild) < 0 ){
        L_blance(&(*p)->lchild);
    }
    BiTree L;
    L=(*p)->lchild;
    (*p)->lchild=L->rchild;
    L->rchild=(*p);
    (*p)=L;
    compute_h((*p)->rchild);
    compute_h(*p);
    return p;
}
BiTree* L_blance(BiTree *p){
    if(compute_h((*p)->rchild) > 0){
        R_blance(&(*p)->rchild);
    }
    BiTree R;
    R=(*p)->rchild;
    (*p)->rchild=R->lchild;
    R->lchild=(*p);
    (*p)=R;
    compute_h((*p)->lchild);
    compute_h(*p);
    return p;
}

BiTree* avlBlance(BiTree *p){
    int flag=compute_h(*p);
    if(flag<=1 && flag >=-1){
        return p;
    }else if(flag>1){
        return R_blance(p);
    }else if(flag<-1){
        return L_blance(p);
    }
    return NULL;
}

int compute_h(BiTree p){
    if(p==NULL){
        return 0;
    }else if(p->rchild==NULL && p->lchild==NULL){
        p->bf=1;
        return 0;
    }else if(p->rchild==NULL){
        p->bf=p->lchild->bf+1;
        return p->lchild->bf;
    }else if(p->lchild==NULL){
        p->bf=p->rchild->bf+1;
        return -(p->rchild->bf);
    }else{
        p->bf= (p->lchild->bf >= p->rchild->bf ) ? p->lchild->bf+1 : p->rchild->bf+1;
        return p->lchild->bf - p->rchild->bf;
    }
    return 0;
}

BiTree createN(int x){
    BiTree t=new BitNode();
    t->bf=1;
    t->data=x;
    t->lchild=NULL;
    t->rchild=NULL;
    return t;
}

void insertAvl(BiTree *p,int x){
    if((*p)==NULL){
        (*p)=createN(x);
        return ;
    }
    BiTree *t=p;
    stack<BiTree *> s;
    while((*t)!=NULL){
        if(x==(*t)->data){
            return ;
        }
        if(x>=(*t)->data){
            s.push(t);
            t=&((*t)->rchild);
        }else{
            s.push(t);
            t=&((*t)->lchild);
        }
    }
    t=s.get_top();
    if((*t)->data<=x){
        (*t)->rchild=createN(x);
    }else{
        (*t)->lchild=createN(x);
    }
    while(!s.isEmpty()){
        t=s.get_top();
        avlBlance(t);
        s.pop();
    }
}

void avl_delete(BiTree *p,int x){
    if((*p)==NULL){
        cout<<"空空如也怎么删"<<endl;
        return ;
    }
    BiTree *t;
    t=p;
    stack<BiTree *> s;
    while((*t)!=NULL){
        if(x>(*t)->data){
            s.push(t);
            t=&((*t)->rchild);
        }else if(x<(*t)->data){
            s.push(t);
            t=&((*t)->lchild);
        }else{
            s.push(t);
            break;
        }
    }
    t=s.get_top();
    if(x!=(*t)->data){
        cout<<"没找到"<<endl;
        return ;
    }else{
        BiTree *l=&((*t)->lchild);
        if((*l)==NULL){   //如果左子树为空
            BiTree temp=(*t);
            (*t)=(*t)->rchild;
            delete(temp);
            while(!s.isEmpty()){
                compute_h(*s.get_top());
                avlBlance(s.get_top());
                s.pop();
            }
            return ;
        }else{
            if((*l)->rchild==NULL){   //如果左子树的右为空
                BiTree temp=(*t);
                (*l)->rchild=temp->rchild;
                (*t)=(*l);
                delete(temp);    
                while(!s.isEmpty()){
                    compute_h(*s.get_top());
                    avlBlance(s.get_top());
                    s.pop();
                }
                return ;
            }else{     //如果左子树的右不为空
                cout<<"wojijrul"<<endl;

                s.push(l);
                BiTree *r=&((*l)->rchild);
                while((*r)!=NULL){
                    s.push(r);
                    r=&((*r)->rchild);
                }
                r=s.get_top();
                BiTree lr=(*r);
                cout<<lr->data<<endl;
                s.pop();
                (*s.get_top())->rchild=lr->lchild;
                // if((*r)==NULL){
                //     cout<<"caol"<<endl;
                //     return ;
                // }
                lr->lchild=(*t)->lchild;
                lr->rchild=(*t)->rchild;
                BiTree temp=(*t);
                (*t)=lr;
                delete(temp);
                while(!s.isEmpty()){
                    compute_h(*s.get_top());
                    avlBlance(s.get_top());
                    s.pop();
                }
                return ;
            }
        }
    }
}
int main(){
    BiTree tree=NULL;
    insertAvl(&tree,1);
    insertAvl(&tree,2);
    insertAvl(&tree,3);
    insertAvl(&tree,4);
    insertAvl(&tree,5);
    insertAvl(&tree,6);
    insertAvl(&tree,7);
    insertAvl(&tree,8);
    insertAvl(&tree,9);
    insertAvl(&tree,10);
    insertAvl(&tree,11);
    insertAvl(&tree,12);
    avl_delete(&tree,12);
    cout<<tree->data<<endl;
    cout<<tree->bf<<endl;
    return 0;
}