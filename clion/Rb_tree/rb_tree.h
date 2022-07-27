//
// Created by jhc on 2022/5/6.
//

#ifndef RB_TREE_RB_TREE_H
#define RB_TREE_RB_TREE_H

#endif //RB_TREE_RB_TREE_H
#include<iostream>
#include"myutil.h"
using namespace std;

namespace jhc_rb_tree {
    enum rb_type {
        red,
        black
    };
    enum class rb_tree_t {
        is_dou_nod,
        is_tri_nod,
        is_tri_and_l_no,
        is_tri_and_r_no,
        is_for_nod,
        is_dou_and_no_son,
        red,
        non,
        left,
        right,
        null,
        is_tri_and_l_red,
        is_tri_and_r_red,
        is_dou_and_l_no,
        is_dou_and_r_no,
    };
    template<typename T>
    struct rb_tree;
    template<typename T> using rb_t_p = rb_tree<T> *;

    template<typename T>
    struct rb_tree {
        T data;
        rb_type rb_t;
        rb_t_p<T> lchild, rchild, fathre;

        explicit rb_tree(rb_t_p<T> f = 0, rb_type typ = red, T data = 0) : fathre(f), data(data), rb_t(typ), lchild(0),
                                                                           rchild(0) {
        }

        ~rb_tree() {
            delete (lchild);
            delete (rchild);
        }

    };

    template<typename T>
    rb_tree_t getType(rb_t_p<T> t) {
        if (t && t->rb_t == black) {
            if (t->rchild && t->lchild && t->rchild->rb_t == black && t->lchild->rb_t == black) {
                return rb_tree_t::is_dou_nod;
            } else if (t->rchild && t->lchild && t->rchild->rb_t == red && t->lchild->rb_t == red) {
                return rb_tree_t::is_for_nod;
            } else if (t->rchild && t->lchild && t->lchild->rb_t == red && t->rchild->rb_t == black) {
                return rb_tree_t::is_tri_and_l_red;
            } else if(t->rchild && t->lchild && t->rchild->rb_t == red && t->lchild->rb_t == black){
                return rb_tree_t::is_tri_and_r_red;
            }else if (!t->rchild && t->lchild && t->lchild->rb_t == red) {
                return rb_tree_t::is_tri_and_r_no;
            } else if (t->rchild && !t->lchild && t->rchild->rb_t == red) {
                return rb_tree_t::is_tri_and_l_no;
            } else if (!t->lchild && !t->rchild) {
                return rb_tree_t::is_dou_and_no_son;
            }else if( t->lchild &&t->lchild->rb_t==black && !t->rchild){
                return rb_tree_t::is_dou_and_r_no;
            }else if( t->rchild && t->rchild->rb_t==black && !t->lchild);
        } else if (t && t->rb_t == red) {
            return rb_tree_t::red;
        } else {
            return rb_tree_t::non;
        }
        return rb_tree_t::non;
    }

    template<typename T>
    class RB_T {
    public:
        rb_t_p<T> root = 0;


        RB_T(T data) {
            root = new rb_tree<T>(0, black, data);
        }

        RB_T() {

        }

        RB_T(rb_t_p<T> (tree)) : root(tree) {

        }

        void insert(T data);

        rb_t_p<T> find_f(T data);

        rb_t_p<T> find(T data);

        rb_t_p<T> find_instead(rb_t_p<T> t);

        void remove(rb_t_p<T> t);

        void del(rb_t_p<T> t);

        void black_balance(rb_t_p<T> t,rb_tree_t type);

        //void T_balance_i(rb_t_p<T> f,T data);
        void t_balance_insert(rb_t_p<T> tree);

        rb_t_p<T> r_rotate(rb_t_p<T> t);

        rb_t_p<T> l_rotate(rb_t_p<T> t);


    };

    template<typename T>
    rb_t_p<T> RB_T<T>::r_rotate(rb_t_p<T> t) {
        if (!t || !t->lchild) {
            cout << "error 1" << endl;
            return NULL;
        }
        rb_t_p<T> l = t->lchild;
        t->lchild = l->rchild;
        if (l->rchild) {
            l->rchild->fathre = t;
        }
        l->fathre = t->fathre;
        if (t->fathre) {
            if (t->fathre->lchild == t) {
                t->fathre->lchild = l;
            } else {
                t->fathre->rchild = l;
            }
        }else{
            root=l;
        }
        l->rchild = t;
        t->fathre = l;
        return l;
    }

