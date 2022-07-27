#include<stdio.h>
#include<malloc.h>

#define maxlen 100

typedef int Datatype;
typedef struct{
    Datatype data[maxlen];
    int last;
}Sequenlist;

void SeqLsetnull(Sequenlist *L){
    L->last=-1;
}

Sequenlist *CreateSeqLset(){
    Sequenlist *L;
    L=malloc(sizeof(Sequenlist));
    L->last=-1;
    return L;
}

int Seqlength(Sequenlist * L){
    return L->last+1;
}

Datatype SeqLget(Sequenlist *L ,int i){
    Datatype result;
    if(i<1 || i>Seqlength(L))printf("超出范围\n");
    else result=L->data[i];
    return result;
}

void SeqLlocate(Sequenlist *L,Datatype x){
    int i,j=0;
    for(i=0;i<Seqlength(L);i++)
        if(L->data[i]==x){
            printf("%d  ",i+1);
            j=1;
        }
    if(j==0){
        printf("%d  ",-1);
    }
}

int SeqLempty(Sequenlist* L){
    if(L->last+1==maxlen)return 1;
    else return 0;
}

int SeqLinsert(Sequenlist *L,int i,Datatype x){
    int j;
    if(SeqLempty(L)==1){
        printf("overflow\n");
        return 0;
    }else if(i<1 || i>L->last +2){
        printf("error\n");
        return 0;
    }else{
        for(j=L->last;j>=i-1;j--)
            L->data[j+1]=L->data[j];
        L->data[i-1]=x;
        L->last=L->last+1;
        return 1;
    }
}

int Seqdelete(Sequenlist *L,int i){
    int j;
    if(L->last<0){
        printf("顺序表为空\n");
        return 0;
    }else if(i<1 || (i>L->last+1)){
        printf("i参数错误！\n");
    }else{
        for(j=i;j<=L->last+1;j++)
            L->data[j-1]=L->data[j];
        L->last--;
        return 1;
    }
}
void SeqPrint(Sequenlist *L){
    for(int i=0;i<L->last;i++)
        printf("%4d",L->data[i]);
    printf("\n");
}
void initseq(Sequenlist *L){
    int j;
    printf("请输入初始化个数：");
    scanf("%d",&j);
    for(int i=0;i<10;i++) //初始化五个
        scanf("%d",L->data+i);
    L->last=10;
}

int main(){
    Sequenlist *L;
    L=CreateSeqLset();
    initseq(L);
    SeqPrint(L);
    SeqLinsert(L,1,10);  //第一个位置插入10
    SeqPrint(L);
    Seqdelete(L,2); //删除第二个数
    SeqPrint(L);
    printf("数字5的位置为");
    SeqLlocate(L,5);  //查找5的位置
    return 0;
}