//
// Created by zhouyuqing on 2024/8/8.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_DSTACK_H
#define DATASTRUCTUREBYLICHUNBAO_DSTACK_H

#include"malloc.h"

#define MaxSize 10

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //栈空间
    int top_0,top_1; //0号栈与1号栈指针
}DStack; //共享栈

//初始化共享栈
void initDStack(DStack *&Ds);
//销毁共享栈
void destroyDStack(DStack *&Ds);
//判断stackNum号栈空
bool dStackIsEmpty(const DStack *Ds,int stackNum);
//stackNum号栈入栈
bool pushDStack(DStack *&Ds,ElemType e,int stackNum);
//stackNum号栈出栈
bool popDStack(DStack *&Ds,ElemType &e,int stackNum);
//获取stackNum号栈顶元素
bool getTopDStack(DStack *Ds,ElemType &e,int stackNum);



#endif //DATASTRUCTUREBYLICHUNBAO_DSTACK_H
