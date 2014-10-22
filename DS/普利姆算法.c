/**
 *   图 -- 采用邻接矩阵存储 -- 普利姆算法求最小生成树(求出连接所有顶点的边的最小权值之和)
 *
 *          （不断的并入 顶点）
 */

#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define NOT_ARRIVE 65535

typedef struct Graph{
    
    char vexs[MAXSIZE];                 //顶点数组
    int matrix[MAXSIZE][MAXSIZE];       //保存边的权值得邻接矩阵
    int vexnum, arcnum;                 //图的顶点数和边树
    
}Graph;

void createGraph(Graph *g);
int getIndex(Graph *g, char data);

/**
 *  从给定顶点开始构造最小生成树
 */
void prim(Graph *g, char data);
/**
 *  获取当前顶点到其他最小权值的顶点编号
 *
 *  @param vexNum : 图的总顶点数
 *  @lowCost[]    : 顶点到其他所有顶点的权值数组
 */
//int getMinCostVexIndex(int vexNum, int lowCost[]);

int getIndex(Graph *g, char data) {
    int i, idx = -1;
    for (i = 0; i < g->vexnum; i++) {
        if (data == g->vexs[i]) {
            idx = i;
            break;
        }
    }
    return idx;
}

void createGraph(Graph *g) {
    scanf("%d,%d", &g->vexnum, &g->arcnum);
    
    int i,j;
    
    //构造顶点
    for (i = 0; i < g->vexnum; i++) {
        scanf("\n%c", &g->vexs[i]);
    }
    
    //初始化边的二维矩阵里元素全部表示不可到达
    for (i = 0; i < g->vexnum; i++) {
        for (j = 0; j < g->vexnum; j++) {
            g->matrix[i][j] = NOT_ARRIVE;
        }
    }
    
    //输入可到顶点之间边的权值(邻接矩阵的matrix[i][j]有值表示可到达，并且是权值)
    char v1, v2;
    int weight;
    for (i = 0; i < g->arcnum; i++) {
        scanf("\n%c,%c,%d", &v1, &v2, &weight);
        g->matrix[getIndex(g, v1)][getIndex(g, v2)] = weight;
        g->matrix[getIndex(g, v2)][getIndex(g, v1)] = weight;
    }
}


void prim(Graph *g, char data) {
    
    
    /**
     *      vexs[i] = j ==>> j号顶点到i号顶点的, 边
     *      lowcost[i] = k ==>> j号顶点到i号顶点的, 权值
     */
    int arcArr[MAXSIZE];                           //边数组
    int lowcost[MAXSIZE];                        //权值数组
    
    //1) 默认从第0号顶点开始遍历 (0号顶点到0号顶点的权值==0)
    arcArr[0] = 0;
    lowcost[0] = 0;
    
    //2) 计算0号顶点到其他所有顶点的权值数组
    int i;
    for (i = 1; i < g->vexnum; i++) {           //i从1开始，因为默认从0号顶点开始遍历，所以避开自己到自己的情况
        arcArr[i] = 0;
        lowcost[i] = g->matrix[0][i];
    }
    
    //3)
    for (i = 1; i < g->vexnum; i++) {           //循环全部顶点 (n个点有n-1条边，所以只需要循环n-1次)
        
        int minCost = NOT_ARRIVE;
        int j = 1;                              //排除0号顶点
        int k = 0;                              //保存权值最小的权值数组元素下标值
        
        while (j < g->vexnum) {
            if (lowcost[j] != 0 && lowcost[j] < minCost) {  //如果权值不为0且权值小于min
                
                minCost = lowcost[j];           //保存最小权值
                k = j;                          //保存最小权值的下标
            }
            j++;
        }
        
        //打印当前顶点边中权值最小的边
        printf("当前权值最小的边是: %d号顶点 --> %d号顶点\n", arcArr[k], k); //vexs[i]=j ==> 顶点j到顶点i
        
        //将选中的顶点k的权值置0, 表示已经加入到最小生成树
        lowcost[k] = 0;                             //标志顶点k已经访问
        
        for (j = 1; j < g->vexnum; j++) {       //循环全部顶点 (n个点有n-1条边，所以只需要循环n-1次)
            
            //如果下标为k顶点各边权值小于此前这些顶点未被加入生成树权值
            if (lowcost[j] != 0 && g->matrix[k][j] < lowcost[j]) {  //lowCost[j] --> vexs[j] --> 其他所有顶点到顶点j的边权值
                lowcost[j] = g->matrix[k][j];       //将较小的权值存入lowcost相应位置
                arcArr[j] = k;                        //将(顶点k-->顶点j)边 保存到边数组
            }
        }
    }
    
}













