#include<stdio.h>
#define LIST_SIZE 20

typedef struct{
    char r[LIST_SIZE];
    int length;
}RecordList;

RecordList *SqLset(){
    RecordList *L;
    int i=0;char c;
    L=malloc(sizeof(RecordList));
    scanf("%c",&c);
    L->length=0;
    while(c!='#'){
        L->r[i]=c;
        L->length++;
        i++;
        if(L->length==LIST_SIZE-1) break;
        scanf("%c",&c);
    }
    return L;

}

int SequenSearch(RecordList *L,char k,int n){
    int i=0,position =-1;
    L->r[n]=k;
    while(n!=i){
        if(L->r[i]==k){
            position =i+1;
            break;
        }
        i++;
    }
    return position;
}

int main(){
    RecordList *A;
    int m;
    char c;
    A=SqLset();
    fflush(stdin);
    scanf("%c",&c);
    m=SequenSearch(A,c,A->length);
    if(m==-1)
        printf("查找不成功！");
    else printf("m=%d,查找成功！",m);
    return 0;
}