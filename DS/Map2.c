///**
// *      图 -- 链接表 (以边为核心)
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//#define MAXSIZE 100
//
//typedef struct Arc {
//    int vexID;                  //当前有向边指向的顶点在顶点数组的下标值
//    struct Arc * next;          //下一条拥有相同狐尾(或狐头)的边
//}Arc;
//
//typedef struct Vex {
//    char data;
//    Arc * firstOut;                //当前顶点的第一条出度边(或入度边)
//}Vex;
//
//typedef struct Map2 {
//    int vexNum, arcNum;
//    Vex vexArr[MAXSIZE];
//}Map2;
//
//int getVexIndex(char data ,Map2 *p);
//void createMap2(Map2 *p);
//
///**
// *  链接表存储图 -- 深度优先遍历
// *
// *  @param p       : 图
// *  @param pos     : 给定一个开始遍历的位置
// *  @param visit[] : 记录被访问顶点的标志数组
// */
//void DFS(Map2 *p, int pos,  int visit[], void (*Print)(char));
//
///**
// *  链接表存储图 -- 广度优先遍历
// *
// *  @param p       : 图
// *  @param pos     : 给定一个开始遍历的位置
// *  @param visit   : 记录被访问顶点的标志数组
// *  @param Print   :
// */
//void BFS(Map2 *p, int pos, int visit[], void (*Print)(char));
//
//int getVexIndex(char data ,Map2 *p) {
//    int i, idx = -1;
//    for (i = 0 ; i < p->vexNum ; i++) {
//        if (data == p->vexArr[i].data) {
//            idx = i;
//            break;
//        }
//    }
//    return idx;
//}
//
//void createMap2(Map2 *p) {
//    
//    scanf("%d, %d", &p->vexNum, &p->arcNum);
//    
//    int i;
//    for (i = 0; i < p->vexNum; i++) {
//        
//        Vex *v = (Vex *)malloc(sizeof(Vex));
//        scanf("/n%c", &v->data);
//        v->firstOut = NULL;
//        
//        p->vexArr[i] = *v;
//    }
//    
//    char v1, v2;
//    for (i = 0; i < p->arcNum; i++) {
//        
//        scanf("\n%c,%c", &v1, &v2);
//        
//        int v1_pos = getVexIndex(v1, p);
//        int v2_pos = getVexIndex(v2, p);
//        
//        Arc *q = (Arc *)malloc(sizeof(Arc));
//        q->vexID = v2_pos;
//        
//        q->next = p->vexArr[v1_pos].firstOut;
//        p->vexArr[v1_pos].firstOut = q;
//    }
//}
//
//void DFS(Map2 *p, int pos, int visit[], void (*Print)(char)) {
//    
//    //1.
//    if (visit[pos] != 1) {
//        
//        //2.
//        Print(p->vexArr[pos].data);
//        
//        //3.
//        visit[pos] = 1;
//        
//        //4.
//        Arc *q = p->vexArr[pos].firstOut;
//        
//        //5.
//        while (q) {
//            
//            int vexID = q->vexID;
//            if (visit[vexID] != 1) {//当前遍历边指向的顶点未访问
//                
//                //6.递归遍历
//                DFS(p, vexID, visit ,Print);
//            }
//            
//            q = q->next;
//        }
//    }
//}
//
//
//void BFS(Map2 *p, int pos, int visit[], void (*Print)(char)) {
//    
//    //1.
//    int queue[MAXSIZE], front = 0, rear = 0;
//    rear = (rear + 1) % MAXSIZE;
//    queue[rear] = pos;
//    
//    //2.
//    while ((rear + 1) % MAXSIZE != front) {
//        
//        front = (front + 1) % MAXSIZE;
//        int vexID = queue[front];
//        
//        if (visit[vexID] != 1) {
//            
//            Print(p->vexArr[vexID].data);
//            visit[vexID] = 1;
//            
//            Arc *q = p->vexArr[vexID].firstOut;
//            while (q) {
//                if (visit[q->vexID] != 1) {
//                    rear = (rear + 1) % MAXSIZE;
//                    queue[rear] = q->vexID;
//                }
//                
//                q = q->next;
//            }
//        }
//    }
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
//
//
