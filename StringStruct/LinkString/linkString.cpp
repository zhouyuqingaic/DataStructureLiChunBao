//
// Created by zhouyuqing on 2024/8/15.
//

#include"linkString.h"

//为链串赋值
void assignLinkString(LinkStringNode *&Li,const char *cstr){
    LinkStringNode *current= nullptr,*pre= nullptr;
    //创建链串
    Li=(LinkStringNode *)malloc(sizeof(LinkStringNode));
    pre=Li; //pre指向current的上个节点
    //遍历 cstr中每个元素，并将其顺序挂到链串 中
    for(int i=0;cstr[i]!='\0';i++){
        //创建当前节点
        current=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        current->data=cstr[i];
        current->next= nullptr;
        //将当前节点挂到链串后
        pre->next=current;
        pre=current;
    }
}

//销毁链串
void destroyLinkString(LinkStringNode *&Li){
    //pre指向current当前节点的上个节点
    LinkStringNode *pre=Li,*current=Li->next;
    //从头节点开始，遍历并删除每个节点
    while(current!= nullptr){
        free(pre);
        pre=current;
        current=current->next;
    }
    //此时current为null,但pre!=null
    free(pre);
    Li= nullptr;
}

//判断链串是否相等
bool equalLinkString(const LinkStringNode *Li,const LinkStringNode *LiOther){
    //currentLi与currentLiOther分别指向 链串的数据节点
    LinkStringNode *currentLi=Li->next;
    LinkStringNode *currentLiOther=LiOther->next;
    //遍历两个串的每个数据节点
    while(currentLi!= nullptr && currentLiOther!= nullptr){
        if(currentLi->data!=currentLiOther->data)
            return false;
        //访问下个节点
        currentLi=currentLi->next;
        currentLiOther=currentLiOther->next;
    }
    if(currentLi!= nullptr || currentLiOther!= nullptr)
        //如果有链串数据没有遍历完,则表明两链串不相等
        return false;
    else
        //如果有链串都遍历完,而且遍历过程中没有出现不相等元素，则两串相等
        return true;
}

//获取链串长度
int lengthLinkString(const LinkStringNode *Li){
    int count=0; //统计数据节点
    LinkStringNode *currentNode=Li->next; //currentNode指向数据节点
    //遍历并统计长度
    while(currentNode!= nullptr){
        count++;
        currentNode=currentNode->next;
    }
    return count;
}

//将两个链串拼接成一个
LinkStringNode *concatLinkString(const LinkStringNode*Li1,const LinkStringNode*Li2){
    //创建结果串
    LinkStringNode *result;
    result=(LinkStringNode *)malloc(sizeof(LinkStringNode));
    result->next= nullptr;
    LinkStringNode *rear=result; //rear指向结果串的结尾
    LinkStringNode *current=Li1->next; //current指向当前要加入链队的节点

    //遍历两个链串，并将遍历结果加入结果串
    LinkStringNode *tempStringNode= nullptr;
    while(current!=NULL){
        //创建结果节点 赋值当前节点数据
        tempStringNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempStringNode->data=current->data;
        tempStringNode->next= nullptr;
        //加入结果串
        rear->next=tempStringNode;
        rear=rear->next;
        //访问下个节点
        current=current->next;
    }
    current=Li2->next;
    while(current!=NULL){
        //创建结果节点 赋值当前节点数据
        tempStringNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempStringNode->data=current->data;
        tempStringNode->next= nullptr;
        //加入结果串
        rear->next=tempStringNode;
        rear=rear->next;
        //访问下个节点
        current=current->next;
    }
    return result;
}

//求子串 从pos位置开始的length个元素
LinkStringNode *subStrLinkString(const LinkStringNode*Li,int pos,int length){
    //创建结果串
    LinkStringNode *result;
    result=(LinkStringNode *)malloc(sizeof(LinkStringNode));
    result->next= nullptr;
    LinkStringNode *rear=result; //rear指向结果串的结尾

    //判断传入pos和length是否符合规范
    if(pos<=0 || pos>lengthLinkString(Li) || pos+length-1> lengthLinkString(Li))
        return result; //不符合规范 ，则返回一个空链串

    //指向Li串第pos个节点
    LinkStringNode *current=Li->next; //current从第一个节点开始计数
    for(int i=1;i<pos;i++) //退出时共执行pos-1次current后移，正好指向pos位置节点
        current=current->next;

    //将Li从pos节点开始的Length个节点复制到result结果串中
    LinkStringNode *tempStringNode= nullptr;
    for(int i=1;i<=length;i++){
        //创建结果节点数据
        tempStringNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempStringNode->data=current->data;
        tempStringNode->next= nullptr;
        //将结果节点挂结果串后
        rear->next=tempStringNode;
        rear=tempStringNode;
        //遍历下个节点
        current=current->next;
    }
    return result;
}

