//
// Created by zhouyuqing on 2024/8/15.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_LINKSTRING_H
#define DATASTRUCTUREBYLICHUNBAO_LINKSTRING_H

#include"malloc.h"

typedef struct LinkStringNode{
    char data; //存放字符
    struct LinkStringNode *next; //指向下一个节点的指针
}LinkStringNode; //链串的节点



//为链串赋值
void assignLinkString(LinkStringNode *&Li,const char *cstr);

//销毁链串
void destroyLinkString(LinkStringNode *&Li);

//判断链串是否相等
bool equalLinkString(const LinkStringNode *Li,const LinkStringNode *LiOther);

//获取链串长度
int lengthLinkString(const LinkStringNode *Li);

//将两个链串拼接成一个
LinkStringNode *concatLinkString(const LinkStringNode*Li1,const LinkStringNode*Li2);

//求子串 从pos位置开始的length个元素
LinkStringNode *subStrLinkString(const LinkStringNode*Li,int pos,int length);

//将子串插入到主串pos开始的位置上
LinkStringNode *insStrLinkString(const LinkStringNode*Li,int pos,const LinkStringNode *subStr);

//子串删除，删除从pos位置开始，长度为length的元素
LinkStringNode *delLinkString(const LinkStringNode *Li,int pos,int length);

//子串的替换 ，将Li中从pos位置开始长度为length的链串替换为子串
LinkStringNode *replaceLinkString(const LinkStringNode *Li,int pos,int length,const LinkStringNode *subStr);

//展示所有元素
void displayLinkString(const LinkStringNode *Li);



#endif //DATASTRUCTUREBYLICHUNBAO_LINKSTRING_H

//使用案例
//#include"StringStruct/LinkString/linkString.h"
//
//int main(){
//    //创建链串
//    LinkStringNode *Li_1= nullptr,*Li_2= nullptr;
//    assignLinkString(Li_1,"zhouyuqingaic");
//    assignLinkString(Li_2,"Android");
//    displayLinkString(Li_1);
//    displayLinkString(Li_2);
//
//    bool ret=equalLinkString((const LinkStringNode *&)Li_1,(const LinkStringNode *&)Li_2);
//    printf("equalLinkString(Li_1,Li_2):%d\n",ret);
//
//    printf("==================================================================================\n");
//
//    //拼接Li_1与Li_2字符串
//    LinkStringNode *result_1=concatLinkString(Li_1,Li_2);
//    //在Li_1后面加入Li_2子串
//    LinkStringNode *result_2= insStrLinkString(Li_1, lengthLinkString(Li_1)+1,Li_2);
//    displayLinkString(result_1);
//    displayLinkString(result_2);
//    ret= equalLinkString(result_1,result_2);
//    printf("equalLinkString(Li_1,Li_2):%d\n",ret);
//
//    printf("==================================================================================\n");
//
//    //获取result_1子串
//    LinkStringNode *result_1_subStr= subStrLinkString(result_1, lengthLinkString(Li_1)+1, lengthLinkString(Li_2));
//    displayLinkString(result_1_subStr);
//
//    //获取result_2子串
//    LinkStringNode *result_2_subStr= delLinkString(result_2,1, lengthLinkString(Li_1));
//    displayLinkString(result_2_subStr);
//
//    ret= equalLinkString(result_1_subStr,result_2_subStr);
//    printf("equalLinkString(result_1_subStr,result_2_subStr):%d\n",equalLinkString(result_1_subStr,result_2_subStr));
//
//    printf("==================================================================================\n");
//
//    LinkStringNode *subStr_2= nullptr;
//    assignLinkString(subStr_2,"Linux");
//    displayLinkString(subStr_2);
//
//    LinkStringNode *result_3=replaceLinkString(result_1,1, lengthLinkString(Li_1),subStr_2);
//    displayLinkString(result_3);
//
//
//    printf("==================================================================================\n");
//    //销毁释链串
//    destroyLinkString(Li_1);
//    destroyLinkString(Li_2);
//    destroyLinkString(result_1);
//    destroyLinkString(result_1_subStr);
//    destroyLinkString(result_2);
//    destroyLinkString(result_2_subStr);
//    destroyLinkString(subStr_2);
//    destroyLinkString(result_3);
//
//    if(Li_1!= nullptr
//       || Li_2!= nullptr
//       || result_1!= nullptr
//       || result_1_subStr!= nullptr
//       || result_2!= nullptr
//       || result_2_subStr!= nullptr
//       || subStr_2!= nullptr
//       ||result_3!= nullptr) {
//        perror("回收内存失败");
//        return -1;
//    }
//
//
//    return 0;
//}
