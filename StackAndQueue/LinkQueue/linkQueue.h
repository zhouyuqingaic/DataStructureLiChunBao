//
// Created by zhouyuqing on 2024/8/12.
//I will spend my life showing you how much I love you.
//李琳同学
//

#ifndef DATASTRUCTUREBYLICHUNBAO_LINKQUEUE_H
#define DATASTRUCTUREBYLICHUNBAO_LINKQUEUE_H

#include"malloc.h"

typedef int ElemType;

typedef struct qnode{
    ElemType data; //数据域
    struct qnode *next; //下一个节点
}LinkQueueDataNode; //链队节点

typedef struct{
    LinkQueueDataNode *front; //指向队头节点
    LinkQueueDataNode *rear; //指向队尾节点
}LinkQueue; //链队

//初始化链队
void initLinkQueue(LinkQueue *&LQ);
//销毁链队
void destroyLinkQueue(LinkQueue *&LQ);
//判断链队是否为空
bool isEmptyLinkQueue(const LinkQueue *LQ);
//元素入队
bool enLinkQueue(LinkQueue *&LQ,ElemType e);
//元素出队
bool deLinkQueue(LinkQueue *&LQ,ElemType &e);



#endif //DATASTRUCTUREBYLICHUNBAO_LINKQUEUE_H

//使用案例
//#include "StackAndQueue/LinkQueue/linkQueue.h"
//
//int main(){
//    LinkQueue *pLinkQueue= nullptr;
//    initLinkQueue(pLinkQueue);
//
//    //入队
//    bool ret=false;
//    int e;
//    for(int i=0;i<10;i++){
//        ret= enLinkQueue(pLinkQueue,i+1990);
//        if(ret==false)
//            printf("%d入队失败,当前队列是否为空:%d\n",
//                   i+1990, isEmptyLinkQueue(pLinkQueue));
//        else
//            printf("%d入队成功!!!\n",i+1990);
//
//    }
//    printf("\n----------------------------------\n");
//
//    //出队
//    while(!isEmptyLinkQueue(pLinkQueue)){
//        ret= deLinkQueue(pLinkQueue,e);
//
//        if(ret==false){
//            printf("出队列失败,当前队列是否为空:%d\n",
//                   isEmptyLinkQueue(pLinkQueue));
//        }else{
//            printf("出队成功,出队元素:%d\n",e);
//        }
//    }
//
//    printf("\n----------------------------------\n");
//
//    destroyLinkQueue(pLinkQueue);
//    if(pLinkQueue!= nullptr)
//        printf("释放队列失败\n");
//    else
//        printf("释放队列成功!!\n");
//
//    return 0;
//}
