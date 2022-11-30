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

vector<TreeNode *> * postorder(TreeNode *node,TreeNode* value){
    auto s=new vector<TreeNode *> ();
    auto p=node;
    auto back=node;
    s->push_back(p);
    while(!s->empty()){
        p=s->back();
        if(p->left && p->left !=back && p->right !=back){
            s->push_back(p->left);
        }else if(p->right && p->right !=back){
            s->push_back(p->right);
        }else{
            if(p==value){
                return s;
            }
            s->pop_back();
            back=p;
        }
    }
    return s;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    auto s1=postorder(root,p);
    auto s2=postorder(root, q);
    auto res=root;
    auto i2=s2->begin();
    for(auto i:*s1){
        if(i2==s2->end()||i!=*i2){
            return res;
        }else{
            res=i;
            i2++;
        }
    }
    return res;
}

vector<int> findMode(TreeNode* root){
    int count=0;
    vector<int> res;
    auto p=root;
    map<int ,int> set;
    stack<TreeNode *> s;
    s.push(root);
    while(!s.empty()){
        p=s.top();
        if(p){
            auto t=set[p->val]++;
            count=t>count? t:count;
            s.pop();
            s.push(p->right);
            s.push(p->left);
        }else{
            s.pop();
        }
    }
    for(auto i:set){
        if(i.second==count){
            res.push_back(i.first);
        }
    }
    return res;
}


int main(){
    map<int,int> m;
    auto res=m[1]++;
    res=m[1];
    cout<<res<<endl;
}