#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int a;
        vector<int> t;
        for(int i=0;i<nums.size();i++){
            t.clear();
            if(nums[i]<=target){
                a=target-nums[i];
                t.push_back(i);
            }else{
                break;
            }
            for(int j=i;j<nums.size();j++){
                if(nums[j]==a){
                    t.push_back(j);
                    break;
                }
            }
        }
        return t;
    }
};
int main(){
    return 0;
}