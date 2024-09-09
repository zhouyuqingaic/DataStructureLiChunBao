//
// Created by zhouyuqing on 2024/9/4.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_BINARYSEARCHTREE_H
#define DATASTRUCTUREBYLICHUNBAO_BINARYSEARCHTREE_H

#include"malloc.h"

typedef int KeyType;
typedef char InfoType;

//二叉排序树节点
typedef struct node{
    KeyType key;
    InfoType data;
    struct node *lchild,*rchild;
}BSTNode;

//插入BST树
//在二叉排序树中插入一个关键字为key,数据为data的节点.
// 插入成功返回true,插入失败返回false
bool insertBST(BSTNode *&Bt,KeyType key,InfoType data);

//通过keyArr和dataArr构建BST二叉排序树
//length为keyArr与dataArr的长度
BSTNode *createBST(KeyType keyArr[],InfoType dataArr[],int length);

//二叉排序树查找
//找到后返回节点，找不到返回nullptr
BSTNode *searchBST(BSTNode *Bt,KeyType key);

//返回一棵二叉排序树中的最大结点
BSTNode *maxNodeBST(BSTNode *Bt);

//返回一棵二叉排序树中的最小结点
BSTNode *minNodeBST(BSTNode *Bt);

//删除键为key的节点
bool deleteNodeBST(BSTNode *&Bt,KeyType key);


#endif //DATASTRUCTUREBYLICHUNBAO_BINARYSEARCHTREE_H

//使用案例
//#include"SearchStruct/BinarySearchTree/binarySearchTree.h"
//
//
//int main(){
//    //测试二叉排序树
//
//    //创建数据列表
//    KeyType keyList[10]={
//            4,6,3,10,5,1,8,9,2,7
//    };
//    InfoType infoList[10]={
//            'a','b','c','d','e','f','g','h','i','j'
//    };
//
//    //创建二叉树
//    BSTNode *Bt=createBST(keyList,infoList,10);
//
//    //展示所有节点
//    printf("\n-----展示所有节点-----\n");
//    for(int key=0;key<=11;key++) {
//        BSTNode *targetNode = searchBST(Bt, key);
//        if (targetNode != nullptr)
//            printf("key:%d,data:%c\n", key, targetNode->data);
//        else
//            printf("查找%d节点失败\n", key);
//    }
//
//    //获取key最大的节点
//    BSTNode *maxNode= maxNodeBST(Bt);
//    printf("key最大节点:key:%d,data:%c\n", maxNode->key, maxNode->data);
//
//    //获取key最小的节点
//    BSTNode *minNode= minNodeBST(Bt);
//    printf("key最小节点:key:%d,data:%c\n",minNode->key,minNode->data);
//
//    printf("\n--------------------------------------------------------\n");
//
//    int key=4;
//    bool ret=deleteNodeBST(Bt,key);
//    if(ret){
//        printf("删除节点%d成功\n",key);
//        BSTNode *targetNode = searchBST(Bt, key);
//        if (targetNode != nullptr)
//            printf("key:%d,data:%c\n", key, targetNode->data);
//        else
//            printf("查找%d节点失败\n", key);
//    }else{
//        printf("删除节点%d失败\n",key);
//    }
//
//    key=8;
//    ret=deleteNodeBST(Bt,key);
//    if(ret){
//        printf("删除节点%d成功\n",key);
//        BSTNode *targetNode = searchBST(Bt, key);
//        if (targetNode != nullptr)
//            printf("key:%d,data:%c\n", key, targetNode->data);
//        else
//            printf("查找%d节点失败\n", key);
//    }else{
//        printf("删除节点%d失败\n",key);
//    }
//
//    key=9;
//    ret=deleteNodeBST(Bt,key);
//    if(ret){
//        printf("删除节点%d成功\n",key);
//        BSTNode *targetNode = searchBST(Bt, key);
//        if (targetNode != nullptr)
//            printf("key:%d,data:%c\n", key, targetNode->data);
//        else
//            printf("查找%d节点失败\n", key);
//    }else{
//        printf("删除节点%d失败\n",key);
//    }
//
//    //展示所有节点
//    printf("\n-----展示所有节点-----\n");
//    for(int key=0;key<=11;key++) {
//        BSTNode *targetNode = searchBST(Bt, key);
//        if (targetNode != nullptr)
//            printf("key:%d,data:%c\n", key, targetNode->data);
//        else
//            printf("查找%d节点失败\n", key);
//    }
//
//
//    printf("\n-----清空所有节点-----\n");
//    for(int key=0;key<=11;key++) {
//        printf("\n|----------------------------------|\n");
//        ret=deleteNodeBST(Bt,key);
//        if(ret){
//            printf("删除节点%d成功\n",key);
//            BSTNode *targetNode = searchBST(Bt, key);
//            if (targetNode != nullptr)
//                printf("key:%d,data:%c\n", key, targetNode->data);
//            else
//                printf("查找%d节点失败\n", key);
//        }else{
//            printf("删除节点%d失败\n",key);
//        }
//        printf("|——————————————————————————————————|\n");
//    }
//
//    if(Bt== nullptr)
//        printf(">>>>>>>>>>二叉排序树清空成功\n");
//    else
//        printf(">>>>>>>>>>二叉排序树清空失败\n");
//
//
//    return 0;
//}

