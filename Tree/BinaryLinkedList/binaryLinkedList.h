//
// Created by zhouyuqing on 2024/8/28.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_BINARYLINKEDLIST_H
#define DATASTRUCTUREBYLICHUNBAO_BINARYLINKEDLIST_H

#include"malloc.h"

typedef int ElemType;

typedef struct BTNode{
    ElemType data; //节点数据域
    struct BTNode *lchild; //左孩子
    struct BTNode *rchild; //右孩子
}BTNode; //二叉树节点

#define MaxSize 10000

//st数组作为顺序栈
void createBTree(BTNode *&Bt,char *str);

//销毁二叉树
void destroyBTree(BTNode *&Bt);

//查找节点
BTNode *findNode(BTNode *&Bt,ElemType x);

//输出二叉树,按照构造用字符串的样式
void displayBTree(BTNode *Bt);

//获取二叉树元素个数
void numberOfNodesBTree(BTNode *Bt,int &length);

//获取二叉树元素个数
int nodesOfBTree(BTNode *Bt);

//先序遍历二叉树，遍历结果存入result中,resultLength为结果数组长度
void preOrderBTree(BTNode *Bt,BTNode *result[],int &resultLength);

//中序遍历二叉树，遍历结果存入result中,resultLength为结果数组长度
void inOrderBTree(BTNode *Bt,BTNode *result[],int &resultLength);

//后序遍历二叉树，遍历结果存入result中,resultLength为结果数组长度
void postOrderBTree(BTNode *Bt,BTNode *result[],int &resultLength);

//显示叶子节点
void displayLeafBTree(BTNode *Bt);

//显示值为x节点在二叉树中所在层次，如果不存在，则层次为0
//h为当前节点的深度,传入为1
int levelBTree(BTNode *Bt,ElemType x,int h);

//判断两棵树形状是否相似
bool likeBTree(BTNode *Bt1,BTNode *Bt2);

//求k的节点个数，h用于指出当前Bt所处的层号，n用于累计当前层的节点个数
//使用是时候 n=0,h=1,k为指定的行数
void lNodeNumBTree(BTNode *Bt,int h,int k,int &n);

//输出值为x的节点所有祖先节点
bool ancestorBTree(BTNode *Bt,ElemType x);

typedef struct SqQueue_BTree{
    BTNode *data[MaxSize]; //存放队中节点
    int front,rear; //队头和队尾指针
}SqQueue_BTree; //用于层次遍历的顺序队列

//层次遍历Bt树,遍历结果存入result中,resultLength为结果串长度
//调用时result为空，resultLength为0
bool levelOrderBTree(BTNode *Bt,BTNode *result[],int &resultLength);

//创建二叉树，通过先序遍历序列和中序遍历序列
//preResultStr为二叉树的先序遍历序列字符串
//inResultStr为二叉树的中序遍历序列字符串
//n遍历序列的字符串长度
BTNode *createBTreeFromPreOrderAndInOrder(char *preResultStr,char *inResultStr,int n);


#endif //DATASTRUCTUREBYLICHUNBAO_BINARYLINKEDLIST_H

