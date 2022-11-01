#include<stdio.h>
#include<malloc.h>
#define MAX_VERTEX_NUM 100

typedef struct node1{
    int adjvex;
    struct node1 *nextarc;
    char info;
}ARCNODE;
typedef struct{
    char vexdata;
    ARCNODE *firstarc;
}VEXNODE,AdjList[MAX_VERTEX_NUM];
typedef struct{
    AdjList vextices;
    int vexnum,arcnum;
}ALGraph;
typedef struct {
    int num;
    char data;
}VERTEX;
typedef struct{
    int n,e;
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

ALGraph cc(MGraph mg){
    int i,j;
    ARCNODE *p; 
    ALGraph al;  //邻接表
    al.vexnum=mg.n;    //将邻接矩阵的结点个数与边的个数复制。
    al.arcnum=mg.e;
    for(i=0;i<mg.n;i++){   //遍历邻接矩阵，将边的信息捞出来，赋值到邻接表。
        al.vextices[i].vexdata=mg.vexs->data;  //过程中同时初始化邻接表。
        al.vextices[i].firstarc=NULL;
        for(j=0;j<mg.n;j++){
            if(mg.edges[i][j]!=0){    //如果邻接矩阵的两点间有边，就加入到邻接表中
                ARCNODE *arc=malloc(sizeof(ARCNODE));  //添加一个边结点
                arc->adjvex=j;
                arc->nextarc=NULL;
                p=al.vextices[i].firstarc;
                if(p==NULL){       //将新加的边添加到邻接表中。
                    al.vextices[i].firstarc=arc;
                }else{
                    while(p->nextarc!=NULL ){
                        p=p->nextarc;
                    }
                    p->nextarc=arc;
                }
            }
        }
    }
    printf("邻接表为：\n");
    for(int i=0;i<al.vexnum;i++){  //输出邻接表
        p=al.vextices[i].firstarc;
        printf("vex%d:",i);
        while(p!=NULL){
            printf("->%d,",p->adjvex);
            p=p->nextarc;
        }
        printf("\n");
    }
    return al;
}

int main(){
    cc(*create_MGraph());
    return 0;
}