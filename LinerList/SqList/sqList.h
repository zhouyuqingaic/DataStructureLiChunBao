//
// Created by zhouyuqing on 2024/8/1.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_SQLIST_H
#define DATASTRUCTUREBYLICHUNBAO_SQLIST_H

#include<malloc.h>
#include<stdio.h>

#define MaxSize 50



typedef int ElemType;

typedef struct{
    ElemType data[MaxSize];
    int length;
}SqList;

//由于a中的n个元素建立顺序表
bool createList(SqList *&L,ElemType a[],int n);
//初始化线性表
void initList(SqList *&L);
//销毁线性表,释放L所占用空间
void destroyList(SqList * &L);
//判断表是否为空
bool listEmpty(SqList *L);
//获取顺序表长度
int listLength(SqList *L);
//显示顺序表
void displayList(SqList *L);
//获取先新性表中第i个元素的值
bool getElement(SqList *L,int i,ElemType &e);
//定位data域为e的元素下标
int locateElement(SqList *L,ElemType e);
//在顺序表i位置上插入data域为e的元素
bool listInsert(SqList *&L,int i,ElemType e);
//从顺序表中删除i位置上的元素,并将元素的数据域赋给e
bool listDelete(SqList *&L,int i,ElemType &e);



#endif //DATASTRUCTUREBYLICHUNBAO_SQLIST_H

//测试案例
//#include"LinerList/SqList/sqList.h"
//
//int main() {
//    ElemType arr[10];
//    for(int i=0;i<10;i++)
//        arr[i]=i+1990;
//
//    SqList *L=nullptr;
//    bool ret;
//    ret=createList(L,arr,10);
//    if(ret==0){
//        return 1;
//    }
//    displayList(L);
//    printf("\n--------------------\n");
//    ElemType e;
//    ret=listDelete(L,5,e);
//    if(ret==0){
//        return 1;
//    }
//    printf("被删除元素e:%d\n",e);
//    displayList(L);
//    printf("\n--------------------\n");
//    e=2005;
//    ret= listInsert(L,5,e);
//    if(ret==0){
//        return 1;
//    }
//    printf("删除元素e:%d\n",e);
//    displayList(L);
//
//    //销毁数组
//    destroyList(L);
//    if(L!= nullptr)
//        return 1;
//    printf("销毁数组成功!\n");
//
//
//    return 0;
//}
//