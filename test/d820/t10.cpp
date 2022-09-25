
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
};


class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        auto l=root->left;
        auto r=root->right;
        trans(l);
        return equals(l, r);
    }
    void trans(TreeNode* root){
        if(!root){
        return ;
    }
    auto p=root->left;
    root->left=root->right;
    root->right=p;
    trans(root->left);
    trans(root->right);
    //return root;
    }
    bool equals(TreeNode * a,TreeNode* b){
        if( (!a && b)  ||  (a&& !b )){
            return false;
        }
        if(!a && !b){
            return true;
        }
        if( a->val != b->val ){
            return false;
        }
        bool aa=false;
        bool bb=false;
        if(a){
            aa=equals(a->left,b->left);
            bb=equals(a->right, b->right);
        }
        return aa&&bb;
    }
};
class Solution1 {
public:
    bool isSymmetric(TreeNode* root) {
        
        auto l=root->left;
        auto r=root->right;
        if(!l && !r){
            return true;
        }
        if( (!l && r)  ||  (l&& !r )){
            return false;
        }
        queue<TreeNode*> q1,q2;
        q1.push(l);
        q2.push(r);
        while(!q1.empty() && !q2.empty()){
            while(!q1.empty() && !q2.empty()){
                
            }
        }
    }
    bool queue_equal(queue<TreeNode*> &q1 ,queue<TreeNode*> &q2){
        const int len=q1.size();
        if(len!=q2.size()){
            return false;
        }
        for(int i=0;i<len;++i ){
            
            if(!equals(q1.front(), q2.front())){
                return false;
            }
            
        }

    }
    void trans(TreeNode* root){
        if(!root){
        return ;
    }
    auto p=root->left;
    root->left=root->right;
    root->right=p;
    trans(root->left);
    trans(root->right);
    //return root;
    }
    bool equals(TreeNode * a,TreeNode* b){
        if( (!a && b)  ||  (a&& !b )){
            return false;
        }
        if(!a && !b){
            return true;
        }
        if( a->val != b->val ){
            return false;
        }else{
            return false;
        }
    }
};
int maxDepth(TreeNode* root) {
    if(!root){
        return 0;
    }else{
        return max(maxDepth(root->left) ,maxDepth(root->right))+1;
    }
}

int minDepth(TreeNode* root) {
    if(!root){
        return 0;
    }
    queue<TreeNode*> *q1=new queue<TreeNode*> ();
    auto q2= new queue<TreeNode *>();
    q1->push(root);
    int count=0;
    while(!q1->empty()){
        ++count;
        int len=q1->size();
        for(int i=0;i<len;i++){
            auto p=q1->front();
            if(!p->left && !p->right){
                return count;
            }
            if(p->left)
                q1->push(p->left);
            if(p->right)
                q1->push(p->right);
            q1->pop();
        }
    }
    return count;
}
#include<map>

bool isBalanced(TreeNode* root) {
    if(!root){
        return true;
    }
    stack<TreeNode *> s;
    auto p=root;
    auto back=root;
    s.push(p);
    map<TreeNode*,int> m;
    m.emplace(root,1);
    auto f=root;
    while(!s.empty()){
        p=s.top();
        if(p->left && p->left != back && p->right != back){
            m.emplace(p->left,m.find(p)->second+1);
        }else if(p->right && p->right !=back){
            m.emplace(p->right,m.find(p)->second+1);
        }else{
            if(!p->left && !p->right){
                m.emplace(p,1);
            }else if(!p->left && p->right){
                auto val=m[p->right];
                if(val>=2){
                    return false;
                }
                m.emplace(p,val+1);
            }else if(!p->right && p->left){
                auto val=m[p->left];
                if(val>=2){
                    return false;
                }
                m.emplace(p,val+1);
            }else{
                auto ll=m[p->left];
                auto rr= m[p->right];
                if(ll-rr>=2 || ll-rr<=-2){
                    return false;
                }
                auto val=max(ll,rr)+1;
                m.emplace(p,val);
            }
            s.pop();
            back=p;
        }
    }
    // for(auto i: m){
    //     if(i.first->left && i.first->right){
    //         auto ex=m[i.first->left]-m[i.first->right];
    //         if(ex>=2 || ex<=-2){
    //             return false;
    //         }
    //         continue;
    //     }else if( !i.first->left &&  !i.first->right){
    //         continue;
    //     }else if(!i.first->left && i.first->right){
    //         auto ex=m[i.first->right];
    //         if(ex>=2){
    //             return false;
    //         }
    //         continue;
    //     }else{
    //         auto ex=m[i.first->left];
    //         if(ex>=2){
    //             return false;
    //         }
    //         continue;
    //     }
    // }
    return  true;
}

