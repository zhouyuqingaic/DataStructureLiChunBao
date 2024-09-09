//
// Created by zhouyuqing on 2024/9/7.
//

#include"hashTableOpenAddressing.h"

//向哈希表中插入关键字key
//lengthHashTable必须很大
//p必须小于等于lengthHashTable,放置出现越界
//nums为表中关键字个数
void insertHashTableOpenAddressing(HashTableOpenAddressing hashTable[],
                                   int &nums,int p,
                                   int lengthHashTable,KeyType key){
    int addr=key%p; //计算哈希值
    if(hashTable[addr].key==NULLKEY || hashTable[addr].key==DELKEY){
        hashTable[addr].key=key; //addr位置上的元素为空或者已经被删除，则元素可以直接放到addr位置
        hashTable[addr].count=1; //探测次数为1
    }else{
        //addr上有元素，继续向后探测
        int i=1;
        do{
            addr=(addr+1)%lengthHashTable;
            i++;
        }while(hashTable[addr].key!=NULLKEY && hashTable[addr].key!=DELKEY);
        //设置元素为key
        hashTable[addr].key=key;
        //设置探测次数
        hashTable[addr].count=i;
    }
    //元素个数+1
    nums++;
}

//创建哈希表
//lengthHashTable必须远大于lengthKeys
//nums为表中关键字个数
//p必须小于等于lengthHashTable,放置出现越界
void createHashTableOpenAddressing(HashTableOpenAddressing hashTable[],int lengthHashTable,
                                   KeyType keys[],int lengthKeys,int p,int &nums) {
    //初始化哈希表
    for(int i=0;i<lengthHashTable;i++){
        hashTable[i].key=NULLKEY;
        hashTable[i].count=0;
    }
    //哈希表中总元素个数从0开始递增
    nums=0;
    //逐个将keys中的元素逐个插入哈希表
    for(int i=0;i<lengthKeys;i++) {
        insertHashTableOpenAddressing(hashTable, nums, p,
                                      lengthHashTable, keys[i]);
    }
}

//删除哈希表元素
//nums为表中关键字个数
bool deleteHashTableOpenAddressing(HashTableOpenAddressing hashTable[],int &nums,int lengthHashTable,int p,KeyType key){
    int addr=key%p; //计算哈希值
    while(hashTable[addr].key!=NULLKEY && hashTable[addr].key!=key)
        addr=(addr+1)%lengthHashTable; //线性探测，找到键为key的元素
    if(hashTable[addr].key==key){
        //如果找到目标键,则将目标位置标记为已删除
        hashTable[addr].key=DELKEY;
        return true;
    }else
        //查找失败
        return false;
}

//查找算法
bool searchHashTableOpenAddressing(HashTableOpenAddressing hashTable[],int lengthHashTable,
                                   int p,KeyType key,
                                   HashTableOpenAddressing &node){
    int i=1;
    int addr=key%p;
    //线性探测键为key的哈希表元素
    while(hashTable[addr].key!=NULLKEY && hashTable[addr].key!=key){
        i++;
        addr=(addr+1)%lengthHashTable;
    }
    if(hashTable[addr].key==key) {
        printf("成功:关键字%d,比较次数:%d次\n", key, i);
        node.key=hashTable[addr].key;
        node.count=hashTable[addr].count;
        return true;
    }else{
        printf("失败:关键字%d,比较次数:%d次\n", key, i);
        return false;
    }
}

//求平均查找长度
//nums为非空元素个数
//通过asl获取平均查找长度
void ASLHashTableOpenAddressing(HashTableOpenAddressing hashTable[],int nums,
                                int lengthHashTable,int p,
                                float &succAVL,float &unSuccAVL){

    int succ=0; //记录查询成功次数
    int unsucc=0; //记录查询不成功次数
    //遍历
    for(int i=0;i<lengthHashTable;i++) {
        if (hashTable[i].key != NULLKEY)
            succ += hashTable[i].count; //记录查找成功次数
    }

    int s=0;
    int j;
    for(int i=0;i<lengthHashTable;i++){
        s=1;
        j=i;
        //累积从当前位置开始的查询到空位置比次数
        while(hashTable[j].key!=NULLKEY){
            s++;
            j=(j+1)%lengthHashTable;
        }
        unsucc+=s;
    }

    //计算成功平均查找长度和失败平均查找长度
    succAVL=succ/nums;
    unSuccAVL=unsucc/lengthHashTable;
}


//展示哈希表
void displayHashTableOpenAddressing(HashTableOpenAddressing hashTable[],
                                    int lengthHashTable){
    //展示哈希表
    printf("展示所有元素:\n");
    for(int i=0;i<lengthHashTable;i++)
        if(hashTable[i].key!=NULLKEY && hashTable[i].key!=DELKEY)
            printf("    当前节点index:%d , key:%d , count:%d\n",
                   i,hashTable[i].key,hashTable[i].count);
}










