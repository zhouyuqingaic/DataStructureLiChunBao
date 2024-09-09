//
// Created by zhouyuqing on 2024/8/14.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_SQSTRING_H
#define DATASTRUCTUREBYLICHUNBAO_SQSTRING_H

#include<stdio.h>

#define MaxSize 10000

typedef struct SqString{
    char data[MaxSize]; //顺序串存储容器
    int length; //顺序串长度
}SqString; //顺序串

//建立顺序串并赋值
void assignSqString(SqString &Sq,const char *cstr);

//将其他顺序串复制给顺序串
void copySqString(SqString &Sq,const SqString &SqOther);

//判断两个顺序串是否相等
bool equalSqString(SqString &Sq,const SqString &SqOther);

//获取顺序串长度
int lengthSqString(SqString &Sq);

//串拼接
SqString concatSqString(const SqString &Sq,SqString SqOther);

//求子串 pos位置开始 且长度length
bool subStrSqString(const SqString &Sq,int pos,int length,SqString &result);

//子串的插入 pos位置开始
bool insertStrSqString(const SqString &Sq,int pos,const SqString &subStr,SqString &result);

//子串的删除 pos位置开始 且长度length
bool deleteStrSqString(const SqString &Sq,int pos,int length,SqString &result);

//顺序串的替换，将pos开始 长度为length的 元素替换为子串
bool replaceStrSqString(const SqString &Sq,int pos,int length,const SqString &subStr,SqString &result);

//显示顺序串
void displayStrSqString(const SqString &Sq);

//获取next数组
void getNextSqString(SqString t,int next[]);

//使用next数组来进行匹配
int KMPIndexSqString(const SqString &Li,const SqString &subStr);


#endif //DATASTRUCTUREBYLICHUNBAO_SQSTRING_H


//使用案例
//#include"StringStruct/SqString/sqString.h"
//
//
//int main(){
//    char *str="zhouyuqingaic";
//    SqString Sq;
//    //赋值字符串
//    assignSqString(Sq,str);
//    //显示字符串
//    displayStrSqString(Sq);
//
//    printf("----------------------------------------\n");
//
//    //字符串复制
//    SqString Sq2;
//    copySqString(Sq2,Sq);
//    displayStrSqString(Sq2);
//
//    printf("Equal:%d\n", equalSqString(Sq,Sq2));
//
//    printf("----------------------------------------\n");
//
//    //删除从个第1位开始往后4位
//    SqString result;
//    bool ret=deleteStrSqString(Sq,1,4,result);
//    if(ret==false){
//        perror("删除失败\n");
//        return -1;
//    }else{
//        printf("删除成功\n");
//        displayStrSqString(result);
//    }
//
//    printf("----------------------------------------\n");
//
//    //创建子串
//    SqString subStr;
//    assignSqString(subStr,"GaoChun");
//    //子串插入到1位置
//    ret=insertStrSqString(Sq,1,subStr,result);
//    if(ret==false){
//        perror("插入失败\n");
//        return -1;
//    }else{
//        printf("插入成功\n");
//        displayStrSqString(result);
//    }
//
//    printf("----------------------------------------\n");
//
//    //获取从 lengthSqString(subStr)+1开始长度为 lengthSqString(Sq) 位置上元素构成的子串
//    ret=subStrSqString(result,lengthSqString(subStr)+1,  lengthSqString(Sq),subStr);
//    if(ret==false){
//        perror("获取子串失败\n");
//        return -1;
//    }else{
//        printf("获取子串成功\n");
//        displayStrSqString(subStr);
//    }
//
//    printf("----------------------------------------\n");
//
//    assignSqString(subStr,"NanJing");
//
//    //将 Sq串 与 subStr串拼接
//    result=concatSqString(Sq,subStr);
//    displayStrSqString(result);
//
//    printf("----------------------------------------\n");
//    SqString subString;
//    assignSqString(subString,"Bei");
//    //替换字符串从 lengthSqString(Sq)+1位置开始 长度为3 的元素为 "Bei"
//    SqString result2;
//    ret=replaceStrSqString(result, lengthSqString(Sq)+1,3,subString,result2);
//    if(ret==false){
//        perror("子串替换失败\n");
//        return -1;
//    }else{
//        printf("子串替换成功\n");
//        displayStrSqString(result);
//        displayStrSqString(result2);
//    }
//
//
//    return 0;
//}