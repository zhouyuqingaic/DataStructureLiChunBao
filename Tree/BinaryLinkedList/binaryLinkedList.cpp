//
// Created by zhouyuqing on 2024/8/28.
//

#include"binaryLinkedList.h"

//st数组作为顺序栈
void createBTree(BTNode *&Bt,char *str){
    BTNode *St[MaxSize]; //St数组作为顺序栈
    int top=-1,flag=0; //top作为栈顶指针
    if(Bt!= nullptr) //初始时二叉链表为空
        destroyBTree(Bt);
    int index=0; //str字符串索引
    char ch=str[0]; //获取当前字符串元素

    //循环扫描str中的每个字符
    BTNode *tempNode= nullptr;
    while(ch!='\0'){
        switch (ch) {
            case '(': //栈顶节点有孩子节点
                top++;
                St[top]=tempNode; //将当前元素加入栈顶
                flag=1; //下个字符为当前栈顶节点的右孩子
                break;
            case ')': //栈顶节点的孩子节点处理完毕
                top--; //栈顶元素出栈
                break;
            case ',': //处理栈顶元素的右孩子节点(第二个子节点)
                flag=2; //下个字符为当前栈顶节点的左孩子
                break;
            default: //当前字符表示一个节点
                //创建用于存储当前字符的节点
                tempNode=(BTNode *)malloc(sizeof(BTNode));
                tempNode->data=ch;
                tempNode->lchild=tempNode->rchild= nullptr;
                if(Bt== nullptr){ //尚未建立根节点，则当前节点为根节点
                    Bt=tempNode;
                }else{ //当前字符表示节点
                    switch (flag) { //当前节点为栈顶节点的孩子节点
                        case 1: //为栈顶元素的左节点
                            St[top]->lchild=tempNode;
                            break;
                        case 2: //为栈顶元素的右节点
                            St[top]->rchild=tempNode;
                            break;
                    }
                }
        }
        index++; //访问下个字符
        ch=str[index];
    }
}

//销毁二叉树
void destroyBTree(BTNode *&Bt){
    if(Bt!= nullptr){ //当前节点非空
        destroyBTree(Bt->lchild); //销毁当前节点的左子树
        destroyBTree(Bt->rchild); //销毁当前节点的右子树
        free(Bt); //释放当前节点
        Bt=nullptr;
    }
}

//查找节点
BTNode *findNode(BTNode *&Bt,ElemType x){
    BTNode *currentNode= nullptr;
    if(Bt== nullptr) //当前树为空
        return nullptr;
    else if(Bt->data==x)  //找到数据为x的节点
        return Bt;
    else{
        //去当前节点的左子树上寻找数据为x的节点
        currentNode= findNode(Bt->lchild,x);
        if(currentNode!= nullptr) //在当前节点的左子树上找到数据为x的节点
            return currentNode;
        else
            //在当前节点的左子树上没有找到数据为x的节点
            //去当前节点的右子树上寻找数据为x的节点
            return findNode(Bt->rchild,x);
    }
}


//输出二叉树,按照构造用字符串的样式
void displayBTree(BTNode *Bt){
    if(Bt!= nullptr){
        printf("%c",Bt->data); //输出当前节点
        if(Bt->lchild!= nullptr || Bt->rchild!= nullptr){
            printf("("); //有孩子节点，输出(

            displayBTree(Bt->lchild); //递归处理左子树
            if(Bt->rchild!=NULL) {
                printf(",");//有右孩子输出
                displayBTree(Bt->rchild); //递归输出右子树
            }
            printf(")"); //孩子节点输出完毕，输出)
        }
    }
}

//获取二叉树元素个数
void numberOfNodesBTree(BTNode *Bt,int &length){
    if(Bt!= nullptr){  //当前元素不空，则访问当前元素
        length++; //当前元素个数+1
        numberOfNodesBTree(Bt,length); //加上左子树元素个数
        numberOfNodesBTree(Bt,length); //加上右子树元素个数
    }
}

//获取二叉树元素个数
int nodesOfBTree(BTNode *Bt){
    if(Bt== nullptr)
        return 0;
    else
        return nodesOfBTree(Bt->lchild)+ nodesOfBTree(Bt->rchild)+1;
}

