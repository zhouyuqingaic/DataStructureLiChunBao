//
// Created by zhouyuqing on 2024/9/8.
//

#include "hashTableChain.h"

//将关键字key插入到哈希表中
//p需要小于等于hashTable的长度
void insertHashTableChain(HashTableChain hashTable[],int &nums,
                          int p,KeyType key,ElemType data){
    //计算地址
    int addr=key%p;
    //创建单链表节点
    NodeType *tempNode=(NodeType *)malloc(sizeof(NodeType));
    tempNode->key=key;
    tempNode->data=data;
    tempNode->next= nullptr;
    //节点加入哈希表
    if(hashTable[addr].firstp== nullptr)
        hashTable[addr].firstp=tempNode; //为当前哈希表单元的第一个元素
    else{
        //当前哈希表单元不空
        tempNode->next=hashTable[addr].firstp; //用头插法插入当前哈希表单元
        hashTable[addr].firstp=tempNode;
    }
    //节点个数+1
    nums++;
}

//创建哈希表
//p需要小于等于hashTable的长度
void createHashTableChain(HashTableChain hashTable[],int &nums,int lengthHashTable,
                          int p,KeyType keys[],ElemType datas[],int lengthKeys){

    //初始化哈希表
    for(int i=0;i<lengthHashTable;i++)
        hashTable[i].firstp= nullptr;
    //重置节点个数
    nums=0;
    //将keys关键字列表中的每个元素都插入哈希表中
    for(int i=0;i<lengthKeys;i++) {
        insertHashTableChain(hashTable, nums,
                             p, keys[i], datas[i]);
//        printf("current--->key:%d,data=%c\n",keys[i],datas[i]);
    }
}

//删除算法
//p需要小于等于hashTable的长度
bool deleteHashTableChain(HashTableChain hashTable[],int &nums,
                          int p,KeyType key){
    //计算地址
    int addr=key%p;
    //从地址的第一个节点开始查找
    NodeType *currentNode= hashTable[addr].firstp;
    NodeType *preNode= nullptr;
    if(currentNode== nullptr) //key节点不存在，删除失败
        return false;
    if(currentNode->key==key){ //第一个链表头节点就是key指向的节点
        hashTable[addr].firstp=currentNode->next; //更新链表头
        free(currentNode); //释放目标几点
        nums--; //减少节点数
        return true; //删除成功
    }
    //第一个链表头节点 不为key指向的节点时
    preNode=currentNode;
    currentNode=currentNode->next;
    //循环查找key节点
    while(currentNode!= nullptr){
        if(currentNode->key==key)
            break;
        //更新父节点与当前节点
        preNode=currentNode;
        currentNode=currentNode->next;
    }
    if(currentNode!= nullptr){
        //找到key节点
        preNode->next=currentNode->next; //将currentNode从链表中移除
        free(currentNode); //释放节点
        nums--; //总数-1
        return true;
    }else{
        //没有找到key节点
        return false;
    }
}

//在哈希表中搜索key节点
//p需要小于等于hashTable的长度
//节点的指针存储在resultNode中
bool searchHashTableChain(HashTableChain hashTable[],
                          int p,KeyType key,
                          NodeType *&resultNode){
    int addr=key%p; //计算地址
    //从目标地址的第一个链表节点开始遍历，直到找到key节点
    NodeType *currentNode=hashTable[addr].firstp;
    while(currentNode!= nullptr){
        if(currentNode->key==key)
            break; //找到目标节点退出循环
        currentNode=currentNode->next;
    }
    if(currentNode!= nullptr){
        //查找成功找到节点
        resultNode=currentNode;
        return true;
    }else
        return false; //查找失败
}

//计算平均查找长度
//p需要小于等于hashTable的长度
//成功查找长度存入succAVL,失败查找长度存入unSuccAVL
void ASLHashTableChain(HashTableChain hashTable[],
                       int nums,int lengthHashTable,
                       float &succAVL,float &unSuccAVL){
    //记录查询成功与查询失败的比较次数
    int succ=0,unsucc=0;
    NodeType *currentNode= nullptr;
    //扫描哈希表所有地址
    int s=0;
    for(int i=0;i<lengthHashTable;i++){
        s=0;
        //获取单链表表头，并访问链表中所有节点
        currentNode=hashTable[i].firstp;
        while(currentNode!= nullptr){
            currentNode=currentNode->next;
            s++; //s记录当前节点是对应单链表的第几个节点
            succ+=s; //累积成功比较次数
        }
        unsucc+=s; //累积不成功比较次数
    }
    //计算成功比较次数和不成功比较次数
    succAVL=(float)succ/(float)nums;
    unSuccAVL=(float)unsucc/(float)lengthHashTable;
}


//展示哈希表所有元素
void displayHashTableChain(HashTableChain hashTable[],int lengthHashTable){
    printf("\n|-------------All Nodes------------------|\n");
    //遍历哈希表所有有安苏
    NodeType *currentNode= nullptr;
    for(int i=0;i<lengthHashTable;i++){
        //获取链表表头，并访问链表中所有节点
        currentNode=hashTable[i].firstp;
        while(currentNode!= nullptr){
            printf("        currentNode,key:%d , data:%c\n",
                   currentNode->key,currentNode->data);
            currentNode=currentNode->next;
        }
    }

    printf("|-------------_________------------------|\n");
}



