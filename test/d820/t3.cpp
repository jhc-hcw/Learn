#include<iostream>
#include<string>
using namespace std;

string reverseStr(string s, int k) {
        const int len=s.length();
        int sum=0;
        bool change=true;
        while(true){
            if(change){
                if((sum+=k)<=len){
                    for(int j=sum,k=sum+k-1;j<k;j++,k--){
                        swap(s[j],s[k]);
                    }
                    change=false;
                    if(sum==len){
                        break;
                    }
                }else if(sum<k){
                    for(int j=sum,k=len-1;j<k;j++,k--){
                        swap(s[j],s[k]);
                    }
                    break;
                }
            }else{
                if((sum+=k)<=len){
                    change=true;
                    if(sum==len){
                        break;
                    }
                }else{
                    break;
                }
            }
        }
        return "sdfsdfsf";
    }

int main(){
    string s="abcdefghijklmn";
    cout<<reverseStr(s,2);
    //cout<<"dkslfsdlkf"<<endl;
    return 9;
}