//
// Created by zhouyuqing on 2024/9/8.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_HASHTABLECHAIN_H
#define DATASTRUCTUREBYLICHUNBAO_HASHTABLECHAIN_H

#include<malloc.h>
#include<stdio.h>

typedef int KeyType;
typedef char ElemType;

typedef struct node{
    KeyType key; //关键字域
    ElemType data; //数据域
    struct node *next; //下个节点指针
}NodeType; //单链表节点类型

typedef struct {
    NodeType *firstp; //队首点指针
}HashTableChain; //哈希表单元类型

//将关键字key插入到哈希表中
//p需要小于等于hashTable的长度
void insertHashTableChain(HashTableChain hashTable[],int &nums,
                          int p,KeyType key,ElemType data);

//创建哈希表
//p需要小于等于hashTable的长度
void createHashTableChain(HashTableChain hashTable[],int &nums,int lengthHashTable,
                          int p,KeyType keys[],ElemType datas[],int lengthKeys);

//删除算法
//p需要小于等于hashTable的长度
bool deleteHashTableChain(HashTableChain hashTable[],int &nums,
                          int p,KeyType key);

//在哈希表中搜索key节点
//p需要小于等于hashTable的长度
//节点的指针存储在resultNode中
bool searchHashTableChain(HashTableChain hashTable[],
                          int p,KeyType key,
                          NodeType *&resultNode);

//计算平均查找长度
//p需要小于等于hashTable的长度
//成功查找长度存入succAVL,失败查找长度存入unSuccAVL
void ASLHashTableChain(HashTableChain hashTable[],
                       int p,int lengthHashTable,
                       float &succAVL,float &unSuccAVL);

//展示哈希表所有元素
void displayHashTableChain(HashTableChain hashTable[],
                           int lengthHashTable);


#endif //DATASTRUCTUREBYLICHUNBAO_HASHTABLECHAIN_H

//使用案例
//#include"SearchStruct/HashTableChain/hashTableChain.h"
//
//int main(){
//    int lengthHashTable=10;
//    HashTableChain hashTable[lengthHashTable];
//
//    int lengthKeys=20;
//
//    KeyType keys[20]={19,23,17,190,8,
//                      21,20,83,43,25,
//                      92,67,45,34,89,
//                      44,37,63,28,49};
//
//    ElemType datas[20]={'a','b','c','d','e',
//                       'f','g','h','i','j',
//                       'k','l','m','n','o',
//                       'p','q','r','s','t'};
//
//    //position必须小于等于lengthHashTable
//    int position=10;
//
//    //创建哈希表
//    int nums=0;
//    createHashTableChain(hashTable,nums,lengthHashTable,position,keys,datas,lengthKeys);
//    printf("插入哈希表元素%d个\n",nums);
//    //展示哈希表
//    displayHashTableChain(hashTable,lengthHashTable);
//
//    printf("\n------------------------------------------------------------\n");
//
//    int key=190;
//    NodeType *tempNode= nullptr;
//    bool ret=searchHashTableChain(hashTable,position,key,tempNode);
//    if(ret){
//        printf("查找key:%d节点成功，节点key:%d,数据:%c\n",key,tempNode->key,tempNode->data);
//    }else{
//        printf("查询key:%d节点失败\n",key);
//    }
//
//    key=1911;
//    tempNode= nullptr;
//    ret=searchHashTableChain(hashTable,position,key,tempNode);
//    if(ret){
//        printf("查找key:%d节点成功，节点key:%d,数据:%c\n",key,tempNode->key,tempNode->data);
//    }else{
//        printf("查询key:%d节点失败\n",key);
//    }
//
//    key=190;
//    ret=deleteHashTableChain(hashTable,nums,position,key);
//    if(ret){
//        printf("删除key:%d节点成功\n",key);
//    }else{
//        printf("删除key:%d节点失败\n",key);
//    }
//
//    key=83;
//    ret=deleteHashTableChain(hashTable,nums,position,key);
//    if(ret){
//        printf("删除key:%d节点成功\n",key);
//    }else{
//        printf("删除key:%d节点失败\n",key);
//    }
//
//    key=43;
//    ret=deleteHashTableChain(hashTable,nums,position,key);
//    if(ret){
//        printf("删除key:%d节点成功\n",key);
//    }else{
//        printf("删除key:%d节点失败\n",key);
//    }
//
//    key=24;
//    ret=deleteHashTableChain(hashTable,nums,position,key);
//    if(ret){
//        printf("删除key:%d节点成功\n",key);
//    }else{
//        printf("删除key:%d节点失败\n",key);
//    }
//
//    key=25;
//    ret=deleteHashTableChain(hashTable,nums,position,key);
//    if(ret){
//        printf("删除key:%d节点成功\n",key);
//    }else{
//        printf("删除key:%d节点失败\n",key);
//    }
//
//    key=1912;
//    ret=deleteHashTableChain(hashTable,nums,position,key);
//    if(ret){
//        printf("删除key:%d节点成功\n",key);
//    }else{
//        printf("删除key:%d节点失败\n",key);
//    }
//
//    key=190;
//    tempNode= nullptr;
//    ret=searchHashTableChain(hashTable,position,key,tempNode);
//    if(ret){
//        printf("查找key:%d节点成功，节点key:%d,数据:%c\n",key,tempNode->key,tempNode->data);
//    }else{
//        printf("查询key:%d节点失败\n",key);
//    }
//
//    key=83;
//    tempNode= nullptr;
//    ret=searchHashTableChain(hashTable,position,key,tempNode);
//    if(ret){
//        printf("查找key:%d节点成功，节点key:%d,数据:%c\n",key,tempNode->key,tempNode->data);
//    }else{
//        printf("查询key:%d节点失败\n",key);
//    }
//
//    displayHashTableChain(hashTable,lengthHashTable);
//
//    printf("\n------------------------------------------------------------\n");
//
//    //获取平均查找长度
//    float succAVL=0,unSuccAVL=0;
//    ASLHashTableChain(hashTable,position,lengthHashTable,
//                      succAVL,unSuccAVL);
//    printf("查找成功平均查找长度:%f  ,  查找失败平均查找长度:%f\n",
//           succAVL,unSuccAVL);
//
//    return 0;
//}