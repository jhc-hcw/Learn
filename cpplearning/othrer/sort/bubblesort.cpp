#include<iostream>
using namespace std;
template<typename T>
void bubble_sort(T *v,int len){
    bool flag=false;
    for(int i=0;i<len-1;i++){
        flag=false;
        for(int j=0;j<(len-1-i);j++){
            flag=true;
            if(v[j]>v[j]){
                swap(v[j],v[i]);
            }
        }
//        if(!flag){
//            return ;
//        }
    }
}
int main(){
   int a[]={9,8,7,6,5,4,3,2,1};
    bubble_sort(a,9);
    cout<<a[0];
}
