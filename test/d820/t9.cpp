#include <cstddef>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
vector<int> preorderTraversal(TreeNode* root) {
    stack<TreeNode *> s;
    // if(root){
    //     return {};
    // }
    s.push(root);
    auto p=root;
    vector<int> res;
    while(!s.empty()){
        p=s.top();
        if(p){
            res.push_back(p->val);
            s.pop();
            s.push(p->right);
            s.push(p->left);
        }else{
            s.pop();
        }
    }
}

vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode *> s;
    //s.push(root);
    auto p=root;
    vector<int> res;
    while(!s.empty() || p){
        if(p){
            s.push(p);
            p=p->left;
        }else{
            p=s.top();
            s.pop();
            res.push_back(p->val);
            p=p->right;
        }
    }
    return res;
}

vector<int> postorderTraversal(TreeNode* root) {
    if(!root){
        return {};
    }
    stack<TreeNode *> s;
    auto p=root;
    auto back=root;
    vector<int> res;
    s.push(p);
    while(!s.empty()){
        p=s.top();
        if(p->left && p->left != back && p->right != back){
            s.push(p->left);
        }else if(p->right && p->right !=back){
            s.push(p->right);
        }else{
            res.push_back(p->val);
            s.pop();
            back=p;
        }
    }
    return res;
}

// vector<int> postorderTraversal1(TreeNode* root) {
//     stack<TreeNode *> s;
//     auto p=root;
//     auto back=root;
//     vector<int> res;
//     s.push(p);
//     while(!s.empty()){
//         p=s.top();
//         if(p){
//             if(!back || p->right==back){
//                 res.push_back(p->val);
//                 back=p;
//                 s.pop();
//             }else{
//                 s.push(p->right);
//                 s.push(p->left);
//             }
//         }else{
//             back=p;
//             s.pop();
//         }
//     }
// }

vector<vector<int>> levelOrder(TreeNode* root) {
    queue<TreeNode *>  *q1=new queue<TreeNode *>();
    auto q2=new queue<TreeNode *>();
    if(!root){
        return {};
    }
    q1->push(root);
    auto p=root;
    vector<vector<int>> res;
    while(!q1->empty()){
        vector<int> temp;
        while(!q1->empty()){
            auto t=q1->front();
            temp.push_back(t->val);
            if(t->left){
                q2->push(t->left);
            }
            if(t->right){
                q2->push(t->right);
            }
            q1->pop();
        }
        res.push_back(temp);
        //using std::swap;
        swap(q1,q2);
    }
    return res;
}

 TreeNode* invertTree(TreeNode* root) {
    if(!root){
        return nullptr;
    }
    auto p=root->left;
    root->left=root->right;
    root->right=p;
    invertTree(root->left);
    invertTree(root->right);
    return root;
}