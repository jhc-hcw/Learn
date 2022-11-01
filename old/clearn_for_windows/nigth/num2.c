#include<stdio.h>
#include<malloc.h>
#define MAX_VERTEX_NUM 100
typedef struct node1{
    int adjvex;
    struct node1 *nextarc;
    char info;
}ARCNODE;
typedef struct VEXNODE{
    char vexdata;
    ARCNODE *firstarc;
}VEXNODE,AdjList[MAX_VERTEX_NUM];
typedef struct{
    AdjList vextices;
    int vexnum,arcnum;
}ALGraph;
ALGraph create_AdjListgraph(){
    int n,e,i,j,k;
    char c;
    // ARCNODE *p;AdjList al;
    ALGraph alg;
    printf("请输入结点个数：");
    scanf("%d",&n);
    printf("请输入结点信息：");
    fflush(stdin);
    for(i=0;i<n;i++){
        scanf("%c ",&c);
        alg.vextices[i].vexdata=c;
        alg.vextices[i].firstarc=NULL;
    }
    fflush(stdin);
    printf("请输入边的个数：");
    scanf("%d",&e);
    printf("请输入边的信息:");
    fflush(stdin);
    for(i=0;i<e;i++){
        scanf("%d-%d,",&j,&k);
        ARCNODE *arc=malloc(sizeof(ARCNODE));
        arc->adjvex=k;
        arc->nextarc=NULL;
        ARCNODE *p=alg.vextices[j].firstarc;
        if(p==NULL){
            alg.vextices[j].firstarc=arc;
        }else{
            while(p->nextarc!=NULL){
                p=p->nextarc;
            }
            p->nextarc=arc;
        }
    }
    alg.vexnum=n;
    alg.arcnum=e;
    for(int i=0;i<alg.vexnum;i++){
        ARCNODE *p=alg.vextices[i].firstarc;
        printf("vex%d:",i);
        while(p!=NULL){
            printf("->%d,",p->adjvex);
            p=p->nextarc;
        }
        printf("\n");
    }
    return alg;
}
//通过广度优先搜索遍历找ab是否存在通路。
void cc(ALGraph al,int a,int b){
    int queue[MAX_VERTEX_NUM];  //顺序队列，访问的节点信息。
    int head=0,rear=0;
    int visted[MAX_VERTEX_NUM];//标记数组，标记结点是否被访问过
    for(int i=0;i<MAX_VERTEX_NUM;i++) visted[i]=0;   //初始化标记数组
    queue[++rear]=a;      //将骑士结点入队列
    while(head!=rear){   
        int k=rear;   //用k标记队列中前一层节点位置的末尾。
        while(head!=k){    //将前一层节点的邻边进行访问。
            int p=queue[++head];  //取队首。
            ARCNODE *arc=al.vextices[p].firstarc;  //取结点的邻边指针
            while(arc!=NULL){   //遍历所有结点的邻边
                if(visted[arc->adjvex]==0){   //访问边的终点，如果第一次访问就入队列。
                    visted[arc->adjvex]=1;
                    queue[++rear]=arc->adjvex;
                    if(arc->adjvex==b){  //如果发现边的终点是所找结点，就打印。
                        printf("两点是连通的！");
                        return ;
                    }
                }
                arc=arc->nextarc;
            }
        }
    }
    printf("两点不是连通的！");
}

int main(){
    // ALGraph al=create_AdjListgraph();
    // int a,b;
    // printf("请输入判断的两个顶点：");
    // scanf("%d %d",&a,&b);
    // cc(al,a,b);
    ALGraph *p=malloc(sizeof(ALGraph));
    p->vexnum[0]
    printf("%d",sizeof(ALGraph));
    return 0;
}