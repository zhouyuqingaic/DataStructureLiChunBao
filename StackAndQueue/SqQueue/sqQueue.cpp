//
// Created by zhouyuqing on 2024/8/11.
//

#include"sqQueue.h"

//初始化队列
void initSqQueue(SqQueue *&q){
    if(q!= nullptr)
        destroySqQueue(q);
    //创建队列 并 初始化
    q=(SqQueue *)malloc(sizeof(SqQueue));
    q->front=q->rear=0;
}
//销毁队列
void destroySqQueue(SqQueue *&q){
    if(q== nullptr)
        return;
    //释放队列空间
    free(q);
    q= nullptr;
}
//判断队列是否为空
bool isEmptySqQueue(const SqQueue *q){
    return q->front==q->rear;
}
//元素进入队列
bool enSqQueue(SqQueue *&q,ElemType e){
    //队满上溢,入队失败
    if((q->rear+1)%MaxSize==q->front)
        return false;
    //队尾指针加1
    q->rear=(q->rear+1)%MaxSize;
    q->data[q->rear]=e;
    return true;
}
//元素出队列
bool deSqQueue(SqQueue *&q,ElemType &e){
    //队空下溢,出队失败
    if(q->rear==q->front)
        return false;
    //队头指针加1
    q->front=(q->front+1)%MaxSize;
    e=q->data[q->front];
    return true;
}