    template<typename T>
    rb_t_p<T> RB_T<T>::l_rotate(rb_t_p<T> t) {
        if (!t || !t->rchild) {
            cout << "error 2" << endl;
            return NULL;
        }
        const rb_t_p<T> r = t->rchild;

        t->rchild = r->lchild;
        if (r->lchild) {
            r->lchild->fathre = t;
        }

        r->fathre = t->fathre;
        if (t->fathre) {
            if (t->fathre->lchild == t) {
                t->fathre->lchild = r;
            } else {
                t->fathre->rchild = r;
            }
        }else{
            root=r;
        }
        r->lchild = t;
        t->fathre = r;
        return r;
    }

    template<typename T>
    rb_t_p<T> RB_T<T>::find_f(T data) {
        rb_t_p<T> p = root;
        while (p) {
            if (p->data == data) {
                return p->fathre;
            } else if (p->data > data && !p->lchild) {
                return p;
            } else if (p->data < data && !p->rchild) {
                return p;
            } else if (p->data > data) {
                p = p->lchild;
            } else if (p->data < data) {
                p = p->rchild;
            }
        }
        return p;
    }

    template<typename T>
    rb_t_p<T> RB_T<T>::find(T data) {
        rb_t_p<T> p = find_f(data);
        if (p) {
            if (p->rchild->data == data) {
                return p->rchild;
            } else {
                return p->lchild;
            }
        } else {
            return root;
        }
    }

    template<typename T>
    void RB_T<T>::insert(T data) {
        if (!root) {
            root = new rb_tree<T>(0, black, data);
            return;
        } else {
            rb_t_p<T> p = find_f(data);
            if (p && p->rb_t == black) {
                if (p->data > data && !p->lchild) {
                    p->lchild = new rb_tree<T>(p, red, data);
                } else if (p->data < data && !p->rchild) {
                    p->rchild = new rb_tree<T>(p, red, data);
                }
            } else if (p && p->rb_t == red) {
                //T_balance_i(p,data);
                if (p->data > data && !p->lchild) {
                    p->lchild = new rb_tree<T>(p, red, data);
                    t_balance_insert(p->lchild);
                } else if (p->data < data && !p->rchild) {
                    p->rchild = new rb_tree<T>(p, red, data);
                    t_balance_insert(p->rchild);
                }
            } else {
                cout << "error-1" << endl;
            }
        }
    }

    template<typename T>
    void RB_T<T>::t_balance_insert(rb_t_p<T> tree) {
        rb_t_p<T> f = tree->fathre, ff = f->fathre;
        if (f->rb_t == black) {
            //cout << "error father is black" << endl;
            return;
        }
        rb_tree_t rbt = getType(ff);
        if (rbt == rb_tree_t::is_tri_and_l_no) {
            if(ff->rchild==f && f->rchild!=tree){
                r_rotate(f);
            }
            ff = l_rotate(ff);
            ff->lchild->rb_t = red;
            ff->rchild->rb_t = red;
            ff->rb_t = black;
            return;
        } else if (rbt == rb_tree_t::is_tri_and_r_no) {
            if(ff->lchild==f && f->lchild!=tree){
                l_rotate(f);
            }
            ff = r_rotate(ff);
            ff->lchild->rb_t = red;
            ff->rchild->rb_t = red;
            ff->rb_t = black;
            return;
        }
        if (rbt == rb_tree_t::is_for_nod) {
            ff->rb_t = ff == root ? black : red;
            ff->lchild->rb_t = black;
            ff->rchild->rb_t = black;
            if (ff != root) {
                ff->rb_t = red;
                t_balance_insert(ff);
            }
            return;
        }
        if (rbt == rb_tree_t::is_tri_and_l_red) {
            ff = r_rotate(ff);
            ff->lchild->rb_t = red;
            ff->rchild->rb_t = red;
            ff->rb_t = black;
        }else {
            ff = l_rotate(ff);
            ff->lchild->rb_t = red;
            ff->rchild->rb_t = red;
            ff->rb_t = black;
        }
    }

