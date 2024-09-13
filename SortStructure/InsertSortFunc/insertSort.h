//
// Created by zhouyuqing on 2024/9/11.
//

#ifndef DATASTRUCTUREBYLICHUNBAO_INSERTSORT_H
#define DATASTRUCTUREBYLICHUNBAO_INSERTSORT_H

#include "../sortGeneralStructure.h"

//插入排序算法
void straightInsertSort(RecType rects[],int lengthRects);

//折半插入排序
void binInsertSort(RecType rects[],int lengthRects);


//希尔排序
void shellSort(RecType rects[],int lengthRects);

#endif //DATASTRUCTUREBYLICHUNBAO_INSERTSORT_H

//使用案例
//
//#include"SortStructure/InsertSortFunc/insertSort.h"
//
//int main(){
//    //无序数组
//    RecType rects[10];
//    int rectsLength=10;
//    rects[0].key=90;
//    rects[0].data='a';
//    rects[1].key=23;
//    rects[1].data='b';
//    rects[2].key=11;
//    rects[2].data='c';
//    rects[3].key=89;
//    rects[3].data='d';
//    rects[4].key=76;
//    rects[4].data='e';
//    rects[5].key=77;
//    rects[5].data='f';
//    rects[6].key=88;
//    rects[6].data='g';
//    rects[7].key=79;
//    rects[7].data='h';
//    rects[8].key=80;
//    rects[8].data='i';
//    rects[9].key=56;
//    rects[9].data='j';
//    //无序数组2
//    RecType rects_2[10];
//    for(int i=0;i<rectsLength;i++){
//        rects_2[i].key=rects[i].key;
//        rects_2[i].data=rects[i].data;
//    }
//
//    //无序数组3
//    RecType rects_3[10];
//    for(int i=0;i<rectsLength;i++){
//        rects_3[i].key=rects[i].key;
//        rects_3[i].data=rects[i].data;
//    }
//
//    //直接插入排序
//    printf("\n直接插入排序\n");
//    printf("原数组:\n");
//    for(int i=0;i<rectsLength;i++)
//        printf("key:%d value:%c ; ",rects[i].key,rects[i].data);
//    straightInsertSort(rects,rectsLength);
//    printf("\n排序后数组:\n");
//    for(int i=0;i<rectsLength;i++)
//        printf("key:%d value:%c ; ",rects[i].key,rects[i].data);
//
//    printf("\n--------------------------------------------------\n");
//
//    //折半插入排序
//    printf("\n折半插入排序\n");
//    printf("原数组:\n");
//    for(int i=0;i<rectsLength;i++)
//        printf("key:%d value:%c ; ",rects_2[i].key,rects_2[i].data);
//    binInsertSort(rects_2,rectsLength);
//    printf("\n排序后数组:\n");
//    for(int i=0;i<rectsLength;i++)
//        printf("key:%d value:%c ; ",rects_2[i].key,rects_2[i].data);
//
//    printf("\n--------------------------------------------------\n");
//
//    //希尔排序
//    printf("\n希尔排序\n");
//    printf("原数组:\n");
//    for(int i=0;i<rectsLength;i++)
//        printf("key:%d value:%c ; ",rects_3[i].key,rects_3[i].data);
//    shellSort(rects_3,rectsLength);
//    printf("\n排序后数组:\n");
//    for(int i=0;i<rectsLength;i++)
//        printf("key:%d value:%c ; ",rects_3[i].key,rects_3[i].data);
//
//
//    return 0;
//}

