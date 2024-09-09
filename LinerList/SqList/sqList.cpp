//
// Created by zhouyuqing on 2024/8/2.
//

#include"sqList.h"

//由于a中的n个元素建立顺序表
bool createList(SqList *&L,ElemType a[],int n){
    //n长度大于顺序表最大允许长度
    if(n>MaxSize)
        return false;
    //创建L列表,并将a中的数据加入L表中
    L=(SqList *)malloc(sizeof(SqList));
    L->length=n;
    for(int i=0;i<n;i++)
        L->data[i]=a[i];
    return true;
}
//初始化线性表
void initList(SqList *&L){
    //传入线性表不空，则销毁
    if(L!= nullptr)
        destroyList(L);
    //创建空线性表
    L=(SqList*)malloc(sizeof(SqList));
    L->length=0;
}
//销毁线性表,释放L所占用空间
void destroyList(SqList * &L){
    //释放L所占空间
    free(L);
    L= nullptr;
}
//判断表是否为空
bool listEmpty(SqList *L){
    return L->length==0;
}
//获取顺序表长度
int listLength(SqList *L){
    return L->length;
}
//显示顺序表
void displayList(SqList *L){
    printf("\n");
    for(int i=0;i<L->length;i++)
        printf("%d ",L->data[i]);
    printf("\n");
}
//获取线性表中第i个元素的值
bool getElement(SqList *L,int i,ElemType &e){
    if(listEmpty(L))
        return false;
    //判断i是否在合理范围内
    if(i<1 || i>L->length)
        return false;
    e=L->data[i-1];
    return true;
}
//定位data域为e的元素下标
int locateElement(SqList *L,ElemType e){
    //表空未找到，返回0
    if(listEmpty(L))
        return 0;
    //从头往后遍历表中每个元素，如果元素等于e则返回元素位置
    int i;
    for(i=0;i<L->length;i++)
        if(L->data[i]==e)
            return i+1;
    //遍历完所有元素,未找到返回0
    return 0;
}
//在顺序表i位置上插入data域为e的元素
bool listInsert(SqList *&L,int i,ElemType e){
    //判断顺序表是否已满,满则插入失败
    if(L->length>MaxSize)
        return false;
    //判断i的范围是否正确,当前i==L->length+1时，表示插入到最后一个位置
    if(i<1 || i>L->length+1)
        return false;
    //将i位置往后的所有元素都后移一位
    for(int j=L->length;j>i-1;j--)
        L->data[j]=L->data[j-1];
    //在i位置插入e
    L->data[i-1]=e;
    L->length++;
    return true;
}
//从顺序表中删除i位置上的元素,并将元素的数据域赋给e
bool listDelete(SqList *&L,int i,ElemType &e){
    //判断表是否为空
    if(listEmpty(L))
        return false;
    //判断i是否在合理范围内
    if(i<1 || i>L->length)
        return false;
    //获取被删除元素的数据
    e=L->data[i];
    //将i位置往后的所有元素都前移一位
    for(int j=i;j<L->length;j++)
        L->data[j-1]=L->data[j];
    L->length--;
    return true;
}

