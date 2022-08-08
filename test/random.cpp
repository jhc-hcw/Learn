#include<random>
#include<iostream>
#include<algorithm>
#include<chrono>
using namespace std;
int main(){
    std::default_random_engine dre;
    std::uniform_int_distribution<int> di(10,20);
    for(int i=0;i<20;++i){
        std::cout<<di(dre)<<" ";
    }
    std::cout<<endl;

    uniform_real_distribution<double> dr(10,20);
    for(int i=0;i<8;++i){
        cout<<di(dre)<<" ";
    }
    cout<<endl;
    vector<int> v={1,2,3,4,5,6,7,8,9,10};
    shuffle(v.begin(),v.end(),dre);
    for(auto i:v){
        cout<<i<<" ";
    }
    cout<<endl;
}