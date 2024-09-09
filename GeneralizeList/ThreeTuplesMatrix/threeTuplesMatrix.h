//
// Created by zhouyuqing on 2024/8/21.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_THREETUPLESMATRIX_H
#define DATASTRUCTUREBYLICHUNBAO_THREETUPLESMATRIX_H

#include<stdio.h>

#define MaxSize 100

typedef int ElemType;

typedef struct{
    int r; //节点行号
    int c; //节点列号
    ElemType  data; //数据域
}TupleNode; //三元组节点

typedef struct{
    int rows; //矩阵行数
    int cols; //矩阵列数
    int nums; //矩阵非零元素个数
    TupleNode nodes[MaxSize]; //非零元素数组
}ThreeTupleMatrix; //三元组矩阵


//通过传入新矩阵 创建 稀疏矩阵
void createThreeTupleMatrix(ThreeTupleMatrix &matrix,int rows,int cols,ElemType A[][MaxSize]);
//给三元组矩阵赋值
bool valueThreeTupleMatrix(ThreeTupleMatrix &matrix,ElemType x,int i,int j);
//获取三元组矩阵指定位置元素的值
bool assignThreeTupleMatrix(const ThreeTupleMatrix &matrix,ElemType &x,int i,int j);
//显示三元组
bool displayThreeTupleMatrix(const ThreeTupleMatrix &matrix);
//三元组矩阵转置
bool transThreeTupleMatrix(const ThreeTupleMatrix &matrix,ThreeTupleMatrix &transMatrix);


#endif //DATASTRUCTUREBYLICHUNBAO_THREETUPLESMATRIX_H


//使用案例
//#include"GeneralizeList/ThreeTuplesMatrix/threeTuplesMatrix.h"
//
//int main(){
//    //创建稀疏矩阵
//    ElemType spareMatrix[][MaxSize]={
//            {11,12,13,14,0},
//            {21,22,23,0,25},
//            {31,32,0,34,35},
//            {41,0,43,44,45},
//            {0,52,53,54,55}
//    };
//    ThreeTupleMatrix matrix_00;
//    createThreeTupleMatrix(matrix_00,5,5,spareMatrix);
//    bool ret= displayThreeTupleMatrix(matrix_00);
//    if(ret== false){
//        perror("展示失败");
//        return -1;
//    }
//
//    printf("\n\n====================================="
//           "=====================================\n\n");
//
//    //设置矩阵元素的值
//    ElemType temp=1996;
//    ret= valueThreeTupleMatrix(matrix_00,temp,2,2);
//    if(ret== false){
//        perror("设置元素值失败");
//        return -1;
//    }
//    ret= displayThreeTupleMatrix(matrix_00);
//    if(ret== false){
//        perror("展示失败");
//        return -1;
//    }
//
//    printf("\n\n====================================="
//           "=====================================\n\n");
//
//    //矩阵转置
//    ThreeTupleMatrix matrix_00_trans;
//    ret= transThreeTupleMatrix(matrix_00,matrix_00_trans);
//    if(ret== false){
//        perror("转置失败");
//        return -1;
//    }
//    ret= displayThreeTupleMatrix(matrix_00_trans);
//    if(ret== false){
//        perror("展示转置矩阵失败");
//        return -1;
//    }
//
//    return 0;
//}
