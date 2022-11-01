#define MAX_NUM 100
typedef struct {
    int num;
    char data;
}vertex;
typedef struct{
    int n,m;
    vertex vertexs[MAX_NUM];
    int edges[MAX_NUM][MAX_NUM];
}Mgraph;

typedef struct node1{
    char info;
    struct node1 *nextarc;
    int adjvex;
}arcnode;

typedef struct{
    char data;
    arcnode *firstarc;
}vertexnode,adjlist[MAX_NUM];
typedef struct{
    int n,e;
    adjlist vextices;
}graph;