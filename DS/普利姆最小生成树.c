///**
// *   图 -- 采用邻接矩阵存储 -- 普利姆算法求最小生成树(求出连接所有顶点的边的最小权值之和)
// *
// *          （不断的并入 顶点）
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 100
//#define NOT_ARRIVE 65535
//#define min(x,y)((x>y)?x:y)
//
//typedef struct Graph{
//    
//    char vexs[MAXSIZE];                 //顶点数组
//    int matrix[MAXSIZE][MAXSIZE];       //保存边的权值得邻接矩阵
//    int vexnum, arcnum;                 //图的顶点数和边树
//    
//}Graph;
//
//void createGraph(Graph *g);
//int getIndex(Graph *g, char data);
//
//int getIndex(Graph *g, char data) {
//    int i, idx = -1;
//    for (i = 0; i < g->vexnum; i++) {
//        if (data == g->vexs[i]) {
//            idx = i;
//            break;
//        }
//    }
//    return idx;
//}
//
//void createGraph(Graph *g) {
//    scanf("%d,%d", &g->vexnum, &g->arcnum);
//    
//    int i,j;
//    
//    //构造顶点
//    for (i = 0; i < g->vexnum; i++) {
//        scanf("\n%c", &g->vexs[i]);
//    }
//    
//    //初始化边的二维矩阵里元素全部表示不可到达
//    for (i = 0; i < g->vexnum; i++) {
//        for (j = 0; j < g->vexnum; j++) {
//            g->matrix[i][j] = NOT_ARRIVE;
//        }
//    }
//    
//    //输入可到顶点之间边的权值(邻接矩阵的matrix[i][j]有值表示可到达，并且是权值)
//    char v1, v2;
//    int weight;
//    for (i = 0; i < g->arcnum; i++) {
//        scanf("\n%c,%c,%d", &v1, &v2, &weight);
//        g->matrix[getIndex(g, v1)][getIndex(g, v2)] = weight;
//        g->matrix[getIndex(g, v2)][getIndex(g, v1)] = weight;
//    }
//}
//
//typedef enum {YES = 0, NO}BOOL ;
//void prim(Graph *g, int *sum) {
//    
//    int mincost[MAXSIZE];                            //从给定的初始顶点(v0)到其他各顶点的最小权值
//    BOOL used[MAXSIZE];                              //标识顶点i是否已经被并入
//    int n = g->vexnum;                               //总顶点数
//    
//    //1) 初始化2个数组
//    int i;
//    for (i = 0; i <  n; i++) {
//        mincost[i] = NOT_ARRIVE;
//        used[i] = NO;
//    }
//    
//    mincost[0] = 0;                                 //从v0到v0的最小权值为0
//    sum = 0;
//
//    
//    while (YES) {
//        
//        int v = -1;     //v保存每一次要并入的顶点
//        
//        for (int i = 0; i < n ; i++) {
//            if (used[i] == NO && (v == -1 || mincost[i] < mincost[v])) {    //取最小(初始)权值的边
//                v = i;
//            }
//        }
//        
//        //全部顶点并入完毕
//        if (v == -1) {
//            break;
//        }
//        
//        //还有未并入的顶点
//        used[v] = YES;
//        sum += mincost[v];
//        
//        for (int i = 0; i < n; i++) {
//            mincost[i] = min(mincost[i], g->matrix[v][i]);
//        }
//    }
//    
//}
//
//
//void prim2(Graph *g, int * sum){
//    
//	//1. 定义2个数组
//	int mincost[MAXSIZE];		//保存到定点i的最小权值
//	BOOL used[MAXSIZE];			//标识定点i是否已经被并入生成树
//    
//	int num = g->vexnum;		//总得顶点数
//    
//	//2. 先将顶点0并入生成树
//	used[0] = YES;
//	mincost[0] = 0;
//	sum = 0;
//    
//	//3. 初始化顶点0到其他所有顶点的权值
//	for (int i = 1; i < num; ++i)
//	{
//		mincost[i] = g->matrix[0][i];
//		used[i] = NO;
//	}
//    
//	//4. 不断的并入剩下的 n-1 个顶点
//	while (YES) {
//        
//		//4.1) 找出顶点0到其他顶点最小边权值的顶点, 再并入
//		int min = NOT_ARRIVE;
//		int v = -1;
//		for (int i = 1; i < num; ++i)
//		{
//			if (used[i] == NO && mincost[i] < min)
//			{
//				min = mincost[i];
//				v = i;
//			}
//		}
//        
//		//4.2) 如果顶点已经全部并入完毕
//		if (v == -1)
//		{
//			break;
//		}
//        
//		//4.3) 并入顶点V
//		used[v] = YES;
//		mincost[v] = min;
//        
//		//4.4) 修正mincost[v]是否是最小权值
//		//查看生成树中刚刚并入的顶点v, 到剩下的顶点权值是否小于初始化时给所有顶点初始的权值(顶点0到其他所有顶点的权值)
//		for (int i = 1; i < num; ++i)
//		{
//			if (used[i] == NO && g->matrix[v][i] < mincost[i])
//			{
//				mincost[i] = g->matrix[v][i];
//			}
//		}
//	}
//}
//
//
//int main() {
//    return 1;
//}
//
//
//
//
//
//
//
//
//
//
//