    template<typename T>
    int layer_order(rb_t_p<T> root) {
        jhc_util::stack<rb_t_p<T>> *s1, *s2;
        jhc_util::queue<rb_t_p<T>> *q1,*q2;
        s1 = new jhc_util::stack<rb_t_p<T>>();
        s2 = new jhc_util::stack<rb_t_p<T>>();
        rb_t_p<T> p = root;
        s1->push(p);
        int count = 0;
        cout<<s1->get_top()->data<<endl;
        while (!s1->isEmpty()) {
            while (!s1->isEmpty()) {
                if (s1->get_top()->lchild) {
                    rb_t_p<T> tp=s1->get_top()->lchild;
                    s2->push(tp);
                    cout << tp->data;
                    if(tp->rb_t==red){
                        cout<<"r ";
                    }else{
                        cout<<"b ";
                    }
                }
                if (s1->get_top()->rchild) {
                    rb_t_p<T> tp=s1->get_top()->rchild;
                    s2->push(tp);
                    cout << tp->data;
                    if(tp->rb_t==red){
                        cout<<"r ";
                    }else{
                        cout<<"b ";
                    }
                }
                s1->pop();
            }
            cout << endl;
            jhc_util::stack<rb_t_p<T>> *t = s1;
            s1 = s2;
            s2 = t;
            count++;
        }
        return count;
    }
    template<typename T>
    rb_t_p<T> RB_T<T>::find_instead(rb_t_p<T> t){
        rb_t_p<T> p=t;
        if(t->lchild){
            p=p->lchild;
            while(p->rchild){
                p=p->rchild;
            }
            return p;
        }else if(t->rchild){
            p=t->rchild;
            while(p->lchild){
                p=p->lchild;
            }
            return p;
        }
        return p;
    }

    template<typename T>
    void RB_T<T>::remove(rb_t_p<T> t) {
        if(t){
            cout<<"del error"<<endl;
            return ;
        }
        rb_t_p<T> deled= find_instead(t);
        t->data=deled->data;
        del(deled);
    }

    template<typename T>
    void RB_T<T>::del(rb_t_p<T> t) {
        if(t->rb_t==red){
            auto f=t->fathre;
            if(f->lchild==t){
                f->lchild=0;
                delete(t);
                return ;
            }else{
                f->rchild=0;
                delete(t);
                return ;
            }
        }
        if(t==root){
            deletl(root);
            root=0;
            return;
        }
        if(t->rb_t==black){
            rb_tree_t type= getType(t);
            if(type==rb_tree_t::is_tri_and_l_no){
                t->data=t->rchild->data;
                delete(t->rchild);
                t->rchild=0;
                return ;
            }else if(type==rb_tree_t::is_tri_and_r_no){
                t->data=t->lchild->data;
                delete(t->lchild);
                t->lchild=0;
                return ;
            }else if(type==rb_tree_t::is_dou_and_no_son){
                auto f=t->fathre;
                if(f->lchild==t){
                    f->lchild=0;
                    delete(t);
                    black_balance(f,rb_tree_t::right); //右边多黑
                }else{
                    f->rchild=0;
                    delete(t);
                    black_balance(f, rb_tree_t::left); //左边多黑
                }
                return ;
            }
        }

    }

