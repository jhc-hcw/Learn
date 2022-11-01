#include<stdio.h>
#include<string.h>


int parpe(){
    char *ss="abcefabababbcdjbcdefsdkfabkaabcdefjielsabkdjfababcdef";
    char *s="abcdef";
    int k=0,i=0,ll=strlen(ss),l=strlen(s),sum=0,j=0;
    int a[ll];
    while(k<ll){
        i=k;
        while(j<l&&i<ll){
            if(s[j]==ss[i]){
            sum++;
            }
            i++;j++;
        }
        a[k]=sum;
        k++;sum=0;j=0;
    }
    for(int t=0;t<ll;t++){
        if(a[t]>=l-1){
            printf("%d找到啦！\n",t);
        }
    }
    
    return 0;
}


int main(){
    parpe();
    return 1;
}
