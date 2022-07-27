#include <iostream>
#include"template.h"
#include"Rational.h"
bool ishw(string s){
    if(s.length()<=1){
        return true;
    }
    if(s.length()%2==1){
        for(auto h=s.begin(),we=--s.end();h!=we;h++,we--){
            if(*h!=*we){
                return false;
            }
        }
    }else{
        auto h=s.begin(),we=--s.end();
        for(;h+1!=we;h++,we--){
            if(*h!=*we){
                return false;
            }
        }
        if(*h!=*we){
            return false;
        }
    }
    return true;
}
int cc =0;
#include<math.h>
class ma{
    int b;
    int c1;
public:
    ma(int c):b(c){
        c1=++cc;
        cout<<"我复活了"<<c1<<endl;
    };
    ~ma(){
        cout<<"我死了"<<c1<<endl;
    }
    void tostring(){
        cout<<"I am "<<c1<<"value is"<<b<<endl;

    }
    ma(ma const &m){
        b=m.b;
        c1=m.c1+1;
        cout<<"拷贝调用"<<c1<<endl;
        ++cc;
    }
};
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
        quick_sort(v,left,mid);
        quick_sort(v,mid,right);
    }
}

int main(){
    vector<int> v={1,2,1,3,3,4,1,6};
    quick_sort(v,0,v.size()-1);
    for (auto i:v){
        cout<<i<<" ";
    }
}
