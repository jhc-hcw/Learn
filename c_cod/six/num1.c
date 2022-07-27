#include<stdio.h>
#include<malloc.h>
#define LIST_SIZE 20

typedef struct{
    int key;
    char *other_data[10];
}RecordType;
typedef struct{
    RecordType r[LIST_SIZE+1];
    int lenght;
}RecordList;


int SeqSerch(RecordList L,int k){
    L.r[0].key=k;
    int i=L.lenght;
    while(L.r[i].key!=k) --i;
    return i;
}

int main(){
    RecordType a1={33,"jhc"};
    RecordType a2={1,"zjh"};
    RecordType a3={2,"lcl"};
    RecordType a4={3,"ljg"};
    RecordType a5={8,"dzl"};
    RecordList a;
    a.r[1]=a1;
    a.r[2]=a2;
    a.r[3]=a3;
    a.r[4]=a4;
    a.r[5]=a5;
    a.lenght=5;
    printf("位置在%d",SeqSerch(a,33));  //查找关键字为33的数据
    return 0;
}