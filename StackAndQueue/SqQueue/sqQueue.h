//
// Created by zhouyuqing on 2024/8/11.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_SQQUEUE_H
#define DATASTRUCTUREBYLICHUNBAO_SQQUEUE_H

#include"malloc.h"

#define MaxSize 5

typedef int ElemType;

typedef struct{
    ElemType data[MaxSize]; //存放队中元素
    int front,rear; //队头和队尾指针
}SqQueue; //顺序队

//初始化队列
void initSqQueue(SqQueue *&q);
//销毁队列
void destroySqQueue(SqQueue *&q);
//判断队列是否为空
bool isEmptySqQueue(const SqQueue *q);
//元素进入队列
bool enSqQueue(SqQueue *&q,ElemType e);
//元素出队列
bool deSqQueue(SqQueue *&q,ElemType &e);


#endif //DATASTRUCTUREBYLICHUNBAO_SQQUEUE_H

//使用案例
//#include "StackAndQueue/SqQueue/sqQueue.h"
//
//int main(){
//    SqQueue *pSqQueue= nullptr;
//    initSqQueue(pSqQueue);
//
//    //入队
//    bool ret=false;
//    int e;
//    for(int i=0;i<10;i++){
//        ret= enSqQueue(pSqQueue,i+1990);
//        if(ret==false)
//            printf("%d入队失败,当前队列是否为空:%d\n",
//                   i+1990, isEmptySqQueue(pSqQueue));
//        else
//            printf("%d入队成功!!!\n",i+1990);
//
//    }
//    printf("\n----------------------------------\n");
//
//    //出队
//    for(int i=0;i<10;i++){
//        ret= deSqQueue(pSqQueue,e);
//
//        if(ret==false){
//            printf("出队列失败,当前队列是否为空:%d\n",
//                   isEmptySqQueue(pSqQueue));
//        }else{
//            printf("出队成功,出队元素:%d\n",e);
//        }
//    }
//
//    destroySqQueue(pSqQueue);
//    if(pSqQueue!= nullptr)
//        printf("释放队列失败\n");
//    else
//        printf("释放队列成功!!\n");
//
//    return 0;
//}
