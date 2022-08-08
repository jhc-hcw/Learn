#include<iostream>
#include<vector>
using namespace std;
int partition(vector<int> &v,int left,int right){
    int x=v[left];
    while(left<right){
        while(v[right]>x){
            --right;
        }
        if(left<right){
            v[left]=v[right];
            ++left;
            
        }
        while(v[left]<x){
            ++left;
        }
        if(left<right){
            v[right]=v[left];
            --right;
        }  
    }
    v[left]=x;
    return left;
}

void quick_sort(vector<int> &v,int left,int right){
    int mid;
    if(left<right){
        mid=partition(v,left,right);
        quick_sort(v,left,mid-1);
        quick_sort(v,mid+1,right);
    }
}

int main(){
    vector<int> v={1,2,1,3,3,4,1,6};
    quick_sort(v,0,v.size()-1);
    for (auto i:v){
        cout<<i<<" ";
    }
    return 0;
}
