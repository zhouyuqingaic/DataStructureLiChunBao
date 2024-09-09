//
// Created by zhouyuqing on 2024/8/4.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_DLINKLIST_H
#define DATASTRUCTUREBYLICHUNBAO_DLINKLIST_H

#include"malloc.h"

typedef int ElemType;

typedef struct DLinkNode{
    ElemType data; //存放元素数据
    struct DLinkNode *prior; //指向前驱节点
    struct DLinkNode *next; //指向后继接线
}DLinkNode; //双链表的结点类型

//遍历arr列表并用头插法建立链表
void createListFront(DLinkNode *&L,ElemType arr[],int length);
//遍历arr列表并用尾插法建立链表
void createListRear(DLinkNode *&L,ElemType arr[],int length);
//在链表i位置上插入元素e
bool listInsert(DLinkNode *&L,int i,ElemType e);
//删除链表中的i号元素,将删除结果赋给e
bool listDelete(DLinkNode *&L,int i,ElemType &e);
//显示链表,reverse=false表示需要逆序显示
void displayList(const DLinkNode *L,bool reverse=false);




#endif //DATASTRUCTUREBYLICHUNBAO_DLINKLIST_H


//案例代码
//#include"LinerList/DLinkList/dlinkList.h"
//
//int main(int argc,char *args[]){
//    int arr[10];
//    for(int i=0;i<10;i++)
//        arr[i]=i+1990;
//    DLinkNode *L1= nullptr,*L2= nullptr;
//    createListRear(L1,arr,10);
//    createListFront(L2,arr,10);
//
//
//    displayList(L1);
//    displayList(L2,true);
//
//    printf("----------------------------------\n");
//
//    bool ret;
//    ret=listInsert(L1,1,1111);
//    if(ret==false)
//        return 0;
//    ret=listInsert(L1,12,9999);
//    if(ret==false)
//        return 0;
//    ret=listInsert(L1,5,5555);
//    if(ret==false)
//        return 0;
//
//    displayList(L1);
//
//    printf("----------------------------------\n");
//
//    ElemType e;
//    ret= listDelete(L1,1,e);
//    if(ret==false)
//        return 0;
//    else
//        printf("删除元素:%d\n",e);
//    ret= listDelete(L1,12,e);
//    if(ret==false)
//        return 0;
//    else
//        printf("删除元素:%d\n",e);
//
//    displayList(L1);
//
//    printf("----------------------------------\n");
//
//}
