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
void insert(TreeNode *root,int val){
    auto p=root;
    while(root){
        if(root->val<val){
            p=root;
            root=root->right;
        }else{
            p=root;
            root=root->left;
        }
    }
    if(p->val>val){
        p->left=new TreeNode(val);
    }else{
        p->left=new TreeNode(val);
    }
}
void blance_insert(TreeNode *root,vector<int> &nums,int start,int end,bool left){
    int len=end-start;
    int mid=len/2+start;
    if(len>=2){
        if(left){
            root->left=new TreeNode(nums[mid]);
            blance_insert(root->left, nums, start, mid, true);
            blance_insert(root->left,nums, mid+1, end, false);
        }else{
            root->right=new TreeNode(nums[mid]);
            blance_insert(root->right, nums, start, mid, true);
            blance_insert(root->right,nums, mid+1, end, false);
        }
    }else if(len==1){
        if(left){
            root->left=new TreeNode(nums[start]);
        }else{
            root->right=new TreeNode(nums[mid]);
        }
    }

}
TreeNode* sortedArrayToBST(vector<int>& nums) {
    const int len=nums.size();
    if(len==0){
        return nullptr;
    }
    auto root=new TreeNode(nums[len/2]);
    blance_insert(root, nums, 0, len/2,true);
    blance_insert(root, nums, len/2+1, len, false);
    return root;


}