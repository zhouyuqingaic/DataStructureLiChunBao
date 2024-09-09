//
// Created by zhouyuqing on 2024/8/3.
//
#include"linkList.h"

//创建链表，并将arr中的元素用头插法插入链表
void createListFront(LinkNode *&L,ElemType arr[],int lengthArr){
    //销毁已存在链表
    if(L!= nullptr)
        destroyList(L);
    //创建头节点
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next= nullptr;
    LinkNode *s= nullptr;
    //遍历列表中每个元素
    for(int i=0;i<lengthArr;i++){
        //创建存储元素的节点，并将节点挂在头节点后
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=arr[i];
        s->next= L->next;
        L->next=s;
    }
}
//创建链表，并将arr中的元素用尾插法插入链表
void createListRear(LinkNode *&L,ElemType arr[],int lenghtArr){
    //销毁已存在链表
    if(L!= nullptr)
        destroyList(L);

    LinkNode *s= nullptr,*r= nullptr;
    //创建头节点
    L=(LinkNode *)malloc(sizeof(LinkNode));
    //r指针指向链尾
    r=L;

    //遍历列表中每个元素
    for(int i=0;i<lenghtArr;i++){
        //创建存储元素节点，并用尾插法将元素挂在尾节点后
        s=(LinkNode *)malloc(sizeof(LinkNode));
        s->data=arr[i];
        s->next=nullptr;
        r->next=s;
        r=s;
    }
}
//初始化线性表
void initList(LinkNode *&L){
    //销毁已存在链表
    if(L!= nullptr)
        destroyList(L);
    L=(LinkNode *)malloc(sizeof(LinkNode));
    L->next= nullptr;
}
//销毁线性表
void destroyList(LinkNode *&L){
    //currentNode指向要被删除节点，nextNode指向要被删除节点的下个节点
    LinkNode *currentNode=L;
    LinkNode *nextNode=L->next;
    //遍历并释放链表中除最后一个节点之外的所有节点
    while(nextNode!= nullptr){
        free(currentNode);
        currentNode=nextNode;
        nextNode=nextNode->next;
    }
    //释放最后一个节点
    free(currentNode);
    //置空链表头指针
    L= nullptr;
}
//判断链表是否为空
bool listEmpty(const LinkNode *L){
    //是否只有头节点
    return L->next== nullptr;
}
//获取链表长度
int listLength(const LinkNode *L){
    int length=0;
    LinkNode *currentNode=(LinkNode *)L;
    //遍历所有除头结点外的所有数据节点，并统计个数
    while(currentNode!= nullptr){
        currentNode=currentNode->next;
        length++;
    }
    return length;
}
//输出线性表到屏幕
void displayList(const LinkNode *L){
    LinkNode *currentNode=L->next;
    //遍历除了头节点外的所有节点，并输出每个节点的数据到屏幕
    printf("\n");
    while(currentNode!= nullptr){
        printf("%d ",currentNode->data);
        currentNode=currentNode->next;
    }
    printf("\n");
}
//获取链表第i个元素数据域的值
bool getElem(LinkNode *L,int i,ElemType &e){
    //i取值错误
    if(i<=0)
        return false;
    int count=1;
    //遍历数据节点，直到遍历到第i个节点
    LinkNode *currentNode=L->next;
    while(count<i && currentNode!= nullptr){
        currentNode=currentNode->next;
        count++;
    }
    //链表长度小于i,获取失败
    if(currentNode== nullptr)
        return false;
    else{
        //找到第i个节点
        e=currentNode->data;
        return true;
    }
}
//找到第一个属于域为e的节点在链表中的位置
int locateElem(LinkNode *L,ElemType e){
    //记录当前节点的位置
    int i=1;
    //遍历节点 直到找到数据域为e的节点
    LinkNode *currentNode=L->next;
    while(currentNode!= nullptr && currentNode->data!=e){
        currentNode=currentNode->next;
        i++;
    }
    //寻找数据域为e的节点失败
    if(currentNode== nullptr)
        return 0;
    else //定位成功，返回数据域为e的节点的位置
        return i;
}
//插入数据元素到i号节点位置
bool listInsert(LinkNode *&L,int i,ElemType e){
    if(i<=0)
        return false;
    int count=0;
    //从头往后遍历到 i-1位置上的节点
    LinkNode *currentNode=L,*tempNode= nullptr;
    while(count<i-1 && currentNode!= nullptr){
        count++;
        currentNode=currentNode->next;
    }
    //i超过最大允许范围 ListLength+1,未找到i-1元素
    if(currentNode== nullptr)
        return false;
    else{
        //找到i-1号节点,在i-1号节点后面插入元素
        //创建数据域为e的节点
        tempNode=(LinkNode *)malloc(sizeof(LinkNode));
        tempNode->data=e;
        //将e节点挂在i-1号节点的后面
        tempNode->next=currentNode->next;
        currentNode->next=tempNode;
        return true;
    }
}
//删除i号节点，并获取删除元素的数据域
bool ListDelete(LinkNode *&L,int i,ElemType &e){
    if(i<=0 || listEmpty(L))
        return false;
    int count=0;
    //从头往后遍历到 i-1位置上的节点
    LinkNode *currentNode=L,*tempNode= nullptr;
    while(count<i-1 && currentNode!= nullptr){
        count++;
        currentNode=currentNode->next;
    }
    if(currentNode==nullptr) //i超过 listLength+1
        return false;
    else {
        if(currentNode->next== nullptr) //i为listLenght+1
            return false;
        //找到i-1号节点，删除i-1号节点后面节点的元素
        tempNode=currentNode->next;
        e=tempNode->data;
        currentNode->next=currentNode->next->next;
        free(tempNode);
        return true;
    }
}


