
#include <cstddef>
#include <utility>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<map>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
pair<TreeNode*,TreeNode*> findnodef(TreeNode * root, int val){
    auto p=root;
    auto t=root;
    t=nullptr;
    while(p){
        if(p->val<val){
            t=p;
            p=p->right;
        }else if(p->val>val){
            t=p;
            p=p->left;
        }else{
            return pair<TreeNode*,TreeNode*> (t,p);
        }
    }
    return pair<TreeNode*,TreeNode*> (t,p);

}
pair<TreeNode*,TreeNode*> getRight(TreeNode *root){
    auto res=root;
    while(root->right){
        res=root;
        root=root->right;
    }
    if(root==res){
        return pair<TreeNode*,TreeNode*> (nullptr,root);
    }
    return pair<TreeNode*,TreeNode*> (res,root);
}
TreeNode* deleteNode(TreeNode* root, int val) {
    auto pai=findnodef(root, val);
    if(!pai.second){
        return root;
    }
    auto father=pai.first;
    auto node=pai.second;
    if(father){  //父节点不为空，删除点不是根结点。
        if(!node->left){ //如果左结点为空，找不到替换，直接右边接上去
            if(father->left==node){
                father->left=node->right;
            }else{
                father->right=node->right;
            }
        }else{
            auto left=node->left;
            auto right=getRight(left);
            if(!right.first){ //如果左边右边没有了，左边替上去，node右边接上去
                if(father->left==node){
                    father->left=left;
                    father->left->right=node->right;
                }else{
                    father->right=left;
                    father->right->right=node->right;
                }
            }else{ //正常替换，最复杂的那种
                node->val=right.second->val;
                right.first->right=right.second->left;
            }
        }
    }else{  //删除点是根结点。
        if(!node->left){
            return node->right;
        }else{
            auto left=node->left;
            auto right=getRight(left);
            if(!right.first){
                node->left->right=node->right;
                return node->left;
            }else{
                node->val=right.second->val;
                right.first->right=right.second->left;
            }
        }
    }
    return root;
    // if(!pai.second->left&& !pai.second->right){
    //     if(pai.first->left==pai.second){
    //         pai.first->left=nullptr;
    //         return root;
    //     }else{
    //         pai.first->right=nullptr;
    //         return root;
    //     }
    // }
    auto left=pai.second;
}
