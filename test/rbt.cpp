#include<iostream>
using namespace std;

template <typename T>
struct tree;
template<typename T>
using tree_ptr=tree<T> *;
template<typename T>
struct rb_tree_t;
template<typename T>
using rb_tree_ptr=rb_tree_t<T> *;

/*
template<typename T>
struct tree{
    using type=T;
    T data;
    tree_ptr<T> father,lchild,rchild;
    tree(T tree_data={},tree_ptr<T> father_v=nullptr,tree_ptr<T> lchild_v=nullptr,tree_ptr<T> rchlid_v=nullptr ):data(tree_data),
    father(father_v),lchild(lchild_v),rchild(rchlid_v){};
    ~tree(){
        delete lchild;
        delete rchild;
    }
    //执行这个方法，删除树不会递归删除它的子树；
    void clear_t();
};
template <typename T>
void tree<T>::clear_t(){
    lchild=nullptr;
    rchild=nullptr;
}
*/    //废弃，发现用继承体系父子节点获取红黑属性要转型，太蠢了
enum class rb_tree_color{
    red=true,black=false
};
template <typename T>
struct rb_tree_t{
    T data;
    rb_tree_ptr<T> father,lchild,rchild;
    rb_tree_color tree_type;
    rb_tree_t(T tree_data={},rb_tree_ptr<T> father_v=nullptr,rb_tree_ptr<T> lchild_v=nullptr,rb_tree_ptr<T> rchlid_v=nullptr,rb_tree_color t=rb_tree_color::red):
    data(tree_data),father(father_v),lchild(lchild_v),rchild(rchlid_v) ,tree_type(t){};
    ~rb_tree_t(){
        delete lchild;
        delete rchild;
    }
    //执行这个方法，删除树不会递归删除它的子树；
    void clear_t();
};

template <typename T>
void rb_tree_t<T>::clear_t(){
    lchild=nullptr;
    rchild=nullptr;
}
template<typename T>
rb_tree_ptr<T> r_rotate(rb_tree_ptr<T> tree){
    auto l=tree->lchild;
    if(tree && l){
        if(tree->father){
            if(tree->lchild==tree){
                tree->father->lchild=l;
            }else{
                tree->father->rchild=l;
            }
        }
        l->father=tree->father;
        tree->father=l;
        tree->lchild=l->rchild;
        if(l->rchild){
            l->rchild->father=tree;
        }        
    }else{
        return nullptr;
    }
    return l;
}
template<typename T>
rb_tree_ptr<T> l_rotate(rb_tree_ptr<T> tree){
    auto r=tree->rchild;
    if(tree && r){
        if(tree->father){
            if(tree->lchild==tree){
                tree->father->lchild=r;
            }else{
                tree->father->rchild=r;
            }
        }
        r->father=tree->father;
        tree->father=r;
        tree->rchild=r->lchild;
        if(r->lchild){
            r->lchild->father=tree;
        }
    }else{
        return nullptr;
    }
    return r;
}
int main(){
    rb_tree_t<int> tt(33);
    rb_tree_t<int> ttt(44,&tt);
    cout<<static_cast<rb_tree_ptr<int>>(ttt.father)->data;
    if(static_cast<rb_tree_ptr<int>>(ttt.father)->tree_type==rb_tree_color::red){
        cout<<"yes"<<endl;
    }
    return 9;
}