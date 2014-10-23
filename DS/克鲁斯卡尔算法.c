/**
 *      最小生成树--克鲁斯卡尔算法
 */

#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100
#define NOT_ARRIVE 65535
#define min(x ,y) ((x > y)?x:y)

typedef enum {NO = 0, YES} BOOL;

//图
typedef struct Graph {
    char vexs[MAXSIZE];
    int matrix[MAXSIZE][MAXSIZE];
    int vexnum, edgenum;
}Graph;

//边结构 (从顶点v1 到 顶点v2 的权值 是多少)
typedef struct Edge{
    
    int beginVex;		//边的起始顶点
    int endVex;			//边的结束顶点
    int weight;			//边的权值
    
}Edge;

void getEdgeArr(Graph *g, Edge edge[]);
void sort(Edge edge[], int length);
void kruskal(Graph *g);

//使用图的邻接矩阵构造边集数组 
void getEdgeArr(Graph *g, Edge edge[]){
	for (int i = 0; i < g->vexnum; ++i)
	{
		for (int j = 0; j < g->vexnum; ++j)
		{
			if ( i != j)	//排除自己到自己
			{
				if (g->matrix[i][j] != NOT_ARRIVE)	//2个顶点之间是有边的
				{
					Edge * e = (Edge *)malloc(sizeof(Edge));
					e->beginVex = i;
					e->endVex = j;
					e->weight = g->matrix[i][j];				
				}
			}
		}
	}
}

//按照每一条边的权值从小到达排序
void sort(Edge edge[], int length) {
	//多种排序方法
}

void kruskal(Graph *g) {

	//1. 边的顶点数和边数
	int vexnum = g->vexnum, edgenum = g->edgenum;

	//2. 从图的邻接矩阵初始化集数组
	Edge edge[MAXSIZE];
	getEdgeArr(g, edge);

	//3. 对边集数组排序
	sort(edge, edgenum);

	


}



















int main() {
    return 1;
}