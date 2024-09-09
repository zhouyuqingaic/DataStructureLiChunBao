//
// Created by zhouyuqing on 2024/8/23.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_GENERALLINKLIST_H
#define DATASTRUCTUREBYLICHUNBAO_GENERALLINKLIST_H

#include<stdio.h>
#include<malloc.h>

typedef int Elemetype;

typedef enum{
    ATOM,
    LIST
}TAG;

typedef struct GLNode{
    TAG tag; //广义表节点标识
    union{ //联合体，用于存储节点数据
        Elemetype data; //存放原子值
        struct GLNode *sublist; //指向子表的指针
    }val;
    struct GLNode *next; //指向下一同类兄弟节点
}GLNode; //广义表节点

//获取广义表的长度
int lengthGLList(GLNode *gl);

//获取广义表的深度
int depthGLList(GLNode *gl);

//创建广义表的存储结构
GLNode *createGLNode(const char *&s);

//销毁广义表
void destroyGLNode(GLNode *&g);

//输出广义表
void displayGLNode(GLNode *g);


#endif //DATASTRUCTUREBYLICHUNBAO_GENERALLINKLIST_H

//有问题代码，获取深度算法有问题
//使用案例，问题后期待修复
//#include"GeneralizeList/generalLinkList/generalLinkList.h"
//
//int main(){
//    //创建广义表
//    const char *gls="((a,b),c,(#),(e,f))";
//    GLNode *gl;
//    gl= createGLNode(gls);
//    //展示广义表
//    printf("\n");
//    displayGLNode(gl);
//    printf("\n");
//    //获取广义表深度
//    int depth=depthGLList(gl);
//    printf("广义表深度:%d\n",depth);
//
//    return 0;
//}