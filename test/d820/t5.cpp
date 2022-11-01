#include<vector>
#include<iostream>
#include<string>
using namespace std;
vector<int> sortedSquares(vector<int>& nums) {
    const int len=nums.size();
    vector<int> res(len);
    int i,j;
    int q=0;
    for( i=0;i<len;i++){
        if(nums[i]<=0){
            ++q;
        }else{
            break;
        }
    }
    vector<int> q1(q);
    vector<int> q2(len-q);
    for(i=q-1,j=0;i>=0;--i,++j){
        q1[j]=nums[i]*nums[i];
    }
    for(i=q,j=0;i<len;++i,++j){
        q2[j]=nums[i]*nums[i];
    }
    q=0;
    for(i=0,j=0;i<q1.size()&&j<q2.size();){
        if(q1[i]>q2[j]){
            nums[q++]=q2[j++];
        }else{
            nums[q++]=q1[i++];
        }
    }
    while(i<q1.size()) nums[q++]=q1[i++];
    while(j<q2.size()) nums[q++]=q2[j++];
    return nums;
}

int main(){
    vector<int> v={-4,-1,0,3,10};
    sortedSquares(v);
    for(auto i:v){
        cout<<i<<" ";
    }
    string s="abc";
    //s.replace(" ","%20");
    s.insert(0,1,'S');
    return 9;
}