//先序遍历二叉树，遍历结果存入result中,resultLength为结果数组长度
void preOrderBTree(BTNode *Bt,BTNode *result[],int &resultLength){
    if(Bt!= nullptr){
        //当前节点加入结果表中
        result[resultLength]=Bt;
        //元素个数+1
        resultLength++;

        preOrderBTree(Bt->lchild,result,resultLength);
        preOrderBTree(Bt->rchild,result,resultLength);
    }
}

//中序遍历二叉树，遍历结果存入result中,resultLength为结果数组长度
void inOrderBTree(BTNode *Bt,BTNode *result[],int &resultLength){
    if(Bt!= nullptr){
        inOrderBTree(Bt->lchild,result,resultLength);

        //当前节点加入结果集中
        result[resultLength]=Bt;
        //元素个数+1
        resultLength++;

        inOrderBTree(Bt->rchild,result,resultLength);
    }
}

//后序遍历二叉树，遍历结果存入result中,resultLength为结果数组长度
void postOrderBTree(BTNode *Bt,BTNode *result[],int &resultLength){
    if(Bt!= nullptr){
        postOrderBTree(Bt->lchild,result,resultLength);
        postOrderBTree(Bt->rchild,result,resultLength);

        //当前节点加入结果集中
        result[resultLength]=Bt;
        //元素个数+1
        resultLength++;
    }
}

//显示叶子节点
void displayLeafBTree(BTNode *Bt){
    if(Bt!= nullptr){
        if(Bt->lchild== nullptr && Bt->rchild== nullptr)
            printf("%c ",Bt->data); //当前节点为叶子节点
        displayLeafBTree(Bt->lchild); //显示左子树的叶子节点
        displayLeafBTree(Bt->rchild); //显示右子树的叶子节点
    }
}

//显示值为x节点在二叉树中所在层次，如果不存在，则层次为0
//h为当前节点的深度,传入为1
int levelBTree(BTNode *Bt,ElemType x,int h){
    if(Bt==NULL) //没有找到目标节点返回0
        return 0;
    else if(Bt->data==x) //找到目标节点，返回目标节点所在层次
        return h;
    else{
        //当前节点不是目标节点，去目标节点的左子树中寻找
        int l= levelBTree(Bt->lchild,x,h+1); //子节点的深度为h+1
        if(l!=0)
            return l; //找到目标节点，返回目标节点层数
        else
            return levelBTree(Bt->rchild,x,h+1); //去左子树中寻找目标节点，子节点深度为h+1
    }
}

//判断两棵树形状是否相似
bool likeBTree(BTNode *Bt1,BTNode *Bt2){
    bool like_L,like_R;
    if(Bt1== nullptr && Bt2== nullptr){  //当前位置两个节点不存在，则当前位置形状相似
        return true;
    }else if(Bt1==NULL || Bt2==NULL){ //当前位置两个节点有一个为空，一个不为空,则形状不相似
        return false;
    }else{ //当前位置上两个节点都不为空，继续判断两个节点的左右子树是否都是相似
        like_L= likeBTree(Bt1->lchild,Bt2->lchild); //判断 两节点的左子树是否相似
        like_R= likeBTree(Bt1->rchild,Bt2->rchild); //判断 两节点的右子树是否相似
        return (like_L && like_R); //向上一侧调用返回结果
    }
}

//求k的节点个数，h用于指出当前Bt所处的层号，n用于累计当前层的节点个数
//使用是时候 n=0,h=1,k为指定的行数
void lNodeNumBTree(BTNode *Bt,int h,int k,int &n){
    if(Bt== nullptr)
        return;
    else{
        if(h==k) //当前节点所处的层次为h则，k层节点个数n自增1
            n++;
        lNodeNumBTree(Bt->lchild,h+1,k,n); //获取当前节点左子树上可能存在的k层节点个数
        lNodeNumBTree(Bt->rchild,h+1,k,n); //获取当前节点右子树上可能存在的k层节点个数
    }
}

