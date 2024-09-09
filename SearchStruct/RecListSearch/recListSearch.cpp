//
// Created by zhouyuqing on 2024/9/4.
//

#include"recListSearch.h"

//获取k指向的节点在RecType列表中的位置
//成功返回位置,失败返回-1(从0开始计数)
int seqSearchRecType(RecType R[],int n,KeyType k){
    int i=0;
    while(i<n && R[i].key!=k) //从表头往后找
        i++;
    if(i==n) //未找到返回-1
        return -1;
    else //找到返回坐标
        return i;
}

//获取k指向的节点在RecType列表中的位置
//成功返回位置,失败返回-1(从0开始计数)
int seqSearch1RecType(RecType R[],int n,KeyType k){
    int i=0;
    R[n].key=k; //设置哨兵
    while(R[i].key!=k) //从表头往后找
        i++;
    if(i==n) //未找到返回-1
        return -1;
    else //找到返回下标
        return i;
}

//折半查找
//RLength为R顺序表长度
int binarySearchRecType(RecType R[],int RLength,KeyType k){
    int low=0,high=RLength-1,mid; //获取上限和下限下标
    while(low<=high){
        mid=(low+high)/2; //折半查找比较位置
        if(k==R[mid].key)
            return mid; //找到k位置，直接返回下标
        if(k<R[mid].key) //继续在R[low..mid-1]中查找
            high=mid-1;
        else //k>R[mid].key 继续在R[mid+1..high]中查找
            low=mid+1;
    }
    return -1; //未找到时返回-1(查找失败)
}




