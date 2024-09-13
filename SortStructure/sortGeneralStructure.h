//
// Created by zhouyuqing on 2024/9/11.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_SORTGENERALSTRUCTURE_H
#define DATASTRUCTUREBYLICHUNBAO_SORTGENERALSTRUCTURE_H

#include<stdio.h>

//定义类型
typedef int KeyType;
typedef char InfoType;

typedef struct{
    KeyType key; //元素类型
    InfoType data; //数据类型
}RecType; //排序结构元素

//展示rect中所有元素
void displayRecTypeList(RecType rects[],int rectsLength);

#endif //DATASTRUCTUREBYLICHUNBAO_SORTGENERALSTRUCTURE_H
