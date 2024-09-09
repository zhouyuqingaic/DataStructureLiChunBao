//
// Created by zhouyuqing on 2024/8/8.
//

#include"linkStack.h"

//初始化栈
void initLinkStack(LinkStackNode *&LinkSt){
    //栈不空,则销毁栈
    if(LinkSt!= nullptr)
        destroyLinkStack(LinkSt);
    //创建栈
    // 设置头节点
    LinkSt=(LinkStackNode *)malloc(sizeof(LinkStackNode));
    LinkSt->next;
}

//销毁栈
void destroyLinkStack(LinkStackNode *&LinkSt){
    if(LinkSt== nullptr)
        return;
    //释放链栈
    free(LinkSt);
    LinkSt= nullptr;
}

//判断栈空
bool IsEmptyLinkStack(const LinkStackNode *LinkSt){
    return LinkSt->next==NULL; //只有一个头节点则栈空
}

//e元素入栈
bool PushLinkStack(LinkStackNode *&LinkSt,ElemType e){
    //连栈不存在则入栈失败
    if(LinkSt== nullptr)
        return false;
    //运用头插法插入链表，链表头结点后面就是栈顶节点
    //创建头结点
    LinkStackNode *topNode=(LinkStackNode *)malloc(sizeof(LinkStackNode));
    topNode->data=e; //设置栈顶节点数据
    //将栈顶元素入栈
    topNode->next=LinkSt->next;
    LinkSt->next=topNode;
    return true;
}

//e元素出栈
bool PopLinkStack(LinkStackNode *&LinkSt,ElemType &e){
    //栈空则出栈失败
    if(IsEmptyLinkStack(LinkSt))
        return false;
    //获取栈顶节点
    LinkStackNode *topNode=LinkSt->next;
    //移除并更新栈顶
    LinkSt->next=topNode->next;
    //获取栈顶节点的数据
    e=topNode->data;
    //释放空间
    free(topNode);
    return true;
}

//获取栈顶
bool getTopLinkStack(LinkStackNode *LinkSt,ElemType &e){
    //栈空则获取栈顶元素失败
    if(IsEmptyLinkStack(LinkSt))
        return false;
    //获取栈顶节点
    LinkStackNode *topNode=LinkSt->next;
    //获取栈顶节点的数据
    e=topNode->data;
    return true;
}
