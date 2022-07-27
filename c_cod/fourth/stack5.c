#include<string.h>
#include<stdio.h>
#include<malloc.h>

typedef struct node{
    char data;
    struct node* next;
}charstack;

charstack* pop(charstack *cs){
    charstack* t=cs->next;
    free(cs);
    return t;
}

char getTop(charstack *cs){
    return cs->data;
}

charstack* push(charstack *cs,char x){
    charstack* t=malloc(sizeof(charstack));
    t->data=x;
    t->next=cs;
    return t;
}
charstack* csinit(){
    charstack* t=malloc(sizeof(charstack));
    
}

int ismach(char *s){
    charstack* cs=NULL;
    int l=strlen(s),res=1;
    for(int i=0;i<l;i++){
        if(s[i]=='(' || s[i]==')'){
            if(s[i]=='('){
                cs=push(cs,s[i]);
            }else{
                if(cs==NULL){
                    res=0;
                    break;
                }else{
                    cs=pop(cs);
                }
            }
        }
    }
    if(cs!=NULL){
        res=0;
    }
    return res;
}

int main(){
    char *s[50];
    printf("请输入多项式");
    gets(s);
    if(ismach(s)==1){
        printf("是匹配的捏");
    }
    else{
        printf("不是匹配的捏");
    }
    return 1;
}