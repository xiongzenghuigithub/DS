///*
//
//#include <stdio.h>
//#include <stdlib.h>
//
//typedef enum {
//    CHILD = 0,
//    THREAD
//}LinkType;
//
//typedef struct ThreadTree{
//    int no;
//    struct ThreadTree *lchild;
//    struct ThreadTree *rchild;
//    LinkType ltag;
//    LinkType rtag;
//}ThreadTree;
//
//ThreadTree * createBiTree();
//void completThread(ThreadTree *p);
//void threading(ThreadTree *p, ThreadTree *pre);
//void InOrderTraverse(ThreadTree *p, void (*func_p)(int));
//
///**
// *  获取给定节点p的直接前驱节点
// */
//ThreadTree * getPreNode(ThreadTree *p);
//
///**
// *  获取给定节点p的直接后继节点
// */
//ThreadTree * getLastNode(ThreadTree *p);
//
//
//ThreadTree * createBiTree() {
//    
//    int no;
//    scanf("%d", &no);
//    
//    if (no != 0) {
//        ThreadTree *t = (ThreadTree *)malloc(sizeof(ThreadTree));
//        t->no = no;
//        t->lchild = createBiTree();
//        t->rchild = createBiTree();
//        return t;
//    }else {
//        return NULL;
//    }
//}
//
//
//ThreadTree *pre = NULL;
//void completThread(ThreadTree *p) {
//    ThreadTree *t = p;
//    if (p) {
//        threading(t, pre);
//        t->rchild = pre;
//        t->rtag = THREAD;
//        pre->rchild = p;
//        pre->rtag = THREAD;
//    }
//}
//
//void threading(ThreadTree *p, ThreadTree *pre) {
//    ThreadTree *t = p;
//    if (t) {
//        //1.
//        threading(t->lchild, pre);
//        
//        //2.
//        if (t->lchild == NULL && pre != NULL) {
//            t->lchild = pre;
//            t->ltag = THREAD;
//        }
//        if (t->rchild == NULL && pre != NULL) {
//            pre->rchild = t;
//            pre->rtag = THREAD;
//        }
//        pre = t;
//        
//        //3.
//        threading(t->rchild, pre);
//    }
//}
//
//
//ThreadTree * getPreNode(ThreadTree *p) {
//    
//    if (p->ltag == THREAD) {
//        //1. 如果有前驱节点的线索
//        return p->lchild;
//    }else {
//        //2. 没有线索, 那么当前节点的前驱节点 == 当前节点左子树中最右下角节点
//        ThreadTree *t = p->lchild;
//        while (t->rtag == CHILD) {
//            t = t->rchild;
//        }
//        return t;
//    }
//}
//
//ThreadTree * getLastNode(ThreadTree *p) {
//    
//    if (p->rtag == THREAD) {
//        //1. 有后继节点的线索
//        return p->rchild;
//    }else {
//        //2. 没有线索, 那么当前节点的后继节点 == 当前节点的右子树中最左下角的节点
//        ThreadTree *t = p->rchild;
//        while (t != NULL && t->ltag == CHILD) {
//            t = t->lchild;
//        }
//        return t;
//    }
//}
//
//void visit(int no) {
//    printf("当前当问的节点.no = %d\n" ,no);
//}
//
//void InOrderTraverse(ThreadTree *p, void (*func_p)(int)) {
//    
//    ThreadTree *t = p;
//    
//    //1. 找到树的最左孩子
//    while (t->ltag == CHILD) {
//        t = t->lchild;
//    }
//    
//    //2. 访问节点
//    visit(t->no);
//    
//    //3. 依次获取每一个节点的后继节点
//    ThreadTree *last = getLastNode(t);
//    while (last != NULL) {
//        visit(last->no);
//        last =  (last);
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
