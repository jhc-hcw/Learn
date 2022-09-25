#include<map>
#include<iostream>
#include <utility>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int,int> m;
    for(auto i:nums){
        ++m[i];
    }
    vector<pair<int,int>> res;
    for_each(m.begin(),m.end(),[&](map<int,int>::const_iterator::value_type &it){
        res.push_back(make_pair(it.second,it.first));
    });
    vector<int> r;
    sort(res.begin(),res.end(),[&](pair<int,int> &p1,pair<int,int> &p2){
        if(p1.first>=p2.first){
            return true;
        }else{
            return false;
        }
    });
    for(int i=0;i<k;++i){
        r.push_back(res[i].first);
    }
    return r;
}

int main(){
    
    vector<pair<int,int>> v;
    for(int i=0;i<99;i++){
        v.push_back(make_pair(i,i));
    }
    for_each(v.begin(), v.end(), [](pair<int,int> &p){
        cout<<p.first<<" ";
    });
    cout<<endl;
    map<int,int> m;
    for(int i=0;i<99;i++){
        m[i];
    }
    for_each(m.begin(), m.end(), [](map<int,int>::const_iterator::value_type it){
        cout<<it.first<<" ";
    });
    return 0;
}