//
// Created by zhouyuqing on 2024/8/3.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_LINKLIST_H
#define DATASTRUCTUREBYLICHUNBAO_LINKLIST_H

#include"malloc.h"

typedef int ElemType;

//带头结点的单链表
typedef struct LinkNode{
    ElemType data; //数据域
    struct LinkNode *next; //下一节点
}LinkNode; //单链表节点

//创建链表，并将arr中的元素用头插法插入链表
void createListFront(LinkNode *&L,ElemType arr[],int lengthArr);
//创建链表，并将arr中的元素用尾插法插入链表
void createListRear(LinkNode *&L,ElemType arr[],int lenghtArr);
//初始化线性表
void initList(LinkNode *&L);
//销毁线性表
void destroyList(LinkNode *&L);
//判断链表是否为空
bool listEmpty(const LinkNode *L);
//获取链表长度
int listLength(const LinkNode *L);
//输出线性表到屏幕
void displayList(const LinkNode *L);
//获取链表第i个元素数据域的值
bool getElem(LinkNode *L,int i,ElemType &e);
//找到第一个属于域为e的节点在链表中的位置
int locateElem(LinkNode *L,ElemType e);
//插入数据元素到i号节点位置
bool listInsert(LinkNode *&L,int i,ElemType e);
//删除i号节点，并获取删除元素的数据域
bool ListDelete(LinkNode *&L,int i,ElemType &e);


#endif //DATASTRUCTUREBYLICHUNBAO_LINKLIST_H


//使用案例
//#include"LinerList/LinkList/linkList.h"
//
//int main(){
//    ElemType arr[10];
//    for(int i=0;i<10;i++)
//        arr[i]=i+1990;
//    //创建链表
//    LinkNode *L1;
//    createListFront(L1,arr,10);
//    displayList(L1);
//    printf("\n---------------------------\n");
//    LinkNode *L2;
//    createListRear(L2,arr,10);
//    displayList(L2);
//    printf("\n---------------------------\n");
//
//    ElemType temp;
//    bool ret= ListDelete(L1,10,temp);
//    if(ret==true)
//        printf("删除成功，删除元素为:%d\n",temp);
//    else{
//        printf("删除失败");
//        return 0;
//    }
//
//    ret= ListDelete(L1,1,temp);
//    if(ret==true)
//        printf("删除成功，删除元素为:%d\n",temp);
//    else{
//        printf("删除失败");
//        return 0;
//    }
//    displayList(L1);
//    printf("\n---------------------------\n");
//
//    temp=2009;
//    ret= listInsert(L1,1,temp);
//    if(ret==true)
//        printf("插入成功，插入元素为:%d\n",temp);
//    else{
//        printf("插入失败");
//        return 0;
//    }
//
//    temp=2000;
//    ret= listInsert(L1,10,temp);
//    if(ret==true)
//        printf("插入成功，插入元素为:%d\n",temp);
//    else{
//        printf("插入失败");
//        return 0;
//    }
//
//    temp=5555;
//    ret= listInsert(L1,5,temp);
//    if(ret==true)
//        printf("插入成功，插入元素为:%d\n",temp);
//    else{
//        printf("插入失败");
//        return 0;
//    }
//
//    displayList(L1);
//
//    printf("当前链表长度:%d\n", listLength(L1));
//    printf("当前链表是否为空:%d\n", listEmpty(L1));
//    printf("值为temp:%d 元素的节点位置:%d\n",temp, locateElem(L1,temp));
//    int i=5;
//    ret=getElem(L1,i,temp);
//    if(ret==true)
//        printf("获取%d位置上的元素:%d\n",i,temp);
//    else{
//        printf("获取%d位置上的元素失败\n");
//        return 0;
//    }
//
//    printf("\n---------------------------\n");
//
//    destroyList(L1);
//    destroyList(L2);
//    if(L1== nullptr && L2== nullptr){
//        printf("销毁链表成功");
//    }else{
//        printf("销毁链表失败");
//        return 0;
//    }
//
//    return 0;
//}



