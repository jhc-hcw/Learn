#include<stdio.h>
#include<string.h>


int parpe(){
    char *ss="abbcdjsdkfkajielkdjfab";
    char *s="ab";
    int k=0,i=0,ll=strlen(ss),l=strlen(s);
    int a[ll];
    while(i<ll){
        while(k<l){
            if(s[k]==ss[i]){
            k++;i++;
            }else{
                break;
            }
        }
        if(k==l){
            printf("找到了在%d",i-k+1);
            return 1;
        }else{
            i=i-k+1;
            k=0;
        }
    }
    printf("没找到");
    return 0;
}


int main(){
    parpe();
    return 1;
}
