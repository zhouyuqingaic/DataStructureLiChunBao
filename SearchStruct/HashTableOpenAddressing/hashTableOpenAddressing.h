//
// Created by zhouyuqing on 2024/9/7.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_HASHTABLEOPENADDRESSING_H
#define DATASTRUCTUREBYLICHUNBAO_HASHTABLEOPENADDRESSING_H

#include"stdio.h"

#define NULLKEY -1 //定义空关键字
#define DELKEY -2 //定义被删关键字

typedef int KeyType; //关键字类型

typedef struct{
    KeyType key; //关键字域
    int count; //探测次数域
}HashTableOpenAddressing; //哈希表单元类型


//向哈希表中插入关键字key
//lengthHashTable必须很大
//p必须小于等于lengthHashTable,放置出现越界
//nums为表中关键字个数
void insertHashTableOpenAddressing(HashTableOpenAddressing hashTable[],
                                   int &nums,int p,
                                   int lengthHashTable,KeyType key);

//创建哈希表
//lengthHashTable必须远大于lengthKeys
//nums为表中关键字个数
//p必须小于等于lengthHashTable,放置出现越界
void createHashTableOpenAddressing(HashTableOpenAddressing hashTable[],int lengthHashTable,
                                   KeyType keys[],int lengthKeys,int p,int &nums);

//删除哈希表元素
//nums为表中关键字个数
bool deleteHashTableOpenAddressing(HashTableOpenAddressing hashTable[],int &nums,
                                   int lengthHashTable,int p,KeyType key);

//查找算法
bool searchHashTableOpenAddressing(HashTableOpenAddressing hashTable[],int lengthHashTable,
                                   int p,KeyType key,
                                   HashTableOpenAddressing &node);

//求平均查找长度
//nums为非空元素个数
//通过asl获取平均查找长度
void ASLHashTableOpenAddressing(HashTableOpenAddressing hashTable[],int nums,
                                int lengthHashTable,int p,
                                float &succAVL,float &unSuccAVL);

//展示哈希表
void displayHashTableOpenAddressing(HashTableOpenAddressing hashTable[],
                                    int lengthHashTable);

#endif //DATASTRUCTUREBYLICHUNBAO_HASHTABLEOPENADDRESSING_H

//使用案例
//#include"SearchStruct/HashTableOpenAddressing/hashTableOpenAddressing.h"
//
//int main(){
//    int lengthHashTable=1000;
//    HashTableOpenAddressing hashTable[1000];
//
//    int lengthKeys=20;
//    KeyType keys[20]={19,23,17,190,8,
//                      21,20,83,43,25,
//                      92,67,45,34,89,
//                      44,37,63,28,49};
//
//    int position=10;
//
//    //创建哈希表
//    int nums=0;
//    createHashTableOpenAddressing(hashTable,lengthHashTable,keys,lengthKeys,
//                                  position,nums);
//    printf("哈希表构建成功，共插入元素%d个\n",nums);
//
//    //展示哈希表
//    displayHashTableOpenAddressing(hashTable,lengthHashTable);
//    printf("------------------------------------------------------------------\n");
//
//    KeyType key=1996;
//
//    //插入
//    insertHashTableOpenAddressing(hashTable,nums,position,lengthHashTable,key);
//    //展示哈希表
//    displayHashTableOpenAddressing(hashTable,lengthHashTable);
//    printf("------------------------------------------------------------------\n");
//
//    //查找元素
//    HashTableOpenAddressing tempNode;
//    bool ret=searchHashTableOpenAddressing(hashTable,lengthHashTable,
//                                           position,key,tempNode);
//    if(ret){
//        printf("查询成功,找到key:%d , count=%d\n",tempNode.key,tempNode.count);
//    }else{
//        printf("查询失败,么有找到key:%d\n",key);
//    }
//
//    printf("------------------------------------------------------------------\n");
//    key=502;
//    ret=searchHashTableOpenAddressing(hashTable,lengthHashTable,
//                                      position,key,tempNode);
//    if(ret){
//        printf("查询成功,找到key:%d , count=%d\n",tempNode.key,tempNode.count);
//    }else{
//        printf("查询失败,么有找到key:%d\n",key);
//    }
//
//
//    printf("------------------------------------------------------------------\n");
//    key=1996;
//    ret= deleteHashTableOpenAddressing(hashTable,nums,lengthHashTable,position,key);
//    if(ret){
//        printf("删除成功,key:%d\n",key);
//    }else{
//        printf("删除失败,么有找到key:%d\n",key);
//    }
//
//    key=43;
//    ret= deleteHashTableOpenAddressing(hashTable,nums,lengthHashTable,position,key);
//    if(ret){
//        printf("删除成功,key:%d\n",key);
//    }else{
//        printf("删除失败,么有找到key:%d\n",key);
//    }
//
//    key=502;
//    ret= deleteHashTableOpenAddressing(hashTable,nums,lengthHashTable,position,key);
//    if(ret){
//        printf("删除成功,key:%d\n",key);
//    }else{
//        printf("删除失败,么有找到key:%d\n",key);
//    }
//
//    //展示哈希表
//    displayHashTableOpenAddressing(hashTable,lengthHashTable);
//    printf("------------------------------------------------------------------\n");
//
//    //成功平均查找长度
//    float succAVL;
//    //失败平均查找成都
//    float unSuccAVL;
//    ASLHashTableOpenAddressing(hashTable,nums,lengthHashTable,
//                               position,succAVL,unSuccAVL);
//    printf("成功平均查找长度:%f , 失败平均查找长度:%f\n",succAVL,unSuccAVL);
//
//    return 0;
//}
