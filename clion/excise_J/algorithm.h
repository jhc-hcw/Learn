//
// Created by jhc on 2022/5/22.
//

#ifndef EXCISE_J_ALGORITHM_H
#define EXCISE_J_ALGORITHM_H
#include<iostream>
#include<set>
#include<unordered_set>
#include<unordered_map>
using namespace std;
class Solution {
public:
    bool trydigui(unordered_set<int> &map,int total,int max){
        for(auto it=map.begin();it!=map.end();it++ ){
            if(total+*it>=max){
                return true;
            }
            unordered_set<int> copy=map;
            copy.erase(*it);
            if(!trydigui(copy,total+*it,max)){
                return true;
            }
        }
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        unordered_set<int> a;
        for(int i=1;i<=maxChoosableInteger;i++){
            a.insert(i);
        }
        return trydigui(a,0,desiredTotal);
    }
};














#endif //EXCISE_J_ALGORITHM_H
