#include<iostream>
#include<string>
using namespace std;
bool repeatedSubstringPattern(string s) {
    const int len=s.length();
    if(len==1){
        return false;
    }else{
        if(len==0){
            return false;
        }else {
            int mid;
            if(len%2==0)
                mid=len/2;
            else
                mid=len/2-1;
            for (int i = 1; i <= mid; i++) {
                int j = i;
                for (; j < len; j++) {
                    if (s[j] != s[j -i]) {
                        break;
                    }
                }
                if (j == len) {
                    return true;
                }
            }
            if(len==3&& s[0]==s[1]&&s[1]==s[2]){
                return true;
            }
        }
    }
    return false;
    }

int main(){
    cout<<repeatedSubstringPattern("zzz");
    return 0;
}