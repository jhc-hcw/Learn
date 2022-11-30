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


void lrmorder(TreeNode *root){
    stack<TreeNode *> s;
    auto p=root;
    auto back=root;
    int sum=0;
    s.push(root);
    while(!s.empty()){
        p=s.top();
        if(p->right && p->right !=back && p->left !=back){
            s.push(p->right);
        }else if(p->left && p->left!=back){
            s.push(p->left);
        }else{
            sum+=p->val;
            p->val=sum;
            s.pop();
            back=p;
        }
    }
}
void inorderTraversal(TreeNode* root) {
    stack<TreeNode *> s;
    auto p=root;
    int sum=0;
    while(!s.empty() || p){
        if(p){
            s.push(p);
            p=p->right;
        }else{
            p=s.top();
            sum+=p->val;
            p->val=sum;
            s.pop();
            p=p->left;
        }
    }
}
TreeNode* convertBST(TreeNode* root) {

    stack<TreeNode *> s;
    auto p=root;
    int sum=0;
    while(!s.empty() || p){
        if(p){
            s.push(p);
            p=p->right;
        }else{
            p=s.top();
            sum+=p->val;
            p->val=sum;
            s.pop();
            p=p->left;
        }
    }
    return root;
}