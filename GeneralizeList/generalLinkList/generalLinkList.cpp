//
// Created by zhouyuqing on 2024/8/23.
//

#include "generalLinkList.h"

//获取广义表的长度
int lengthGLList(GLNode *gl){
    int count=0;
    //遍历当前节点的所有子节点
    GLNode *currentSubList=gl->val.sublist;
    while(currentSubList!= nullptr){
        //统计子节点个数
        count++;
        currentSubList=currentSubList->next;
    }
    return count;
}

//获取广义表的深度
int depthGLList(GLNode *gl){
    int maxDepth=0; //子表最大深度
    int depth=0; //当前深度
    if(gl->tag==ATOM){
        //当前节点为原子节点，深度为0
        return 0;
    }

    GLNode *currentSubList= nullptr;
    //当前节点为子表节点
    if(gl->tag==LIST)
        currentSubList=gl->val.sublist; //获取当前节点的第一个子节点

    if(currentSubList== nullptr){
        //当前子表无子节点
        return 1;
    }
    //当前节点有子节点,遍历所有子节点
    while(currentSubList!= nullptr){
        if(gl->tag==LIST){
            //当前子节点为子表，获取该子节点的子表的深度
            depth= depthGLList(gl);
            if(depth>maxDepth)
                //当前子表的深度大于子表最大深度,更新最大深度
                maxDepth=depth;
        }
        currentSubList=currentSubList->next; //遍历下一个子节点
    }
    //返回当前表的深度
    return maxDepth+1; //在子表基础上加上当前节点
}

//创建广义表的存储结构
GLNode *createGLNode(const char *&s){
    GLNode *g;
    char ch=*s++; //取第一个字符
    if(ch!='\0'){ //若s未扫描完
        if(ch=='(') {
            g=(GLNode *)malloc(sizeof(GLNode)); //创建一个新节点
            g->next= nullptr;
            g->tag=LIST; //新节点作为表(表头)节点
            g->val.sublist= createGLNode(s);
        }else if(ch==')'){
            g= nullptr; //遇到),置空
        }else if(ch=='#'){
            g= nullptr; //遇到#，表示空表
        }else{ //为原子字符
            g=(GLNode *)malloc(sizeof(GLNode)); //创建一个新节点
            g->next= nullptr;
            g->tag=ATOM;
            g->val.data=ch;
        }
    }else //s扫描完毕,g置空
        g= nullptr;

    ch=*s++; //取下一个字符
    if(g!= nullptr) //s未完成扫描
        if(ch==',') //有剩余的兄弟元素
            g->next= createGLNode(s);
        else //没有剩余元素
            g->next= nullptr;
    return g; //返回广义表g
}


//销毁广义表
void destroyGLNode(GLNode *&g){
    GLNode *currentNode,*nextNode;
    currentNode=g->val.sublist; //currentNode指向广义表的第一个元素(当前节点)
    while(currentNode!= nullptr){ //遍历所有元素
        if(currentNode->tag==ATOM){ //若为原子节点
            nextNode=currentNode->next; //获取当前节点的下个节点
            free(currentNode); //释放当前节点
            currentNode=nextNode; //currentNode指向后继兄弟节点
        }else{ //若为子表
            nextNode=currentNode->next; //获取当前节点的下个节点
            destroyGLNode(currentNode); //释放当前节点为表头表示的子表
            currentNode=nextNode; //currentNode指向后继兄弟结点
        }
    }
    free(g); //释放表头节点
}

//输出广义表
void displayGLNode(GLNode *g){
    if(g!= nullptr){ //表不空判断
        if(g->tag==ATOM) //g元素为原子时
            printf("%c",g->val.data); //输出原子值
        else{ //g元素为子表时
            printf("(");
            //输出子表所有元素
            if(g->val.sublist== nullptr)
                printf("#"); //子表为空表时
            else
                displayGLNode(g->val.sublist); //子表非空，递归显示
            printf(")");
        }
        if(g->next!= nullptr){ //当前元素还有其他兄弟没有输出
            printf(",");
            displayGLNode(g->next); //递归输出g的兄弟
        }
    }
}

