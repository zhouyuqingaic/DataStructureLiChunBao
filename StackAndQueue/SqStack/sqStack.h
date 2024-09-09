//
// Created by zhouyuqing on 2024/8/8.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_SQSTACK_H
#define DATASTRUCTUREBYLICHUNBAO_SQSTACK_H

#include"malloc.h"

#define MaxSize 100

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //栈空间
    int top; //栈顶指针
}SqStack; //顺序栈

//初始化栈
void initStack(SqStack *&S);
//销毁栈
void destroyStack(SqStack *&S);
//判断栈空
bool stackEmpty(const SqStack *S);
//入栈
bool push(SqStack *&S,ElemType e);
//出栈
bool pop(SqStack *&S,ElemType &e);
//获取栈顶元素
bool getTop(const SqStack *S,ElemType &e);


#endif //DATASTRUCTUREBYLICHUNBAO_SQSTACK_H

//使用案例
//int main(int argc,char *args[]) {
//    SqStack *S = nullptr;
//    initStack(S);
//    int e;
//    bool ret;
//    printf("Is empty:%d\n", stackEmpty(S));
//    ret = getTop(S, e);
//    if (ret == true) {
//        printf("Top empty:%d\n", e);
//    } else {
//        printf("Get Top Element Fail\n");
//    }
//
//    printf("----------------------------------\n");
//
//    for (int i = 0; i < MaxSize; i++)
//        push(S, i + 1900);
//
//    printf("Is empty:%d\n", stackEmpty(S));
//    ret = getTop(S, e);
//    if (ret == true) {
//        printf("Top empty:%d\n", e);
//    } else {
//        printf("Get Top Element Fail\n");
//    }
//
//    while(!stackEmpty(S)){
//        ret=pop(S,e);
//        if (ret == true) {
//            printf("Pop Elemnet:%d  ", e);
//        } else {
//            printf("Pop Element Fail\n");
//        }
//    }
//    printf("\n");
//
//
//}