//将子串插入到主串pos开始的位置上
LinkStringNode *insStrLinkString(const LinkStringNode*Li,int pos,const LinkStringNode *subStr){
    //创建结果串
    LinkStringNode *result;
    result=(LinkStringNode *)malloc(sizeof(LinkStringNode));
    result->next= nullptr;
    LinkStringNode *rear=result; //rear指向结果串的结尾

    //判断传入pos是否合规
    if(pos<=0 || pos>lengthLinkString(Li)+1) //当pos==lengthLinkString(Li)+1表示在最后追加子串
        return result; //不符合规范，返回一个空链串

    LinkStringNode *tempNode= nullptr;

    //将Li的1~pos-1 位置上元素复制到结果串
    LinkStringNode *current=Li->next;
    for(int i=1;i<pos;i++){ //共执行pos-1次循环
        tempNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempNode->data=current->data;
        tempNode->next= nullptr;
        //将节点挂在结果串后
        rear->next=tempNode;
        rear=rear->next;
        //节点后移
        current=current->next;
    }


    //将subStr插入到Li的pos位置开始往后
    LinkStringNode  *currentSubStr=subStr->next;
    for(int i=1;i<= lengthLinkString(subStr);i++){ //执行lengthLinkString(subStr)次循环
        tempNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempNode->data=currentSubStr->data;
        tempNode->next= nullptr;

        //将节点挂在结果串后
        rear->next=tempNode;
        rear=rear->next;

        //节点后移
        currentSubStr=currentSubStr->next;
    }

    //将Li的pos位置及其之后的所有元素加入结果串
    while(current!= nullptr){
        tempNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempNode->data=current->data;
        tempNode->next= nullptr;

        //将节点挂在结果串后面
        rear->next=tempNode;
        rear=rear->next;

        //节点后移
        current=current->next;
    }

    return result;
}

//子串删除，删除从pos位置开始，长度为length的元素
LinkStringNode *delLinkString(const LinkStringNode *Li,int pos,int length){
    LinkStringNode *result=(LinkStringNode *)malloc(sizeof(LinkStringNode));
    result->next= nullptr;
    LinkStringNode *rear=result;
    //判断传入参数是否合规
    if(pos<=0
        ||length>lengthLinkString(Li)
        || length<0
        || pos+length-1>lengthLinkString(Li))
        return result; //参数不合规，返回空串
    //将1~pos-1位置上元素加入结果串
    LinkStringNode *current=Li->next,*tempNode= nullptr;
    for(int i=1;i<pos;i++){
        tempNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempNode->data=current->data;
        tempNode->next=nullptr;

        //加入结果串
        rear->next=tempNode;
        rear=tempNode;

        //访问下个元素
        current=current->next;
    }


    //移动到pos+length-1位置上
    for(int i=pos;i<=pos+length-1;i++){
        current=current->next;
    }

    //将剩余节点加入结果串中
    while(current!= nullptr){
        tempNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempNode->data=current->data;
        tempNode->next=nullptr;

        //加入结果串
        rear->next=tempNode;
        rear=tempNode;

        //访问下个元素
        current=current->next;
    }

    return result;
}

//子串的替换 ，将Li中从pos位置开始长度为length的链串替换为子串
LinkStringNode *replaceLinkString(const LinkStringNode *Li,int pos,int length,const LinkStringNode *subStr) {
    LinkStringNode *result = (LinkStringNode *) malloc(sizeof(LinkStringNode));
    result->next = nullptr;
    LinkStringNode *rear = result;

    //判断传入参数是否合规
    if (pos <= 0
        || length > lengthLinkString(Li)
        || length < 0
        || pos + length - 1 > lengthLinkString(Li)) {
        return result; //参数不合规，返回空串
    }

    //将1~pos-1位置上的元素加入结果串
    LinkStringNode *current=Li->next,*tempNode= nullptr;
    for(int i=1;i<pos;i++){
        tempNode=(LinkStringNode*)malloc(sizeof(LinkStringNode));
        tempNode->data=current->data;
        tempNode->next= nullptr;

        //加入结果串
        rear->next=tempNode;
        rear=rear->next;

        //访问下个元素
        current=current->next;
    }

    //将subStr中元素加入结果串
    LinkStringNode *currentSubStr=subStr->next;
    while(currentSubStr!= nullptr){
        tempNode=(LinkStringNode *)malloc(sizeof(LinkStringNode));
        tempNode->data=currentSubStr->data;
        tempNode->next= nullptr;

        //加入结果串
        rear->next=tempNode;
        rear=rear->next;

        //访问下个元素
        currentSubStr=currentSubStr->next;
    }

    //将current移动到pos+length位置上
    for(int i=0;i<length;i++){ //从pos位置开始，往后移动length次,移动pos+length位置
        current=current->next;
    }

    //将pos+length位置上的所有元素加入结果串
    while(current!= nullptr){
        tempNode=(LinkStringNode*)malloc(sizeof(LinkStringNode));
        tempNode->data=current->data;
        tempNode->next= nullptr;

        //加入结果串
        rear->next=tempNode;
        rear=rear->next;

        //访问下个元素
        current=current->next;
    }

    return result;
}

//展示所有元素
void displayLinkString(const LinkStringNode *Li){
    //遍历所有元素并打印
    LinkStringNode *current=Li->next;
    printf("\n|------------start-------\n");
    printf("|");
    while(current!= nullptr){
        printf("%c ",current->data);
        current=current->next;
    }
    printf("\n");
    printf("|------------ end -------\n");
}