#include<array>
#include<list>
vector<string> binaryTreePaths(TreeNode* root) {
    vector<pair<TreeNode *,int>> v;
    vector<string> res;
    v.push_back(make_pair(root, 0));
    while(v.size()==0){
        auto p=v.back();
        if(p.second==0){
            if(p.first->left){
                p.second=true;
                v.push_back(make_pair(p.first->left, false));
                continue;
            }else{
                if(p.first->right){
                    p.second=3;
                    v.push_back(make_pair(p.first->right, 0));
                    continue;
                }else{
                    //print
                    string s;
                    for(auto i:v){
                       s.append(to_string(i.first->val));
                       if(i!=v.back())
                            s.append("->");
                    }
                    res.push_back(s);
                    v.resize(v.size()-1);
                    continue;
                }
            }
        }else{
            v.resize(v.size()-1);
            continue;
        }
    }
    return res;
}
std::string construct_res(vector<TreeNode*> &vec){
    string res;
    for(auto i:vec){
        res.append(to_string(i->val));
        res.append("->");
    }
    return res;
}
#include<array>
#include<list>
#include<set>
vector<string> binaryTreePaths1(TreeNode* root) {
    vector<string> res;
    vector<TreeNode*> sk;
    set<TreeNode *> setl,setr;
    setl.insert(root);
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
    return res;
}

int sum=0;
int sumOfLeftLeaves(TreeNode* root) {
    if(root){
        if(root->left){
            if(!root->left->left && !root->left->right)
                sum+=root->left->val;
        }
    }else{
        return 0;
    }
    sumOfLeftLeaves(root->right);
    sumOfLeftLeaves(root->left);
    return sum;

}

int findBottomLeftValue(TreeNode* root) {   //513题
    queue<TreeNode *>  *q1=new queue<TreeNode *>();
    auto q2=new queue<TreeNode *>();
    if(!root){
        return 0;
    }
    int res=root->val;
    q1->push(root);
    while(!q1->empty()){
        res=q1->front()->val;
        while(!q1->empty()){
            auto t=q1->front();
            if(t->left){
                q2->push(t->left);
            }
            if(t->right){
                q2->push(t->right);
            }
            q1->pop();
        }
        swap(q1,q2);
    }
    return res;
}
bool hasPathSum(TreeNode* root, int targetSum) { //112题
    if(!root){
        return false;
    }
    vector<string> res;
    vector<TreeNode*> sk;
    set<TreeNode *> setl,setr;
    sk.push_back(root);
    while(!sk.empty()){
        auto p=sk.back();
        if(setr.find(p)==setr.end()){
            if(setl.find(p)==setl.end()){
                if(!p->left && !p->right){
                    int sum=0;
                    for(auto i:sk){
                        sum+=i->val;
                    }
                    if(sum==targetSum){
                        return true;
                    }
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
    return false;
}
int find_v(vector<int> & v,int tar){
    for(int i=0;i<v.size();++i){
        if(v[i]==tar){
            return i;
        }
    }
    return 0;
}
#include<algorithm>
#include<array>
TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) { //106题
    stack<TreeNode*> s;
    const int len=inorder.size();
    vector<bool> isuse(len,false);
    auto find_index=[&](int v)->int{
        for(int i=0;i<len;i++){
            if(inorder[i]==v){
                return i;
            }
        }
        return -1;
    };
    auto root=new TreeNode(postorder.back());
    isuse[find_index(postorder.back())]=true;
    postorder.pop_back();
    s.push(root);
    //int rindex=find_index(postorder.back());
    while(!postorder.empty()){
        auto index=find_index(postorder.back()); //子
        auto rindex=find_index(s.top()->val);  //父
        if(rindex<index){
            s.top()->right=new TreeNode(inorder[index]);
            s.push(s.top()->right);
            isuse[index]=true;
            postorder.pop_back();
        }else{
            if(  isuse[rindex-1]==true){
                s.pop();
            }else{
                auto p=new TreeNode(inorder[index]);
                s.top()->left=p;
                s.pop();
                s.push(p);
                isuse[index]=true;
                postorder.pop_back();
            }
        }
        //rindex=index;
    }
    return root;
}