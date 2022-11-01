#include <stdio.h>
#include <stdlib.h>

typedef struct GNode GNode;
typedef struct Graph Graph;

struct GNode {
    int tag;
    int edgeSize;
    GNode** edges;
};

struct Graph {
    int nodeSize;
    GNode** nodes;
};

GNode* createGNode(int tag, int size) {
    GNode* node = malloc(sizeof(GNode));
    node->tag = tag;
    node->edgeSize = 0;
    node->edges = malloc(size * sizeof(GNode));
    return node;
}

Graph* createGraph(int size) {
    Graph* g = malloc(sizeof(Graph));
    g->nodeSize = size;
    g->nodes = malloc(size * sizeof(GNode));
    return g;
}

void randomGraph(Graph* g) {
    int size = g->nodeSize;

    for (int i = 0; i < size;i++) g->nodes[i] = createGNode(i, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0;j < size;j++) {
            if (i == j) continue;
            if (rand() % 100 < 20) {
                GNode* src = g->nodes[i];
                GNode* dst = g->nodes[j];
                src->edges[src->edgeSize++] = dst;
            }
        }
    }
}

void showGraph(Graph* g) {
    for (int i = 0; i < g->nodeSize; i++) {
        printf("Node %d ->", g->nodes[i]->tag);
        for (int j = 0;j < g->nodes[i]->edgeSize;j++) {
            printf("%d ", g->nodes[i]->edges[j]->tag);
        }
        printf("\n");
    }
}

int isDAG(Graph* g) {
    int* stack = malloc(g->nodeSize * sizeof(int));
    int stackIndex = 0;
    int nodeRemain = g->nodeSize;

    int* inDegrees = malloc(g->nodeSize * sizeof(int));
    for (int i = 0;i < g->nodeSize;i++) inDegrees[i] = 0;

    for (int i = 0;i < g->nodeSize;i++) {
        GNode* src = g->nodes[i];
        for (int j = 0;j < src->edgeSize;j++) {
            GNode* dst = src->edges[j];
            inDegrees[dst->tag]++;
        }
    }

    for (int i = 0;i < g->nodeSize;i++) {
        if (inDegrees[i] == 0) stack[stackIndex++] = i;
    }

    if (stackIndex == 0) return 0;

    while (stackIndex) {
        int i = stack[--stackIndex];
        nodeRemain--;
        GNode* currNode = g->nodes[i];
        for (int j = 0;j < currNode->edgeSize;j++) {
            GNode* dst = currNode->edges[j];
            inDegrees[dst->tag] --;
            if (inDegrees[dst->tag] <= 0) {
                stack[stackIndex++] = dst->tag;
            }
        }
    }

    free(stack);
    free(inDegrees);

    printf("Node remain:%d\n", nodeRemain);
    if (nodeRemain == 0) return 1;
    else return 0;

}

int main() {
    srand((unsigned) time(NULL));
    Graph* g = createGraph(5);
    int testCases = 10;
    for (int i = 0;i < testCases;i++) {
        printf("Test case %d:\n", i);
        randomGraph(g);
        showGraph(g);
        int result = isDAG(g);
        printf("The result is : %s\n\n", result ? "DAG" : "not DAG");
    }

    return 0;
}