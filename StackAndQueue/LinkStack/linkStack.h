//
// Created by zhouyuqing on 2024/8/8.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_LINKSTACK_H
#define DATASTRUCTUREBYLICHUNBAO_LINKSTACK_H

#include "malloc.h"

typedef int ElemType;

typedef struct LinkStackNode{
    ElemType data; //数据域
    struct LinkStackNode *next; //指针域
}LinkStackNode; //链栈节点

//初始化栈
void initLinkStack(LinkStackNode *&LinkSt);
//销毁栈
void destroyLinkStack(LinkStackNode *&LinkSt);
//判断栈空
bool IsEmptyLinkStack(const LinkStackNode *LinkSt);
//e元素入栈
bool PushLinkStack(LinkStackNode *&LinkSt,ElemType e);
//e元素出栈
bool PopLinkStack(LinkStackNode *&LinkSt,ElemType &e);
//获取栈顶
bool getTopLinkStack(LinkStackNode *LinkSt,ElemType &e);




#endif //DATASTRUCTUREBYLICHUNBAO_LINKSTACK_H

//使用案例
//int main(int argc,char *args[]) {
//    LinkStackNode *LinkSt = nullptr;
//    initLinkStack(LinkSt);
//    int e;
//    bool ret;
//
//    printf("Is empty:%d\n", IsEmptyLinkStack(LinkSt));
//    ret= getTopLinkStack(LinkSt,e);
//
//    if (ret == true) {
//        printf("Top element:%d\n", e);
//    } else {
//        printf("Get Top Element Fail\n");
//    }
//
//    printf("----------------------------------\n");
//
//    for (int i = 0; i < 10; i++)
//        PushLinkStack(LinkSt, i + 1900);
//
//    printf("Is empty:%d\n", IsEmptyLinkStack(LinkSt));
//    ret = getTopLinkStack(LinkSt, e);
//    if (ret == true) {
//        printf("Top element:%d\n", e);
//    } else {
//        printf("Get Top Element Fail\n");
//    }
//
//    while(!IsEmptyLinkStack(LinkSt)){
//        ret=PopLinkStack(LinkSt,e);
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
