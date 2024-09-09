//
// Created by zhouyuqing on 2024/9/4.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_RECLISTSEARCH_H
#define DATASTRUCTUREBYLICHUNBAO_RECLISTSEARCH_H


typedef int KeyType;
typedef char InfoType;
typedef struct{
    KeyType key; //关键字
    InfoType data; //数据域
}RecType; //查找元素的类型

typedef struct{
    KeyType key; //KeyType为关键字类型
    int link; //指向对应块的起始下标
}IdxType; //索引元素


#endif //DATASTRUCTUREBYLICHUNBAO_RECLISTSEARCH_H
