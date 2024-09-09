//
// Created by zhouyuqing on 2024/8/8.
//

#include"sqStack.h"

//初始化栈
void initStack(SqStack *&S){
    //销毁非空栈
    if(S!= nullptr)
        destroyStack(S);
    S=(SqStack *)malloc(sizeof(SqStack)); //创建顺序栈
    S->top=-1;  //设置栈顶
}
//销毁栈
void destroyStack(SqStack *&S){
    if(S== nullptr)
        return;
    //释放栈空间
    free(S);
    S= nullptr;
}
//判断栈空
bool stackEmpty(const SqStack *S){
    return S->top==-1;
}
//入栈
bool push(SqStack *&S,ElemType e){
    //栈满入栈失败
    if(S->top==MaxSize-1)
        return false;
    //入栈
    S->top++; //更新栈顶
    S->data[S->top]=e; //元素加入栈顶
    return true;
}
//出栈
bool pop(SqStack *&S,ElemType &e){
    //栈空出栈失败
    if(S->top==-1)
        return false;
    //出栈
    e=S->data[S->top]; //获取栈顶元素
    S->top--; //更新栈顶
    return true;
}
//获取栈顶元素
bool getTop(const SqStack *S,ElemType &e){
    //栈空获取失败
    if(S->top==-1)
        return false;
    //获取栈顶元素
    e=S->data[S->top];
    return true;
}
