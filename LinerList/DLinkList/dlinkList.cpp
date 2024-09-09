//
// Created by zhouyuqing on 2024/8/4.
//

#include"dlinkList.h"

//遍历arr列表并用头插法建立链表
void createListFront(DLinkNode *&L,ElemType arr[],int length){
    DLinkNode  *currentNode= nullptr;
    //创建头节点
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior=L->next= nullptr;
    //遍历列表中每个元素
    for(int i=0;i<length;i++){
        //创建用于存储当前元素的双链表节点
        currentNode=(DLinkNode *)malloc(sizeof(DLinkNode));
        currentNode->data=arr[i];
        //将数据节点挂到头节点后
        currentNode->next=L->next;
        currentNode->prior=L;
        if(L->next!= nullptr)
            L->next->prior=currentNode;
        L->next=currentNode;
    }
}
//遍历arr列表并用尾插法建立链表
void createListRear(DLinkNode *&L,ElemType arr[],int length){
    DLinkNode *currentNode= nullptr,*rear= nullptr;
    //创建头节点
    L=(DLinkNode *)malloc(sizeof(DLinkNode));
    L->prior=L->next= nullptr;
    rear=L;
    //遍历列表中每个元素
    for(int i=0;i<length;i++){
        //创建用于存储当前元素的双链表节点
        currentNode=(DLinkNode *)malloc(sizeof(DLinkNode));
        currentNode->data=arr[i];
        //将数据节点挂到最后一个节点后面
        currentNode->prior=rear;
        currentNode->next=rear->next;
        rear->next=currentNode;
        rear=currentNode;
    }
}
//在链表i位置上插入元素e
bool listInsert(DLinkNode *&L,int i,ElemType e){
    if(i<1)
        return false;
    int j=0;
    DLinkNode *preNode=L,*tempNode= nullptr;
    //找到第i-1个节点
    while(j<i-1 && preNode!= nullptr) {
        j++;
        preNode = preNode->next;
    }

    //i节点超过范围,大于listLength+1 (为listLenght+1表示插入到链表最后一个元素后)
    if(preNode== nullptr)
        return false;
    else{
        //创建e元素节点
        tempNode=(DLinkNode *)malloc(sizeof(DLinkNode));
        tempNode->data=e;
        //将e元素节点挂到i-1元素后
        tempNode->next=preNode->next;
        if(preNode->next!= nullptr)
            preNode->next->prior=tempNode;
        preNode->next=tempNode;
        tempNode->prior=preNode;
        return true;
    }
}
//删除链表中的i号元素,将删除结果赋给e
bool listDelete(DLinkNode *&L,int i,ElemType &e){
    if(i<1)
        return false;
    int j=0;
    DLinkNode *preNode=L,*tempNode;
    //找到第i-1个节点
    while(j<i-1 && preNode!= nullptr) {
        j++;
        preNode = preNode->next;
    }

    //i节点超过范围,大于等于listLength+1,(当i=listLengt+1时，pre指向最后一个元素)
    if(preNode== nullptr || preNode->next==nullptr)
        return false;
    else{
        //获取i节点数据
        tempNode=preNode->next;
        e=tempNode->data;
        //将i号节点从链表移除
        preNode->next=tempNode->next;
        if(tempNode->next!= nullptr)
            tempNode->next->prior=preNode;
        //释放i节点
        free(tempNode);
        return true;
    }
}

//显示链表,reverse=false表示需要逆序显示
void displayList(const DLinkNode *L,bool reverse){
    DLinkNode *currentNode= nullptr;
    printf("\n");
    if(reverse== false){
        //不逆序打印
        currentNode=L->next;
        while(currentNode!=nullptr){
            printf("%d ",currentNode->data);
            currentNode=currentNode->next;
        }
    }else{
        //逆序打印
        currentNode=(DLinkNode *)L;
        //找到最后一个节点
        while(currentNode->next!=NULL){
            currentNode=currentNode->next;
        }
        //从最后一个节点向前遍历
        while(currentNode!=L){
            printf("%d ",currentNode->data);
            currentNode=currentNode->prior;
        }
    }
    printf("\n");
}









