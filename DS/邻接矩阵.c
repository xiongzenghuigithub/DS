///**
// *  图的存储形式1 -- 邻接矩阵 ( 只关心顶点 )
// */
//
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 100
//
//typedef char Data;
//
//typedef struct Vex{
//    Data data;
//}Vex;
//
//typedef struct Map1 {
//    int vexNum, arcNum;
//    Vex vexArr[MAXSIZE];
//    int matrix[MAXSIZE][MAXSIZE];
//}Map1;
//
//int getVexIndex(Data data, Map1 *p);
//void createMap1(Map1 *p);
//void deleteVex(Map1 *P, Data data);
//
//int getVexIndex(Data data, Map1 *p) {
//    int idx = -1;
//    int i;
//    for (i = 0; i < p->vexNum; i++) {
//        if (p->vexArr[i].data == data) {
//            idx = i;
//            break;
//        }
//    }
//    return idx;
//}
//
//void createMap1(Map1 *p) {
//    
//    scanf("%d", &p->vexNum);
//    scanf("\n%d", &p->arcNum);
//    
//    int i;
//    for (i = 0; i < p->vexNum; i++) {
//        
//        Data data;
//        scanf("%c", &data);
//        if (data != '#') {
//            Vex *v = (Vex *)malloc(sizeof(Vex));
//            v->data = data;
//            p->vexArr[i] = *v;
//        }
//    }
//    
//    for (i = 0; i < p->arcNum; i++) {
//        Data v1, v2;
//        scanf("\n %c, %c", &v1, &v2);
//        int idx1 = getVexIndex(v1, p);
//        int idx2 = getVexIndex(v2, p);
//        p->matrix[idx1][idx2] = 1;
//        p->matrix[idx2][idx1] = 1;
//    }
//}
//
//
//void deleteVex(Map1 *p, Data data) {
//    int idx = getVexIndex(data, p);
//    
//    int i,j;
//    
//    for (i = idx; i < p->vexNum; i++) {
//        for (j = 0; j < p->vexNum; j++) {
//            p->matrix[idx][j] = p->matrix[i+1][j];
//        }
//    }
//    
//    for (i = idx; i < p->vexNum; i++) {
//        for (j = 0; j < p->vexNum; j++) {
//            p->matrix[j][i] = p->matrix[j][i+1];
//        }
//    }
//    
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
