
#include <stdio.h>
#include <stdlib.h>

typedef char Data;

//-----------------单链表--------------------
typedef struct LNode{
    Data data;
    struct LNode *next;
    
}LNode;

//头插法
void createLinkListWithHead(LNode *head, int length) {
    
    int i;
    for (i = 0; i < length; i++) {
        
        LNode *node = (LNode *)malloc(sizeof(LNode));
        scanf("%c", &node->data);
        
        node->next = head->next;
        head->next = node;
    }
}

//尾插法
LNode *tailLink = NULL;
void createLinkListWithTail(LNode *head, int length){
    
    tailLink = head;
    
    int i;
    for (i = 0; i < length; i++) {
        
        LNode *node = (LNode *)malloc(sizeof(LNode));
        scanf("%c", &node->data);
        
        tailLink->next = node;
        tailLink = node;
    }
}

//查找值为data的节点的地址
LNode * getIdxWithData(LNode *head, Data data){
    
    LNode *p = NULL , *pre = NULL;
    p = head;
    
    while (p != NULL) {
        
        //保存p指针的前一个节点
        pre = p;
        
        if (p->data == data) {
            break;
        }
        
        p = p->next;
    }
    
    return pre;
}

//插入元素
void insert(LNode *head, Data data, Data data2){
    
    LNode *pre = getIdxWithData(head, data);
    
    LNode *node = (LNode *)malloc(sizeof(LNode));
    node->next = pre->next;
    pre->next = node;
}

//将两个升序排列的链表 --》 合并成表链表C
void linkListMergae(LNode *headA, LNode *headB, LNode *headC) {
    
    //1.
    LNode *pa = headA->next;
    LNode *pb = headB->next;
    LNode *pc = headC;          //指向表c的最后一个节点
    
    //2.
    while (pa != NULL && pb != NULL) {
        if (pa->data <= pb->data) {
            
            pc->next = pa;
            pc = pc->next;
            pa = pa->next;
            
        }else {
            
            pc->next = pb;
            pc = pc->next;
            pb = pb->next;
        }
    }
    
    //3.
    pc->next = NULL;
    
    //4.1
    if (pa != NULL) {
        
        pc->next = pa;
    }
    
    //4.2
    if (pb != NULL) {
        pc->next = pb;
    }
}


//-----------------链栈--------------------
//1)链栈node
typedef struct LinkStackNode{
    Data data;
    struct LinkStackNode *pre;
}LinkStackNode;

//2)链栈 -- 主要就是一个top指针
LinkStackNode *top;

void push(LinkStackNode *top, Data data) {
    
    LinkStackNode *node = (LinkStackNode *)malloc(sizeof(LinkStackNode));
    node->data = data;
    
    node->pre = top;
    top = node;
}

int pop(LinkStackNode *top) {
    
    int data = top->data;
    top = top->pre;
    
    return data;
}

//-----------------链队列--------------------
typedef struct LinkQeueuNode{
    Data data;
    struct LinkQeueuNode *next;
}LinkQeueuNode;

//链队列
LinkQeueuNode *front, *rear;

void initQueue(LinkQeueuNode *front, LinkQeueuNode *rear){
    front = rear = NULL;
}

void insertQueue(LinkQeueuNode *rear, int data) {
    
    LinkQeueuNode *node = (LinkQeueuNode *)malloc(sizeof(LinkQeueuNode));
    node->data = data;
    
    node->next = front->next;
    front = node;
}

void popQueue(LinkQeueuNode *front){
    
    LinkQeueuNode *node = front;
    int data = node->data;
    
    front = front->next;
}

#define MAXSIZE 100
typedef struct String{
    char arr[MAXSIZE];
    int len;
}String;

void getNext(String *str, int next[]) {
    
    int i = 0, j = -1;
    next[0] = -1;
    
    while (i < str->len) {
        
        if (j == -1 && str->arr[i] == str->arr[j]) {
            i++;
            j++;
            next[i] = j;
            
        }else {
            j = next[j];
        }
    }
}











