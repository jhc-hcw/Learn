//
// Created by jhc on 2022/5/4.
//

#ifndef DEMO2_CREATE_TREE_H
#define DEMO2_CREATE_TREE_H

#endif //DEMO2_CREATE_TREE_H
//
// Created by jhc on 2022/5/4.
//
namespace creat_tree {
#include"my_util.h"

    using namespace jhc_util;

    template<typename T>
    struct tree_node {
        T data;
        struct tree_node *lchild, *rchild;

        tree_node(T x=0) : data(x), lchild(0), rchild(0) {

        }

        ~tree_node() {
            delete (lchild);
            delete (rchild);
        }
    };

    template<typename T> using Bitree = tree_node<T> *;

    template<typename T>
    Bitree<T> creat_new_tree(){
        queue<Bitree<T>> q;
        char data;
        int count=0;
        Bitree<T> tree=0,temp_tree=0;
        cout<<"请逐层输入结点,空:'@',结束：'#'：";
        cin>>data;
        while(data!='#'){
            if('@'!=data){
                temp_tree=new tree_node<T>(data);
            }else{
                temp_tree= 0;
            }
            //++ ;
            q.add(temp_tree);
            if(count==1){
                tree=temp_tree;
            }else{
                if(temp_tree && q.get_head()){
                    if(count%2==0){
                        q.get_head()->lchild=temp_tree;
                    }else{
                        q.get_head()->rchild=temp_tree;
                    }
                }
                if(count%2==1){
                    q.del();
                }
            }
            cin>>data;
        }
        return tree;
    }

    template<typename T>
    void pre_ord(Bitree<T> x){
        if(x){
            cout<<x->data;
            pre_ord(x->lchild);
            pre_ord(x->rchild);
        }
    }



    template<typename T> void iput_r(Bitree<T>);
    template<typename  T>
    void iput_l(Bitree<T> p){
        T data;
        if(p){
            cin>>data;
            if(data!='#'){
                Bitree<T> t=new tree_node<T>(data);
                p->lchild=t;
                iput_l(t);
                iput_r(p);
            }else{
                iput_r(p);
            }
        }
    }
    template<typename  T>
    void iput_r(Bitree<T> p){
        T data;
        if(p){
            cin>>data;
            if(data!='#'){
                Bitree<T> t=new tree_node<T>(data);
                p->rchild=t;
                iput_l(t);
            }
        }
    }
    template<typename T>
    Bitree<T> stack_create_tree(){
        Bitree<T> temp_t=0,root=0;
        T data;
        cout<<"输入：";
        cin>>data;
        root=new tree_node<T>(data);
        iput_l(root);
        return root;
    }

    template<typename T>
    Bitree<T> c_T(Bitree<T> t=0){
        T data;
        cin>data;
        if(!t){
            if(data!='#')
                t=new tree_node<T>(data);
            return t;
        }
        if(data!='#'){
            Bitree<T> t=new tree_node<T>(data);
            t->lchild=data;
            c_T(t);
            c_T(t->rchild);
        }else{
            c_T(t->rchild);
        }
        return t;
    }