    template<typename T>
    void RB_T<T>::black_balance(rb_t_p<T> t,rb_tree_t type) {
        auto tt= getType(t);
        if(type==rb_tree_t::left){  //专注右旋！！
            if(tt==rb_tree_t::red){  //如果是红色节点右边多黑。
                auto lc=t->lchild;
                auto lct= getType(lc);
                if(lct==rb_tree_t::is_tri_and_r_no){
                    r_rotate(t);
                    return;
                }else if(lct==rb_tree_t::is_tri_and_l_no){
                    auto p=l_rotate(lc);
                    p= r_rotate(t);
                    p->rb_t=black;
                    p->lchild->rb_t=red;
                    return;
                }else if(lct==rb_tree_t::is_tri_and_l_red){
                    r_rotate(t);
                    return;
                }else if(lct==rb_tree_t::is_tri_and_r_red){
                    t->rb_t=black;
                    r_rotate(t);
                    return;
                }else if(lct==rb_tree_t::is_dou_and_no_son){
                    lc->rb_t=black;
                    t->rb_t=black;
                    return;
                }else if(lct==rb_tree_t::is_dou_nod){
                    lc->rb_t=red;
                    if(t->fathre->lchild==t){
                        black_balance(t->fathre,rb_tree_t::right);
                    }else{
                        black_balance(t->fathre,rb_tree_t::left);
                    }
                    return;
                }
            }else{  //如果是黑色节点右边多黑
                auto lc=t->lchild;
                auto lct= getType(lc);
                auto lrc=lc->rchild;
                auto lrct= getType(lrc);
                if(tt==rb_tree_t::is_dou_and_r_no){  //如果为二节点就是三黑删除一个的情况。
                    if(lct==rb_tree_t::is_for_nod || lct==rb_tree_t::is_tri_and_r_no){
                        auto p= r_rotate(t);
                        p->lchild->rb_t=black;
                        return ;
                    }else if(lct==rb_tree_t::is_tri_and_l_no){
                        l_rotate(lc);
                        auto p= r_rotate(t);
                        p->lchild->rb_t=black;
                        return ;
                    }
                }else if(tt==rb_tree_t::is_tri_and_r_no){   //底层，右空情况。确定右边只有一个黑色。
                    if(lrct==rb_tree_t::is_dou_and_no_son){
                        lrc->rb_t=red;
                        r_rotate(t);
                        return;
                    }else if(lrct==rb_tree_t::is_for_nod){
                        lrc->rb_t=red;
                        lrc->lchild->rb_t=black;
                        auto p= r_rotate(t);
                        return;
                    }else if(lrct== rb_tree_t::is_tri_and_r_no){
                        t->rb_t=red;
                        auto p =r_rotate(t);
                        r_rotate(p->lchild);
                        return;
                    }else if(lrct==rb_tree_t::is_tri_and_l_no){
                        lrc->rb_t=red;
                        lrc->rchild->rb_t=black;
                        l_rotate(lrc);
                        r_rotate(t);
                        t->rb_t=red;
                        return;
                    }
               }else if(tt==rb_tree_t::is_dou_nod){
                    if(lct==rb_tree_t::is_dou_nod){
                        lc->rb_t=red;
                        if(t->fathre->lchild==t){
                            black_balance(t->fathre,rb_tree_t::right);
                        }else{
                            black_balance(t->fathre,rb_tree_t::left);
                        }
                        return;
                    }else if(lct==rb_tree_t::is_for_nod){
                        auto p=r_rotate(t);
                        p->lchild->rb_t=red;
                        return;
                    }else if(lct==rb_tree_t::is_tri_and_l_red){
                        auto p= r_rotate(t);
                        p->lchild=red;
                        return;
                    }else if(lct==rb_tree_t::is_tri_and_r_red){
                        lc->rb_t=red;
                        lc->rchild->rb_t=black;
                        auto p= l_rotate(lc);
                        p= r_rotate(t);
                        p->lchild=red;
                        return;
                    }
                }
            }
        }else{  //上面对称

            if(tt==rb_tree_t::red){  //如果是红色节点右边多黑。
                auto rc=t->lchild;
                auto rct= getType(rc);
                if(rct==rb_tree_t::is_tri_and_l_no){
                    l_rotate(t);
                    return;
                }else if(rct==rb_tree_t::is_tri_and_r_no){
                    auto p=r_rotate(rc);
                    p= l_rotate(t);
                    p->rb_t=black;
                    p->lchild->rb_t=red;
                    return;
                }else if(rct==rb_tree_t::is_tri_and_r_red){
                    l_rotate(t);
                    return;
                }else if(lct==rb_tree_t::is_tri_and_r_red){
                    t->rb_t=black;
                    r_rotate(t);
                    return;
                }else if(lct==rb_tree_t::is_dou_and_no_son){
                    lc->rb_t=black;
                    t->rb_t=black;
                    return;
                }else if(lct==rb_tree_t::is_dou_nod){
                    lc->rb_t=red;
                    if(t->fathre->lchild==t){
                        black_balance(t->fathre,rb_tree_t::right);
                    }else{
                        black_balance(t->fathre,rb_tree_t::left);
                    }
                    return;
                }
            }else{  //如果是黑色节点右边多黑
                auto lc=t->lchild;
                auto lct= getType(lc);
                auto lrc=lc->rchild;
                auto lrct= getType(lrc);
                if(tt==rb_tree_t::is_dou_and_r_no){  //如果为二节点就是三黑删除一个的情况。
                    if(lct==rb_tree_t::is_for_nod || lct==rb_tree_t::is_tri_and_r_no){
                        auto p= r_rotate(t);
                        p->lchild->rb_t=black;
                        return ;
                    }else if(lct==rb_tree_t::is_tri_and_l_no){
                        l_rotate(lc);
                        auto p= r_rotate(t);
                        p->lchild->rb_t=black;
                        return ;
                    }
                }else if(tt==rb_tree_t::is_tri_and_r_no){   //底层，右空情况。确定右边只有一个黑色。
                    if(lrct==rb_tree_t::is_dou_and_no_son){
                        lrc->rb_t=red;
                        r_rotate(t);
                        return;
                    }else if(lrct==rb_tree_t::is_for_nod){
                        lrc->rb_t=red;
                        lrc->lchild->rb_t=black;
                        auto p= r_rotate(t);
                        return;
                    }else if(lrct== rb_tree_t::is_tri_and_r_no){
                        t->rb_t=red;
                        auto p =r_rotate(t);
                        r_rotate(p->lchild);
                        return;
                    }else if(lrct==rb_tree_t::is_tri_and_l_no){
                        lrc->rb_t=red;
                        lrc->rchild->rb_t=black;
                        l_rotate(lrc);
                        r_rotate(t);
                        t->rb_t=red;
                        return;
                    }
                }else if(tt==rb_tree_t::is_dou_nod){
                    if(lct==rb_tree_t::is_dou_nod){
                        lc->rb_t=red;
                        if(t->fathre->lchild==t){
                            black_balance(t->fathre,rb_tree_t::right);
                        }else{
                            black_balance(t->fathre,rb_tree_t::left);
                        }
                        return;
                    }else if(lct==rb_tree_t::is_for_nod){
                        auto p=r_rotate(t);
                        p->lchild->rb_t=red;
                        return;
                    }else if(lct==rb_tree_t::is_tri_and_l_red){
                        auto p= r_rotate(t);
                        p->lchild=red;
                        return;
                    }else if(lct==rb_tree_t::is_tri_and_r_red){
                        lc->rb_t=red;
                        lc->rchild->rb_t=black;
                        auto p= l_rotate(lc);
                        p= r_rotate(t);
                        p->lchild=red;
                        return;
                    }
                }
            }








            if(tt==rb_tree_t::red){    //可以变色解决
                auto rc=t->rchild;
                auto rct= getType(rc);
                if(rct==rb_tree_t::is_tri_and_r_no){

                }else if(rct==rb_tree_t::is_tri_and_l_no){

                }else if(rct==rb_tree_t::is_tri_and_l_red){

                }else if(rct==rb_tree_t::is_tri_and_r_red){

                }else if(rct==rb_tree_t::is_tri_nod){

                }else if(rct==rb_tree_t::is_dou_and_no_son){

                }else if(rct==rb_tree_t::is_dou_nod){

                }
            }else{

            }
        }
//        if(t->rb_t==red){
//            if(type==rb_tree_t::right){
//                auto rrc=t->rchild->rchild;
//                auto rrct= getType(rrc);
//                auto rct= getType(t->rchild);
//                if(t->rchild && rct==rb_tree_t::is_dou_and_no_son){  //如果删除节点父节点为红色，其另一子结点为二结点光棍。
//                    t->rchild->rb_t=red;
//                    t->rb_t=black;
//                    return ;
//                }else if(t->rchild && rct==rb_tree_t::is_for_nod || t->rchild && rct==rb_tree_t::is_tri_and_l_no){  //如果删除节点父节点为红色，其另一子节点为四节点或可旋转的三节点。 旋转变色。
//                    t=r_rotate(t);
//                    t->rb_t=red;
//                    t->lchild->rb_t=black;
//                    t->rchild->rb_t=black;
//                    return;
//                }else if(t->rchild && rct==rb_tree_t::is_tri_and_l_no){   //无法直接旋转，先变成可旋转。
//                    l_rotate(t->rchild);
//                    t= r_rotate(t);
//                    t->rb_t=red;
//                    t->lchild->rb_t=black;
//                    t->rchild->rb_t=black;
//                    return ;
//                }else if(t->rchild && rct==rb_tree_t::is_dou_nod){  //是二节点非光棍。变色并向上求平衡
//                    t->rchild->rb_t=red;
//                    t->rb_t= black;
//                    if(t->fathre->lchild==t){
//                        black_balance(t->fathre,rb_tree_t::right);
//                    }else{
//                        black_balance(t->fathre,rb_tree_t::left);
//                    }
//                    return ;
//                }//else if(t->rchild && getType(t->lchild))
//            }else if(type==rb_tree_t::red){  //上面对称处理。
//                auto lct= getType(t->lchild);
//                if(t->lchild && lct==rb_tree_t::is_dou_and_no_son){
//                    t->lchild->rb_t=red;
//                    t->rb_t= black;
//                    return ;
//                }else if(t->lchild && lct==rb_tree_t::is_for_nod || t->lchild && lct==rb_tree_t::is_tri_and_r_no){
//                    t= l_rotate(t);
//                    t->rb_t=red;
//                    t->lchild->rb_t=black;
//                    t->rchild->rb_t=black;
//                    return ;
//                }else if(t->lchild && lct==rb_tree_t::is_tri_and_r_no){
//                    r_rotate(t->lchild);
//                    t= l_rotate(t);
//                    t->rb_t=red;
//                    t->lchild->rb_t=black;
//                    t->rchild->rb_t=black;
//                    return ;
//                }else if(t->lchild && lct==rb_tree_t::is_dou_nod){
//                    t->lchild->rb_t= black;
//                    t->rb_t=black;
//                    if(t->fathre->lchild==t){
//                        black_balance(t->fathre,rb_tree_t::right);
//                    }else{
//                        black_balance(t->fathre,rb_tree_t::left);
//                    }
//                    return ;
//                }
//            }
//        }else{
//            if(type==rb_tree_t::right){ // 如果右边黑色多
//                auto rc=t->rchild;
//                auto rct= getType(rc);
//                if(rct==rb_tree_t::is_dou_and_no_son){    //如果黑色父节点，其另一个子节点为黑色二节点。变色，向上求黑平衡
//                    rc->rb_t=red;
//                    if(t->fathre->lchild==t){
//                        black_balance(t->fathre,rb_tree_t::right);
//                    }else{
//                        black_balance(t->fathre,rb_tree_t::left);
//                    }
//                    return ;
//                }else if(rct ==rb_tree_t::is_for_nod || rct==rb_tree_t::is_tri_and_r_no){  //如果黑色父节点，另一个子节点为四节点，旋转。
//                    t= r_rotate(t);
//                    t->lchild->rb_t= black;
//                    return;
//                }else if(rct==rb_tree_t::is_tri_and_l_no){
//                    rc->lchild->rb_t=black;
//                    l_rotate(t->lchild);
//                    t= r_rotate(t);
//                    return ;
//                }else if(rct==rb_tree_t::red){  //如果红色父子节点，下面两个黑色节点
//                    auto rlc=rc->lchild;
//                    if(rlc && getType(rlc)==rb_tree_t::is_for_nod || rlc && getType(rlc)==rb_tree_t::is_tri_and_r_no ){
//                        t=r_rotate(t);
//                        r_rotate(t->rchild);
//                        t->rb_t=black;
//                        t->rchild->rb_t=red;
//                        return ;
//                    }else if(rlc && getType(rlc)==rb_tree_t::is_tri_and_l_no){
//                        l_rotate(rlc);
//                        t= r_rotate(t);
//                        r_rotate(t->rchild);
//                        t->rb_t=black;
//                        return ;
//                    }
//                }
//            }else{  //对称操作
//                auto lc=t->lchild;
//                auto lct= getType(lc);
//                if(lct==rb_tree_t::is_dou_nod || lct==rb_tree_t::is_dou_and_no_son){
//                    lc->rb_t=red;
//                    if(t->fathre->lchild==t){
//                        black_balance(t->fathre,rb_tree_t::right);
//                    }else{
//                        black_balance(t->fathre,rb_tree_t::left);
//                    }
//                }
//            }
//        }
    }
}
