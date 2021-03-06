///**
// *      最小生成树--克鲁斯卡尔算法
// *
// *			1. 借助 并查集 判断当前要加入的边 是否会产生回路
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#define MAXSIZE 100
//#define NOT_ARRIVE 65535
//#define min(x ,y) ((x > y)?x:y)
//
//typedef enum {NO = 0, YES} BOOL;
//
//
////并查集数据结构
//typedef struct UnionSet{
//    
//    int parant[MAXSIZE];
//    int rank[MAXSIZE];
//    
//}UnionSet;
//
//void InitUnionSet(UnionSet * u);
//int Find(UnionSet * u, int x);
//void Union(UnionSet * u, int x, int y);
//
//void initUnionSet(UnionSet * u) {
//    for (int i = 0; i < MAXSIZE; i++) {
//        u->parant[i] = i;   //把自己作为自己的根节点
//        u->rank[i] = 0;
//    }
//}
//
//int Find(UnionSet * u, int x) {
//    if (u->parant[x] != x) {
//        u->parant[x] = Find(u, u->parant[x]);
//    }
//    return u->parant[x];
//}
//
//void Union(UnionSet * u, int x, int y) {
//    x = Find(u, x);
//    y = Find(u, y);
//    
//    if (u->rank[x] < u->rank[y]) {
//        u->parant[x] = y;
//        
//    }else {
//        
//        u->parant[y] = x;
//        if (u->rank[x] == u->rank[y]) {
//            u->rank[x]++;
//        }
//    }
//}
//
//
////图
//typedef struct Graph {
//    char vexs[MAXSIZE];
//    int matrix[MAXSIZE][MAXSIZE];
//    int vexnum, edgenum;
//}Graph;
//
////边结构 (从顶点v1 到 顶点v2 的权值 是多少)
//typedef struct Edge{
//    
//    int beginVex;		//边的起始顶点
//    int endVex;			//边的结束顶点
//    int weight;			//边的权值
//    
//}Edge;
//
//void getEdgeArr(Graph *g, Edge edge[]);
//void sort(Edge edge[], int length);
//void kruskal(Graph * g, int * sum);
//
////使用图的邻接矩阵构造边集数组 
//void getEdgeArr(Graph *g, Edge edge[]){
//	for (int i = 0; i < g->vexnum; ++i)
//	{
//		for (int j = 0; j < g->vexnum; ++j)
//		{
//			if ( i != j)	//排除自己到自己
//			{
//				if (g->matrix[i][j] != NOT_ARRIVE)	//2个顶点之间是有边的
//				{
//					Edge * e = (Edge *)malloc(sizeof(Edge));
//					e->beginVex = i;
//					e->endVex = j;
//					e->weight = g->matrix[i][j];				
//				}
//			}
//		}
//	}
//}
//
////按照每一条边的权值从小到达排序
//void sort(Edge edge[], int length) {
//	//多种排序方法
//}
//
//void kruskal(Graph * g , int * sum) {
//
//	//1. 边的顶点数和边数
//	int vexnum = g->vexnum, edgenum = g->edgenum;
//
//	//2. 从图的邻接矩阵初始化集数组
//	Edge edge[MAXSIZE];
//	getEdgeArr(g, edge);
//
//	//3. 对边集数组排序
//	sort(edge, edgenum);
//
//	//4. 借助并查集结构 判断当前边加入后是否会形成回路
//    UnionSet set;
//    InitUnionSet(&set);
//
//    for (int i = 0; i < edgenum; i++) {
//        
//        //查找边集2个顶点各自的父顶点
//        int n = Find(&set, edge[i].beginVex);
//        int m = Find(&set, edge[i].endVex);
//        
//        //各自的跟节点不在同一个集合(树)中 ==> 加入的边不可能形成回路
//        if (n != m) {
//            
//            //并入顶点
//            set.parant[n] = m;
//            
//            //累加权值
//            sum += edge[i].weight;
//        }
//    }
//}
//
//
