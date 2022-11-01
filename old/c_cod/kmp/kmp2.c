#include<stdio.h>
#include<string.h>
#include<malloc.h>


int strl(char *s){
    int len=0;
    while(s[len]!='\0') len++;
    return len;
}

char* streverse(char *s){
    int l=strl(s),i=0,k=l-1;
    char *res=malloc(sizeof(char)*(l+1));
    while(i<l){
        res[i]=s[k];
        i++;
        k--;
    }
    res[l]='\0';
    return res;
}

char* substr(char *s,int a,int b){
    int l=b-a+2,i=0,j=a;
    char *res=malloc(sizeof(char)*(l+1));
    res[l]='\0';
    for(i=0;j<=b;i++,j++)
        res[i]=s[j];
    return res;
}

char *streplace(char *s,char a,char b){
    int l=strl(s);
    char *res=malloc(sizeof(char)*(l+1));
    res[l]='\0';
    for(int i=0;i<l;i++){
        if(s[i]==a)
            res[i]=b;
        else
            res[i]=s[i];
    }
    return res;
}

char *RNAtransform(char *s){
    int l=strl(s);
    char *res=malloc(sizeof(char)*(l+1));
    res[l]='\0';
    for(int i=0;i<l;i++){
        if(s[i]=='A'){
            res[i]='U';
            continue;
        }
        else if(s[i]=='U'){
            res[i]='A';
            continue;
        }
        else if(s[i]=='C'){
            res[i]='G';
            continue;
        }
        else if(s[i]=='G'){
            res[i]='C';
        }
    }
    return res;
}

void cc(){
    char *ss="ababcabadkeiblazpbaab";
    char *s="ab";
    int ll=strl(ss),l=strl(s),j=0,k=-1,i=0;
    int res[ll];
    res[0]=-1;
    while(j<ll){
        while(k<l){
            if(s[k]==ss[i]){
            k++;i++;
            }else{
                k++;
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
}