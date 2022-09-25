#include<iostream>
#include<string>
using namespace std;

string reverseWords(string s){
    s.push_back(' ');
    int r=s.length()-1;
    int h=r-1;
    string res;
    while(h>=0){
        if(s[h]!=' '){
            --h;
        }else{
            for(int i=h+1;i<r;i++){
                res.push_back(s[i]);
            }
            if(h+1!=r)
               res.push_back(' ');
            r=h;
            --h;
        }
    }
    for(int i=h+1;i<r;i++){
        res.push_back(s[i]);
    }
    if(*res.rend()==' '){
        res.resize(res.length()-1);
    }
    return res;
}
int main(){
    string s="  hello world ";
    string res=reverseWords(s);
    cout<<"|"<<res<<"|"<<endl;
    return 0;
}