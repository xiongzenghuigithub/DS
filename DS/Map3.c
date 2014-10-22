///**
// *  图 -- 十字链表 (以边为核心, 使同时具有入度和出度)
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 100
//
//typedef struct Arc {
//    int headVexID;              //边的狐头顶点ID
//    int tailVexID;              //边的狐尾顶点ID
//    struct Arc * headLink;      //拥有相同狐头顶点ID的第一条入度边
//    struct Arc * tailLink;      //
//}Arc;
//
//typedef struct Vex {
//    char data;
//    Arc * firstOut;
//    Arc * firstIn;
//}Vex;
//
//typedef struct Map {
//    int vexNum;
//    int arcNum;
//    Vex vexArr[MAXSIZE];
//}Map;
//
//void createMap(Map *p);
//int getVexIndex(Map *p, char data);
//
//void createMap(Map *p) {
//    scanf("%d,%d", &p->vexNum, &p->arcNum);
//    
//    int i;
//    for (i = 0; i < p->vexNum; i++) {
//        Vex *v = (Vex *)malloc(sizeof(Vex));
//        scanf("\n%c", &v->data);
//        v->firstOut = v->firstIn = NULL;
//        p->vexArr[i] = *v;
//    }
//    
//    int v1, v2;
//    for (i = 0; I < p->arcNum; i++) {
//        scanf("\n%c,%c", &v1, &v2);
//        int v1_pos = getVexIndex(p, v1);
//        int v2_pos = getVexIndex(p, v2);
//        
//        Arc *q = (Arc *)malloc(sizeof(Arc));
//        q->headVexID = v2_pos;
//        q->tailVexID = v1_pos;
//        
//        q->headLink = p->vexArr[v2_pos].firstIn;
//        p->vexArr[v2_pos].firstIn = q;
//        
//        q->tailLink = p->vexArr[v1_pos].firstIn;
//        p->vexArr[v1_pos].firstIn = q;
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
//
//