//输出值为x的节点所有祖先节点
bool ancestorBTree(BTNode *Bt,ElemType x){
    if(Bt== nullptr) //如果当前节点为空发，不是x父节点
        return false;
    else if((Bt->lchild!= nullptr && Bt->lchild->data==x)
            ||
            (Bt->rchild!= nullptr && Bt->rchild->data==x)) { //当前节点Bt的左节点或者右节点为x节点,则打印Bt
        printf("%c", Bt->data);
        return true;
    }else if(ancestorBTree(Bt->lchild,x)
            ||
            ancestorBTree(Bt->rchild,x)) { //x节存在于当前Bt节点的左子树或者右子树上,则打印Bt
        printf("%c", Bt->data);
        return true;
    }else //当前节点 不为x节点的父节点
        return false;
}


//层次遍历Bt树,遍历结果存入result中,resultLength为结果串长度
//调用时result为空，resultLength为0
bool levelOrderBTree(BTNode *Bt,BTNode *result[],int &resultLength){
    if(Bt== nullptr)
        return false;
    //初始化顺序队(由于二叉树的节点数不会太多，这里直接没有使用循环队列)
    SqQueue_BTree qu;
    qu.rear=0;
    qu.front=0;
    //根节点入队
    qu.data[qu.rear]=Bt;
    BTNode *tempNode;
    while(qu.front<=qu.rear){
        //队头节点出队
        tempNode=qu.data[qu.front];
        qu.front++;
        //加入遍历队列
        result[resultLength]=tempNode;
        resultLength++;
        //将左孩子入队
        if(tempNode->lchild){
            //节点加入队尾
            qu.rear++;
            qu.data[qu.rear]=tempNode->lchild;
        }
        //将右孩子入队
        if(tempNode->rchild){
            //节点加入队尾
            qu.rear++;
            qu.data[qu.rear]=tempNode->rchild;
        }
    }
    return true;
}

//创建二叉树，通过先序遍历序列和中序遍历序列
//preResultStr为二叉树的先序遍历序列字符串
//inResultStr为二叉树的中序遍历序列字符串
//n遍历序列的字符串长度
BTNode *createBTreeFromPreOrderAndInOrder(char *preResultStr,char *inResultStr,int n){
    BTNode *root;
    int k;
    if(n<=0) //前序和中序序列表示空树
        return nullptr;
    //创建二叉树 根节点
    root=(BTNode *)malloc(sizeof(BTNode));
    root->data=*preResultStr;
    //在中序序列中找到等于*pre字符(根节点)的位置k
    char *current;
    for(current=inResultStr;current<inResultStr+n;current++)
        if(*current==*preResultStr) //指向根节点的数据
            break;
    k=current-inResultStr; //确定根节点在中序遍历序列中的位置
    //构造左子树
    root->lchild= createBTreeFromPreOrderAndInOrder(
            preResultStr+1,inResultStr,k);
    //右子树
    root->rchild= createBTreeFromPreOrderAndInOrder(
            preResultStr+k+1,current+1,n-k-1);

    //返回根节点
    return root;
}

//创建二叉树，通过后序和中午
//postResultStr为二叉树的后序遍历序列字符串
//inResultStr为二叉树的中序遍历序列字符串
//n遍历序列的字符串长度
BTNode *createBTreeFromPostOrderAndInOrder(char *postResultStr,char *inResultStr,int n){
    int k;
    char r,*p;
    if(n<=0) //后续和中序表示空树
        return nullptr;
    //创建根节点
    BTNode *root=(BTNode *)malloc(sizeof(BTNode));
    root->data=*(postResultStr+n-1);
    //在中序序列中查找到等于*(postResultStr+n-1)字符(根节点)的位置k
    char *current;
    for(current=inResultStr;current<inResultStr+n;current++)
        if(*current==root->data) //指向根节点的数据
            break;
    k=current-inResultStr; //k为根节点在inOrder中的下标位置
    //递归构造左子树
    root->lchild= createBTreeFromPostOrderAndInOrder(
            postResultStr,inResultStr,k);
    //递归构造右子树
    root->rchild= createBTreeFromPostOrderAndInOrder(
            postResultStr+k,current+1,n-k-1);
    //返回根节点
    return root;
}







