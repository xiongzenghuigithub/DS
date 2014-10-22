//
///**
// *  二叉树
// */
//#include <stdio.h>
//#include <stdlib.h>
//
//#define MAXSIZE 100
//
//typedef struct BiTreeNode{
//    
//    char data;
//    struct BiTreeNode * lchild;
//    struct BiTreeNode * rchild;
//    
//}BiTreeNode;
//
///**
// *  先序递归创建二叉树
// */
//BiTreeNode * PreOrderCreateBiTree();
//
///**
// *  计算二叉树的高度
// */
//int getDepth(BiTreeNode *p);
//
////先序递归遍历
//void PreOrderTraverse(BiTreeNode *p, void (*visit)(char));
//
////深度优先递归遍历
//void DFS(BiTreeNode *p, void (*visit)(char));
//
////广度优先递归遍历
//void BFS(BiTreeNode *p, void (*visit)(char));
//
//BiTreeNode * PreOrderCreateBiTree() {
//    
//    char data;
//    scanf("%c", &data);
//    
//    if (data != '#') {
//        
//        //1.
//        BiTreeNode * t = (BiTreeNode *)malloc(sizeof(BiTreeNode));
//        t->data = data;
//        
//        //2.
//        t->lchild = PreOrderCreateBiTree();
//        
//        //3.
//        t->rchild = PreOrderCreateBiTree();
//        
//        return t;
//        
//    }else {
//        return NULL;
//    }
//}
//
//int getDepth(BiTreeNode *p) {
//    
//    if (p) {
//        int ldep = getDepth(p->lchild) ;
//        int rdep = getDepth(p->rchild) ;
//        return (ldep > rdep) ? ldep:rdep + 1;
//    }else {
//        return 0;
//    }
//}
//
//void PreOrderTraverse(BiTreeNode *p, void (*visit)(char)) {
//    if (p) {
//        visit(p->data);
//        PreOrderTraverse(p->lchild, visit);
//        PreOrderTraverse(p->rchild, visit);
//    }
//}
//
////借助栈 -- 深度
//void DFS(BiTreeNode *p, void (*visit)(char)) {
//    
//    //1.
//    BiTreeNode * stack[MAXSIZE];
//    int  top = -1;
//    
//    //2.
//    top = top + 1;
//    stack[top] = p;
//    
//    //3.
//    while (top != -1) {
//        
//        BiTreeNode * t = stack[top];
//        top = top - 1;
//        
//        if (t->lchild) {
//            top = top + 1;
//            stack[top] = t->lchild;
//        }
//        
//        if (t->rchild) {
//            top = top + 1;
//            stack[top] = t->rchild;
//        }
//    }
//}
//
////借助队列 -- 广度
//void BFS(BiTreeNode *p, void (*visit)(char)){
//    
//    //1.
//    BiTreeNode * queue[MAXSIZE];
//    int rear = 0, front = 0;
//    
//    //2.
//    rear = (rear + 1) % MAXSIZE;
//    queue[rear] = p;
//    
//    //3.
//    while ((rear + 1) % MAXSIZE != front) {
//        front = (front + 1) % MAXSIZE;
//        BiTreeNode *t = queue[front];
//        
//        if (t->lchild) {
//            rear = (rear + 1) % MAXSIZE;
//            queue[rear] = t->lchild;
//        }
//        
//        if (t->rchild) {
//            rear = (rear + 1) % MAXSIZE;
//            queue[rear] = t->rchild;
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
