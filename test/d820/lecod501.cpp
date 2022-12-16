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
            auto t=++set[p->val];
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