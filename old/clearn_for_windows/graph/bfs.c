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
int vised[MAX_VERTEX_NUM];
typedef struct{
    int data[50];
    int front,rear;
}squeue;
squeue init_queue(){
    squeue queue;
    queue.front=0;
    queue.rear=0;
    return queue;
}
int isempty(squeue q){
    if(q.front==q.rear){
        return 1;
    }else return 0;
}
int isfull(squeue q){
    if(q.front==(q.rear+1)%50){
        return 1;
    }else return 0;
}
void add(squeue q,int x){
    if(!isfull(q)){
        q.rear=(q.rear+1)%50;
        q.data[q.rear]=x;
    }else printf("满了！");
}
void delete(squeue q){
     if(isempty(q)){
         q.front=(q.front+1)%50;
         return q.data[q.front];
     }else printf("空了！");
} 
void dfs_trave(ALGraph al){
    int i;
    for(i=0;i<al.vexnum;i++){
        vised[i]=0;
    }
    for(i=0;i<al.vexnum;i++){
        if(vised[i]==0){
            dfs(al,i);
        }
    }
}
void dfs(ALGraph al,int i){
    printf("%c %d,",al.vextices[i].vexdata,i);
    vised[i]=1;
    ARCNODE *p=al.vextices[i].firstarc;
    while(p){
        if(vised[p->adjvex]==0){
            dfs[al,p->adjvex];
        }
        p=p->nextarc;
    }
}
squeue qu=init_queue();
void vfs_trave(ALGraph al){
    int i;
    for(i=0;i<al.vexnum;i++){
        vised[i]=0;
    }
    for(i=0;i<al.vexnum;i++){
        if(vised[i]==0){
            bfs(al,i);
        }
    }
}
void bfs(ALGraph al,int i){
    int j;
    ARCNODE *p;
    printf("%d,",i);
    vised[i]=1;
    add(qu,i);
    while(!isempty(qu)){
        j=delete(qu);
        p=al.vextices[j].firstarc;
        while(p){
            if(vised[p->adjvex]==0){
                printf("%d,",j);
                vised[j]=0;
                add(qu,j);
            }
            p=p->nextarc;
        }
    }
}
int main(){
    ALGraph al=create_AdjListgraph();
    int a,b;
    printf("请输入判断的两个顶点：");
    scanf("%d %d",&a,&b);
    cc(al,a,b);
    return 0;
}