    template<typename T>
    void mid_order(Bitree<T> root){
        jhc_util::stack<Bitree<T>> s;
        Bitree<T> p=root;
        while(p || !s.isEmpty()){
            if(p){
                s.push(p);
                p=p->lchild;
            }else{
                p=s.get_top();
                s.pop();
                cout<<p->data;
                p=p->rchild;
            }
        }
    }
    template<typename T>
    void pre_order(Bitree<T> root){
        jhc_util::stack<Bitree<T>> s;
        Bitree<T> p=root;
        while(p||!s.isEmpty()){
            if(p){
                s.push(p);
                cout<<p->data;
                p=p->lchild;
            }else{
                p=s.get_top();
                s.pop();
                p=p->rchild;
            }
        }
    }
    template<typename T>
    void end_order(Bitree<T> root){
        jhc_util::stack<Bitree<T>> s;
        Bitree<T> head=root,temp=0;
        if(head){
            s.push(root);
            while(!s.isEmpty()){
                temp=s.get_top();
                if(temp->lchild && head!=temp->lchild && head!=temp->rchild){
                    s.push(temp->lchild);
                }else if (temp->rchild && head!=temp->rchild){
                    s.push(temp->rchild);
                }else{
                    cout<<temp->data;
                    s.pop();
                    head=temp;
                }
            }
        }
    }
    template<typename T>
    int layer_order(Bitree<T> root){
        jhc_util::stack<Bitree<T>> *s1,*s2;
        s1=new jhc_util::stack<Bitree<T>>();
        s2=new jhc_util::stack<Bitree<T>>();
        Bitree<T> p=root;
        s1->push(p);
        int count=0;
        while(!s1->isEmpty()) {
            while (!s1->isEmpty()) {
                if (s1->get_top()->lchild) {
                    s2->push(s1->get_top()->lchild);
                }
                if (s1->get_top()->rchild) {
                    s2->push(s1->get_top()->rchild);
                }
                s1->pop();
            }
            jhc_util::stack<Bitree<T>> *t=s1;
            s1=s2;
            s2=t;
            count++;
        }
        return count;
    }
    template<typename T>
    void fouth_m(Bitree<T> root){
        jhc_util::stack<Bitree<T>> s;
        Bitree<T> p=root;
        while(p||!s.isEmpty()){
            if(p){
                s.push(p);
                if(!p->rchild && !p->lchild){
                    cout<<p->data;
                }
                p=p->lchild;
            }else{
                p=s.get_top();
                s.pop();
                p=p->rchild;
            }
        }
    }
    template<typename T>
    int fifth_m(Bitree<T> root){
        jhc_util::stack<Bitree<T>> s;
        Bitree<T> p=root;
        int count=0;
        while(p||!s.isEmpty()){
            if(p){
                s.push(p);
                if(!p->rchild && !p->lchild){
                    count++;
                }
                p=p->lchild;
            }else{
                p=s.get_top();
                s.pop();
                p=p->rchild;
            }
        }
        return count;
    }
    template<typename T>
    void sixth_m(Bitree<T> root){
        jhc_util::stack<Bitree<T>> s;
        Bitree<T> head=root,temp;
        if(head){
            s.push(root);
            while(!s.isEmpty()){
                temp=s.get_top();
                if(temp->lchild && head!=temp->lchild && head!=temp->rchild){
                    s.push(temp->lchild);
                }else if (temp->rchild && head!=temp->rchild){
                    s.push(temp->rchild);
                }else{
                    if(temp->lchild && temp->rchild){
                        cout<<temp->data;
                    }
                    s.pop();
                    head=temp;
                }
            }
        }
    }
    template<typename T>
    int dfs_h(Bitree<T> t){
        if(!t){
            return 0;
        }
        int l= dfs_h(t->lchild);
        int r= dfs_h(t->rchild);
        return l>r? l+1 : r+1;
    }

    void meanu(){
        Bitree<char> bitree=stack_create_tree<char>();
        cout<<""<<endl;
        cout<<"----------------二叉树------------"<<endl;
        cout<<"                菜单                       "<<endl;
        cout<<""<<endl;
        cout<<"1.先序遍历         2.中序遍历"<<endl;
        cout<<"3.后序遍历         4.先序输出叶子"<<endl;
        cout<<"5.叶子个数         6后序二度结点"<<endl;
        cout<<"7.输出深度         8.退出"<<endl;
        cout<<"----------------------------------"<<endl;
        int choose=0;
        while(1){
            cout<<"输入选择：";
            cin>>choose;
            switch(choose){
                case 1:
                    pre_ord(bitree);cout<<endl;break;
                case 2:
                    mid_order(bitree);cout<<endl;break;
                case 3:
                    end_order(bitree);cout<<endl;break;
                case 4:
                    fouth_m(bitree);cout<<endl;break;
                case 5:
                    cout<<fifth_m(bitree)<<endl;break;
                case 6:
                    sixth_m(bitree);cout<<endl;break;
                case 7:
                    cout<<layer_order(bitree)<<endl;break;
                case 8:
                    return ;
                default:continue;
            }
        }
    }

}


