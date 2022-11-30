#include <cstddef>
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
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if(!root){
        return new TreeNode(val);
    }
    auto p=root;
    auto t=root;
    while(p){
        if(p->val>val){
            t=p;
            p=p->left;
        }else{
            t=p;
            p=p->right;
        }
    }
    if(t->val>val){
        t->left=new TreeNode(val);
    }else{
        t->right=new TreeNode(val);
    }
}