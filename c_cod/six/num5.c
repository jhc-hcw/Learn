#include<stdio.h>
#include<malloc.h>

#define LIST_SIZE 20

typedef struct{
    int key;
    char *other_data[10];
}RecordType;
typedef struct{
    RecordType r[LIST_SIZE+1];
    int lengh;
}RecordList;

int SeqSerch(RecordList L,int k){
    L.r[L.lengh].key=k;
    int i=0;
    while(L.r[i].key!=k) ++i;
    if(i==L.lengh){
        return -1;
    }
    return i;
}

int main(){
    RecordType a1={1,"zjh"};
    RecordType a2={2,"lcl"};
    RecordType a3={3,"ljg"};
    RecordType a4={8,"dzl"};
    RecordType a5={33,"jhc"};
    RecordList a;
    a.r[0]=a1;
    a.r[1]=a2;
    a.r[2]=a3;
    a.r[3]=a4;
    a.r[4]=a5;
    a.lengh=5;
    int m=SeqSerch(a,33);  //查找关键字为33的数据i
    if(m==-1)
        printf("查找不成功！");
    else printf("m=%d,查找成功！",m);
    return 0;
}