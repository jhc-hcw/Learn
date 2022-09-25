//
// Created by jhc on 22-9-14.
//
#include<vector>
#include<iostream>
using namespace  std;
#include<array>
#include<list>
#include<set>

#include <cstddef>
#include <string>
#include <type_traits>
#include <utility>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode(){delete left;delete right;}
};
vector<string> binaryTreePaths1(TreeNode* root) {
    vector<string> res;
    vector<TreeNode*> sk;
    set<TreeNode *> setl,setr;
    //setl.insert(root);
    sk.push_back(root);
    while(!sk.empty()){
        auto p=sk.back();
        if(setr.find(p)==setr.end()){
            if(setl.find(p)==setl.end()){
                if(!p->left && !p->right){
                    string s;
                    auto e=sk.end()-1;
                    for(auto i=sk.begin();i!=e;++i){
                        s.append(to_string((*i)->val));
                        s.append("->");
                    }
                    s.append(to_string(p->val));
                    res.push_back(s);
                    sk.pop_back();
                    continue;
                }
                if(p->left){
                    setl.insert(p);
                    p=p->left;
                    sk.push_back(p);
                    continue;
                }
                setr.insert(p);
                p=p->right;
                sk.push_back(p);
            }else{
                if(p->right){
                    setr.insert(p);
                    p=p->right;
                    sk.push_back(p);
                    continue;
                }
                setr.insert(p);

            }
        }else{
            sk.pop_back();
        }
    }
    for(auto i:res){
        cout<<i<<endl;
    }
    return res;
}
int main(){
   TreeNode* root=new TreeNode(1);
   root->left=new TreeNode(2);
   root->right=new TreeNode(3);
    binaryTreePaths1(root);

   delete root;
}