////使用案例
//#include"Tree/BinaryLinkedList/binaryLinkedList.h"
//
//int main(){
//    //创建二叉树
//    char *treeStr="A(B,C(D(F,G),E))";
//    BTNode *Bt= nullptr;
//    createBTree(Bt,treeStr);
//    //展示二叉树
//    displayBTree(Bt);
//    printf("\n");
//    //二叉树元素个数
//    int nums= nodesOfBTree(Bt);
//    printf("节点个数:%d\n",nums);
//
//    printf("1----------------------------------------------------\n");
//
//    //创建二叉树2
//    treeStr="1(2,3(4(6,7),5))";
//    BTNode *Bt_2=nullptr;
//    createBTree(Bt_2,treeStr);
//    //展示二叉树
//    displayBTree(Bt_2);
//    printf("\n");
//    //二叉树元素个数
//    nums= nodesOfBTree(Bt_2);
//    printf("节点个数:%d\n",nums);
//
//    printf("2----------------------------------------------------\n");
//
//    //创建二叉树3
//    treeStr="1(2,3(4,5))";
//    BTNode *Bt_3=nullptr;
//    createBTree(Bt_3,treeStr);
//    //展示二叉树
//    displayBTree(Bt_3);
//    printf("\n");
//    //二叉树元素个数
//    nums= nodesOfBTree(Bt_3);
//    printf("节点个数:%d\n",nums);
//
//    printf("3----------------------------------------------------\n");
//
//    printf("likeBTree(Bt,Bt_2):%d\n", likeBTree(Bt,Bt_2));
//    printf("likeBTree(Bt,Bt_3):%d\n", likeBTree(Bt,Bt_3));
//
//    printf("4----------------------------------------------------\n");
//
//    BTNode *result[10000];
//    int resultLength=0;
//    bool ret=levelOrderBTree(Bt,result,resultLength);
//    if(ret==true) {
//        for (int i = 0; i < resultLength; i++)
//            printf("%c ", result[i]->data);
//        printf("\n");
//    }
//
//    resultLength=0;
//    ret= levelOrderBTree(Bt_2,result,resultLength);
//    if(ret==true) {
//        for (int i = 0; i < resultLength; i++)
//            printf("%c ", result[i]->data);
//        printf("\n");
//    }
//
//    resultLength=0;
//    ret= levelOrderBTree(Bt_3,result,resultLength);
//    if(ret==true) {
//        for (int i = 0; i < resultLength; i++)
//            printf("%c ", result[i]->data);
//        printf("\n");
//    }
//
//    printf("5----------------------------------------------------\n");
//
//    ret= ancestorBTree(Bt,'F');
//    if(ret== false)
//        printf("\nBt树输出%c的祖先节点失败\n",'F');
//    else
//        printf("\nBt树输出%c的祖先节点成功\n",'F');
//
//    ret= ancestorBTree(Bt_2,'F');
//    if(ret== false)
//        printf("\nBt_2树输出%c的祖先节点失败\n",'F');
//    else
//        printf("\nBt_2树输出%c的祖先节点成功\n",'F');
//
//    printf("6----------------------------------------------------\n");
//
//    BTNode *preResult[MaxSize];
//    char preResultStr[MaxSize];
//    int preResultLength=0;
//
//    BTNode *inResult[MaxSize];
//    char inResultStr[MaxSize];
//    int inResultLength=0;
//
//    BTNode *postResult[MaxSize];
//    char postResultStr[MaxSize];
//    int postResultLength=0;
//
//    char *current= nullptr;
//
//    //获取中序，先序，后续序列
//    printf("\n");
//    preOrderBTree(Bt,preResult,preResultLength);
//    for(int i=0;i<preResultLength;i++){
//        *(preResultStr+i) = (char)(preResult[i]->data);
////        printf("%c ",*(preResultStr+i));
//    }
//    printf("\n");
//
//
//    printf("\n");
//    inOrderBTree(Bt,inResult,inResultLength);
//    for(int i=0;i<inResultLength;i++) {
//        *(inResultStr + i) = (char) (inResult[i]->data);
////        printf("%c ",*(inResultStr + i));
//    }
//    printf("\n");
//
//    printf("\n");
//    postOrderBTree(Bt,postResult,postResultLength);
//    for(int i=0;i<postResultLength;i++) {
//        *(postResultStr + i) = (char) (postResult[i]->data);
////        printf("%c ",*(postResultStr + i));
//    }
//    printf("\n");
//
//    BTNode *Bt_Copy_1=createBTreeFromPreOrderAndInOrder(
//            preResultStr,inResultStr,inResultLength);
//
//    BTNode *Bt_Copy_2= createBTreeFromPreOrderAndInOrder(
//            postResultStr,inResultStr,inResultLength);
//
//    displayBTree(Bt);
//    printf("\n");
//    displayBTree(Bt_Copy_1);
//    printf("\n");
//    displayBTree(Bt_Copy_1);
//    printf("\n");
//
//    printf("7----------------------------------------------------\n");
//
//    destroyBTree(Bt);
//    destroyBTree(Bt_2);
//    destroyBTree(Bt_3);
//
//    if(Bt== nullptr || Bt_2== nullptr || Bt_3== nullptr)
//        printf("释放树成功\n");
//    else
//        printf("释放树失败\n");
//
//    return 0;
//}
//