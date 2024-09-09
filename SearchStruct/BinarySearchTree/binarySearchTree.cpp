//
// Created by zhouyuqing on 2024/9/4.
//

#include"binarySearchTree.h"

//插入BST树
//在二叉排序树中插入一个关键字为key,数据为data的节点.
// 插入成功返回true,插入失败返回false
bool insertBST(BSTNode *&Bt,KeyType key,InfoType data){
    if(Bt==nullptr){ //原树为空,则当前节点为根节点
        Bt=(BSTNode *)malloc(sizeof(BSTNode));
        Bt->key=key;
        Bt->data=data;
        Bt->lchild= nullptr;
        Bt->rchild= nullptr;
        return true;
    }else if(key==Bt->key) { //找到相同关键字节点，则该节点插入失败
        return false;
    }else if(key<Bt->key){  //key的值比当前节点Bt节点小，插入左子树
        return insertBST(Bt->lchild,key,data);
    }else   //key的值比当前节点Bt节点大，插入右子树
        return insertBST(Bt->rchild,key,data);
}

//通过keyArr和dataArr构建BST二叉排序树
//length为keyArr与dataArr的长度
BSTNode *createBST(KeyType keyArr[],InfoType dataArr[],int length){
    //指向BST
    BSTNode *Bt= nullptr;
    //逐个插入节点
    for(int i=0;i<length;i++)
        insertBST(Bt,keyArr[i],dataArr[i]);
    //返回建立好的BST
    return Bt;
}

//二叉排序树查找
//找到后返回节点，找不到返回nullptr
BSTNode *searchBST(BSTNode *Bt,KeyType key){
    if(Bt== nullptr || Bt->key==key) //找到键等于key的节点，直接返回
        return Bt;
    if(key<Bt->key) //key小于当前节点的key，去当前节点的左孩子上找
        return searchBST(Bt->lchild,key);
    else //key大于当前节点的key,去当前接的右孩子上找
        return searchBST(Bt->rchild,key);
}

//返回一棵二叉排序树中的最大结点
BSTNode *maxNodeBST(BSTNode *Bt){
    //找到最右节点并返回
    while(Bt->rchild!= nullptr)
        Bt=Bt->rchild;
    return Bt;
}

//返回一棵二叉排序树中的最小结点
BSTNode *minNodeBST(BSTNode *Bt){
    //找到最左节点并返回
    while(Bt->lchild!= nullptr)
        Bt=Bt->lchild;
    return Bt;
}

//删除带左右孩子的节点
void deleteNodeWithChildren(BSTNode *Bt,BSTNode *&r){
    BSTNode *temp= nullptr;
    if(r->rchild!= nullptr){ //递归找到Bt下最右下节点
        deleteNodeWithChildren(Bt,r->rchild);
    }else{
        //找到Bt左子树的最右下节点r
        //将节点r的值赋给Bt节点
        Bt->key=r->key;
        Bt->data=r->data;
        //r为最右下节点，最多只有左子树
        //让左子节点替代它
        temp=r;
        r=r->lchild;
        //释放原r节点
        free(temp);
    }
}

//在二叉排序树中删除Bt节点
void deleteNode(BSTNode *&Bt){
    BSTNode *temp= nullptr; //存储临时节点
    if(Bt->rchild== nullptr){ //当前Bt没有右子树(或者既没有右子树，也没有左子树),用左子节点取代该节点
        temp=Bt;
        Bt=Bt->lchild;
        free(temp);
    }else if(Bt->lchild== nullptr){ //当前Bt没有左子树,用右子节取代该节点
        temp=Bt;
        Bt=Bt->rchild;
        free(temp);
    }else{ //当前节点有左,右孩子
        deleteNodeWithChildren(Bt,Bt->lchild);
    }
}

//删除键为key的节点
bool deleteNodeBST(BSTNode *&Bt,KeyType key){
    if(Bt== nullptr) //没有找到键为key的节点或者BST树为空
        return false;
    else{
        if(Bt->key > key){ //key小于当前节点key，去左子树中寻找
            deleteNodeBST(Bt->lchild,key);
        }else if(Bt->key < key){ //key大于当前节点key,去右子树中寻找
            deleteNodeBST(Bt->rchild,key);
        }else{
            //找到目标节点，删除目标节点
            deleteNode(Bt);
            return true;
        }
    }
}

