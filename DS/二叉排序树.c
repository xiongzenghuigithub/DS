
#include <stdio.h>
#include <stdlib.h>

typedef struct BiTree {
    int id;
    struct BiTree * lchild;
    struct BiTree * rchild;
}BiTree;


/**根据值查找某一特定节点*/
BiTree * findNodeById(BiTree * root , int id)
{
    BiTree * result = NULL;
    if (root != NULL)
    {
        if (id < root->id)
        {
            result = findNodeById(root->lchild, id);
        
        }else if (id > root->id)
        {
            result = findNodeById(root->rchild, id);
        }else
        {
            result = root;
        }
    }
    return result;
}

/**找到某一值对应节点的 父节点 (注意: 只知道这个id的的节点的父节点是谁，但是不知道到底是父节点的左孩子or有孩子？) */
BiTree * findParantNode( BiTree * root, int id )
{
    BiTree * result = NULL;
    
    if (root != NULL)
    {
        
        if (id < root->id)
        {
            if (id == root->lchild->id)
            {
                result = root;
            }
            else if (id < root->lchild->id)
            {
                result = findParantNode(root->lchild, id);//root已经指向左孩子
                if (result == NULL)
                {
                    result = findParantNode(root->rchild, id);
                }
            }
            else if (id > root->lchild->id) {
                
            }
        }
        
        if (id > root->id)
        {
            if (id == root->rchild->id)
            {
                root = root->rchild;
            }
            else
            {
                result = findParantNode(root->rchild, id);//root已经指向右孩子
                if (result == NULL)
                {
                    result = findParantNode(root->rchild, id);
                }
            }
        }
    }
    
    return result;
}

/** 找到指定节点的 中序遍历下得 直接前驱 */
BiTree * getPreInOrderTraverse(BiTree * root)
{
    //前驱: 当前节点左子树中，最右边的孩子
    BiTree * result = root->lchild;
    
    while (result != NULL)
    {
        result = result->rchild;
    }
    
    return result;
}

/** 找到指定节点的 中序遍历下得 直接后继 */
BiTree * getNextInOrderTraverse(BiTree * root) {
    
    //后继: 当前节点右子树中，最左边的孩子
    BiTree * result = root->rchild;
    
    while (result != NULL) {
        result = result->lchild;
    }
    
    return result;
}

/**  删除某一个节点 */
typedef enum BOOL{
    FAILD = 0,
    SUCCESS
}BOOL;

BOOL deleteNode(BiTree * root , int nodeID) {//传入二叉排序树的根节点
    
    //1. 找到要删除顶点的父节点
    BiTree * parant = findParantNode(root, nodeID);
    
    //2. 找到要删除的顶点
    BiTree * node = findNodeById(root, nodeID);
    
    //3. 删除
    if (node == NULL) {
        printf("未找到顶点\n");
        return FAILD;
        
    }else {
        
        //情况一、待删除的节点为 ： 叶子节点
        if (node->lchild == NULL && node->rchild == NULL) {
            
            //叶子节点可能就是根节点
            if (parant == NULL) {//树的根节点的parant == NULL
                root = NULL;
                
            }else {
                
                //叶子是parant节点的 左孩子 or 右孩子
                if (node == parant->lchild) {
                    parant->lchild = NULL;
                }
                
                if (node == parant->rchild) {
                    parant->rchild = NULL;
                }
            }
        }
        //情况二、待删除的节点为 ： 只拥有左子树
        else if (node->lchild != NULL) {
            
            //1. 待删除节点为树的根节点
            if (parant == NULL) {
                root = node->lchild;
                
            }else {
                
                //2.1 删除节点是父节点的左孩子
                if (node == parant->lchild) {
                    parant->lchild = node->lchild;
                }
                
                //2.2 删除节点是父节点的由孩子
                if (node == parant->rchild) {
                    parant->rchild = node->lchild;
                }
            }
            
        }
        //情况三、待删除的节点为 ： 只拥有右子树
        else if (node->rchild != NULL) {
            
            if (parant == NULL) {
                root = node->rchild;
                
            }else {
                
                if (node == parant->lchild) {
                    parant->lchild = node->rchild;
                }
                
                if (node == parant->rchild) {
                    parant->lchild = node->rchild;
                }
            }
        }
        //情况四、待删除的节点为 ： 同时用用 左子树和右子树
        else {
            
            //1. 使用当前节点在中序遍历下得直接前驱节点id替换
            BiTree * pre = getPreInOrderTraverse(node);
            node->id = pre->id;
            
            //2. 
        }
        
        return SUCCESS;
    }
}


















