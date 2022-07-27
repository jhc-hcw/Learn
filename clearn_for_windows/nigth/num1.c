#include<stdio.h>
#include<malloc.h>
#define MAX_VERTEX_NUM 100
typedef struct{    //顶点类型
    int num;
    char data;
}VERTEX;
typedef struct{   //邻接矩阵类型
    int n;
    int e;
    VERTEX vexs[MAX_VERTEX_NUM];
    int edges[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
}MGraph;
MGraph * create_MGraph(){  //图的构建
    int i,j,k,w,n,e;
    char c;
    MGraph *mg=malloc(sizeof(MGraph));
    printf("顶点数：");
    scanf("%d",&n);
    printf("边数：");
    scanf("%d",&e);
    mg->n=n;mg->e=e;
    fflush(stdin);
    printf("请输入顶点信息：");
    for(i=0;i<n;i++){
        scanf("%c ",&c);
        mg->vexs[i].data=c;
        mg->vexs[i].num=i;
    }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            mg->edges[i][j]=0;
    printf("输入边的信息：");
    fflush(stdin);
    for(i=0;i<e;i++){
        scanf("%d %d,",&j,&k);
        mg->edges[j][k]=1;
    }
    printf("邻接矩阵为：\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%d ",mg->edges[i][j]);
        }
        printf("\n");
    }
    return mg;
}

int visited[MAX_VERTEX_NUM];  //标记访问过结点的数组
int isallzero(MGraph *mg,int i){   //判断矩阵一列是否全为0
    int j;
    for(j=0;j<mg->n;j++){
        if(mg->edges[j][i]==1)
            return 0;
    }
    return 1;
}
void clear0(MGraph *mg,int k){    //将一行的元素全设置为0
    for(int i=0;i<mg->n;i++){
        mg->edges[k][i]=0;
    }
}
int ishavezero(MGraph *mg){      //寻找是否有未访问过的且全为0的列，有就返回列标，没有返回-1
    int i,j,n,k;
    for(i=0;i<mg->n;i++){
        if(visited[i]==0){
            if(isallzero(mg,i)){
                return i;
            }
        }
    }
    return -1;
}
void tuosort(MGraph *mg){     //进行拓扑排序
    int v=0,c;
    for(int i=0;i<mg->n;i++) visited[i]=0;
    printf("拓扑排序为：");
    while((c=ishavezero(mg))!=-1){
        clear0(mg,c);
        visited[c]=1;
        printf("%d ",c);
        v++;
    }
    if(v!=mg->n){      //如果排序完的个数不等于结点个数，就是有回路的图
        printf("存在回路");
    }else{
        printf("不存在回路！");
    }
}
int main(){
    MGraph *mg=create_MGraph();
    tuosort(mg);
    return 0;
}