
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
#define NOTARRIVE 65535
typedef enum BOOL{
    NO = 0,
    YES
}BOOL;

typedef struct Graph{
    char vexs[MAXSIZE];
    int arc[MAXSIZE][MAXSIZE];
    int vexNum;
}Graph;


void dijkstra(Graph * g) {
    
    int dist[MAXSIZE];      //初始时, 顶点0到其他各顶点的路径
    int pre[MAXSIZE];       //保存v0 到 vi的最短路径上得前一个顶点
    BOOL used[MAXSIZE];     //保存顶点i是否已经被并入最短路径
    
    //1. 指定从顶点0开始
    used[0] = YES;
    dist[0] = 0;
    pre[0] = -1;
    
    //2. 初始化 剩下的n-1个顶点 的dist[] 、used[] 、pre[]
    for (int i = 1; i < g->vexNum ; i++) {
        
        //2.1)v0到vi得路径值
        dist[i] = g->arc[0][i];
        
        //2.2)标志顶点i没有被并入
        used[i] = NO;
        
        //2.3)修改pre数组
        if (g->arc[0][i] == NOTARRIVE) {
            pre[i] = -1;
            
        }else{
            pre[i] = 0;
        }
    }
    
    //
}





int main() {
    return 1;
}