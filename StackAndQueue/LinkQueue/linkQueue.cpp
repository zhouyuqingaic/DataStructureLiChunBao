//
// Created by zhouyuqing on 2024/8/12.
//

#include"linkQueue.h"

//初始化链队
void initLinkQueue(LinkQueue *&LQ){
    if(LQ!= nullptr)
        destroyLinkQueue(LQ);
    //初始化链队
    LQ=(LinkQueue *)malloc(sizeof(LinkQueue));
    LQ->front= nullptr;
    LQ->rear= nullptr;
}
//销毁链队
void destroyLinkQueue(LinkQueue *&LQ){
    if(LQ== nullptr)
        return;
    //遍历并释放 链队中所有数据节点
    LinkQueueDataNode *currentNode=LQ->front,*tempNode= nullptr;
    while(currentNode!= nullptr){
        tempNode=currentNode->next;
        free(currentNode); //释放当前节点
        currentNode=tempNode;
    }
    //释放链队
    free(LQ);
    LQ= nullptr;
}
//判断链队是否为空
bool isEmptyLinkQueue(const LinkQueue *LQ){
    return LQ->front== nullptr;
}


////很不优雅的实现
////元素入队
//bool enLinkQueue(LinkQueue *&LQ,ElemType e){
//    if(LQ== nullptr)
//        return false;
//    //创建数据节点
//    LinkQueueDataNode *currentNode=
//            (LinkQueueDataNode *)malloc(sizeof(LinkQueueDataNode));
//    currentNode->data=e;
//    currentNode->next= nullptr;
//    if(LQ->front== nullptr){
//        //链队为空,则该节点既是头结点也是尾节点
//        LQ->front=currentNode;
//        LQ->rear=currentNode;
//    }else {
//        //链表非空
//        //将数据节点 用头插法 插入链队
//        currentNode->next = LQ->front->next;
//        LQ->front = currentNode;
//    }
//    return true;
//}
////元素出队
//bool deLinkQueue(LinkQueue *&LQ,ElemType &e){
//    if(LQ== nullptr || isEmptyLinkQueue(LQ))
//        return false;
//    //获取队尾作为 出队节点
//    LinkQueueDataNode *currentNode=LQ->rear;
//    e=currentNode->data;
//    if(LQ->front==LQ->rear){
//        //链表只有一个元素
//        free(currentNode);
//        LQ->front=LQ->rear=nullptr;
//    }else{
//        //链表中不止一个元素
//        //获取当前节点的上一个节点
//        LinkQueueDataNode *preNode=LQ->front;
//        while(preNode->next!=currentNode)
//            preNode=preNode->next;
//        //删除当前节点
//        preNode->next= nullptr;
//        free(currentNode);
//        //更新队列尾指针
//        LQ->rear=preNode;
//    }
//    return true;
//}

//元素入队
bool enLinkQueue(LinkQueue *&LQ,ElemType e){
    //链队不存在，则出队失败
    if(LQ== nullptr)
        return false;
    //创建 数据节点
    LinkQueueDataNode *dataNode=(LinkQueueDataNode *)malloc(sizeof(LinkQueueDataNode));
    dataNode->data=e;
    dataNode->next= nullptr;
    if(LQ->front== nullptr){
        //链表为空，则 头尾指针都 指向 数据节点
        LQ->front=dataNode;
        LQ->rear=dataNode;
    }else{
        //链表不为空
        //将数据节点挂在尾节点后 并 更新尾指针
        LQ->rear->next=dataNode;
        LQ->rear=dataNode;
    }
    return true;
}
//元素出队
bool deLinkQueue(LinkQueue *&LQ,ElemType &e){
    //链队不存在 或 链队为空，则出队失败
    if(LQ== nullptr || isEmptyLinkQueue(LQ))
        return false;
    //获取队头数据节点
    LinkQueueDataNode *dataNode=LQ->front;
    e=dataNode->data;
    if(LQ->front==LQ->rear){
        //链表中只有一个元素
        //释放队头节点，并更新队头、队尾指针
        free(dataNode);
        LQ->front=LQ->rear= nullptr;
    }else {
        //链表中有多个元素
        //更新队头节点
        LQ->front = dataNode->next;
        //释放原队头节点
        free(dataNode);
    }
    return true;
}






