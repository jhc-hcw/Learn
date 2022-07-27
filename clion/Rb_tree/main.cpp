#include <iostream>
#include"rb_tree.h"
int main() {
    jhc_rb_tree::RB_T<int> t(1);
//    for(int i=2;i<=6;i++){
//        t.insert(i);
//    }
    t.insert(8);
    t.insert(6);
    t.insert(4);
    t.insert(9);
    t.insert(55);
    t.insert(80);
    t.insert(443);
    t.insert(21);
    t.insert(56);
    t.insert(300);
    t.insert(7);
    t.insert(3306);
    t.insert(1086);
    t.insert(64);
    t.insert(86);
    t.insert(10);
    t.insert(244);
    layer_order(t.root);
    //cout<<t.root->lchild->rb_t;
    return 0;
}
