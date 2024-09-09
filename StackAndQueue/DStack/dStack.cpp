//
// Created by zhouyuqing on 2024/8/8.
//

#include"dStack.h"

//初始化共享栈
void initDStack(DStack *&Ds){
    if(Ds!= nullptr)
        destroyDStack(Ds);
    //创建栈
    Ds=(DStack *)malloc(sizeof(DStack));
    //重置指针
    Ds->top_0=-1;
    Ds->top_1=MaxSize;
}
//销毁共享栈
void destroyDStack(DStack *&Ds){
    if(Ds== nullptr)
        return;
    //释放共享栈
    free(Ds);
    Ds= nullptr;
}
//判断stackNum号栈空
bool dStackIsEmpty(const DStack *Ds,int stackNum){
    if(stackNum==0)
        return Ds->top_0==-1;
    else
        return Ds->top_1==MaxSize;
}
//stackNum号栈入栈
bool pushDStack(DStack *&Ds,ElemType e,int stackNum){
    //判断栈是否满
    if(Ds->top_0==Ds->top_1-1)
        return false;
    if(stackNum==0){
        //更新栈顶指针并入栈
        Ds->top_0++;
        Ds->data[Ds->top_0]=e;
        return true;
    }else if(stackNum==1){
        //更新栈顶指针并入栈
        Ds->top_1--;
        Ds->data[Ds->top_1]=e;
        return true;
    }else{
        return false;
    }
}
//stackNum号栈出栈
bool popDStack(DStack *&Ds,ElemType &e,int stackNum){
    if(stackNum==0){
        //栈空出栈失败
        if(Ds->top_0==-1)
            return false;
        //获取出栈元素并修改栈顶指针
        e=Ds->data[Ds->top_0];
        Ds->top_0++;
        return true;
    }else if(stackNum==1){
        //栈空出栈失败
        if(Ds->top_1==MaxSize)
            return false;
        //获取出栈元素并修改栈顶指针
        e=Ds->data[Ds->top_1];
        Ds->top_1--;
        return true;
    }else{
        return false;
    }
}
//获取stackNum号栈顶元素
bool getTopDStack(DStack *Ds,ElemType &e,int stackNum){
    if(stackNum==0){
        //栈空获取失败
        if(Ds->top_0==-1)
            return false;
        //获取栈顶
        e=Ds->data[Ds->top_0];
        return true;
    }else if(stackNum==1){
        //栈空获取失败
        if(Ds->top_1==MaxSize)
            return false;
        //获取栈顶
        e=Ds->data[Ds->top_1];
        return true;
    }else{
        return false;
    }
}

