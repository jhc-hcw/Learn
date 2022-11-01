/*
（1）假设以邻接矩阵作为图的存储结构，编写算法判断在给定的有向图中是否存在一个简单有向回路。
提示：判别一个图是否有回路，可以有以下几种方法：
①利用深度优先遍历；
②拓扑排序。
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/*图的邻接矩阵存储表示法*/
//用两个数组分别存储顶点表和邻接矩阵
#define MaxInt 32767  //表示极大值，即无穷
#define MVNum 100  //最大顶点数
typedef char VerTexType;  //假设顶点的数据类型为字符型
typedef int ArcType;	//假设边的权值类型为整型
typedef struct
{
	// VerTexType vexs[MVNum];	//顶点表
    char vexs[MVNum];	//顶点表
	// ArcType arcs[MVNum][MVNum];	//邻接矩阵
    int arcs[MVNum][MVNum];	//邻接矩阵
	int vexnum, arcnum;	//图的当前顶点数和边数
}AMGraph;

void Create_DN(AMGraph *G)  //使用邻接矩阵创建有向图
{
    int i, j;
    VerTexType v1, v2;

    //创建顶点集
    G = (AMGraph *)malloc(sizeof(AMGraph));   //为图G动态分配内存空间
    printf("请输入顶点个数和边数：");
    scanf("%d %d", &G -> vexnum, &G ->arcnum);
    fflush(stdin);
    printf("请输入%d个顶点:", G -> vexnum);
    for(i = 0; i < G -> vexnum; i++)    //输入顶点
    {
        scanf("%c", &G -> vexs[i]);
    }
    printf("%c\n", G -> vexs[0]);
    printf("%c\n", G -> vexs[1]);
    printf("%c\n", G -> vexs[2]);
    printf("%c\n", G -> vexs[3]);
    printf("%c\n", G -> vexs[4]);
    printf("\n");

    // //创建邻接矩阵
    // for(i = 0)

    //显示所有的结点信息
    printf("图中的顶点为：");   
    for(j = 0; j < G -> vexnum; j++)
    {
        printf("%c",G->vexs[j]);
    }
    printf("\n");
}

int main()
{
    AMGraph *A = (AMGraph *)malloc(sizeof(AMGraph));
    Create_DN(A);
    return 0;
}
