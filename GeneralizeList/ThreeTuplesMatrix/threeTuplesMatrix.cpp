//
// Creamatrix.d by zhouyuqing on 2024/8/21.
//
#include "threeTuplesMatrix.h"

//创建稀疏矩阵
void createThreeTupleMatrix(ThreeTupleMatrix &matrix,int rows,int cols,ElemType A[][MaxSize]){
    //初始化所有三元组节点
    for(int i=0;i<MaxSize;i++) {
        matrix.nodes[i].r=-1;
        matrix.nodes[i].c=-1;
        matrix.nodes[i].data=0;
    }
    //设置初始化稀疏矩阵
    matrix.rows=rows;
    matrix.cols=cols;
    matrix.nums=0;
    //开始插入元素
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(A[i][j]!=0){
                //存储非零元素
                matrix.nodes[matrix.nums].r=i;
                matrix.nodes[matrix.nums].c=j;
                matrix.nodes[matrix.nums].data=A[i][j];
                //非零元素个数+1
                matrix.nums++;
            }
        }
    }
}


//给三元组矩阵赋值
bool valueThreeTupleMatrix(ThreeTupleMatrix &matrix,ElemType x,int i,int j){
    int k=0;
    //i,j位置超过矩阵范围
    if(i>=matrix.rows || j>=matrix.cols)
        return false;
    //找到第i行第一个非0元素
    while(k<matrix.nums && matrix.nodes[k].r<i)
        k++;
    //在第i行非零元素中找j列
    while(k<matrix.nums && matrix.nodes[k].r==i && matrix.nodes[k].c<j)
        k++;
    //存在i行j列的非0元素，修改元素的值
    if(matrix.nodes[k].r==i && matrix.nodes[k].c==j)
        matrix.nodes[k].data=x;
    else{
        //i行j列不存在元素，将k往后的所有元素后移一位
        for(int k1=matrix.nums-1;k1>=k;k1--){
            matrix.nodes[k1+1].r=matrix.nodes[k1].r;
            matrix.nodes[k1+1].c=matrix.nodes[k1].c;
            matrix.nodes[k1+1].data=matrix.nodes[k1].data;
        }
        //插入非零元素x
        matrix.nodes[k].r=i;
        matrix.nodes[k].c=j;
        matrix.nodes[k].data=x;
        //元素数目+1
        matrix.nums+=1;
    }
}

//获取三元组矩阵指定位置元素的值
bool assignThreeTupleMatrix(const ThreeTupleMatrix &matrix,ElemType &x,int i,int j){
    int  k=0;
    //i,j超过矩阵范围
    if(i>=matrix.rows || j>=matrix.cols)
        return false;
    //找到第i行第一个非零元素
    while(k<matrix.nums && matrix.nodes[k].r<i)
        k++;
    //在第i行非零元素中找到第j列
    while(k<matrix.nums && matrix.nodes[k].r==i && matrix.nodes[k].c<j)
        k++;
    //存在i行j列非零元素
    if(matrix.nodes[k].r==i && matrix.nodes[k].c==j) {
        //获取值
        x = matrix.nodes[k].data;
        //获取成功
        return true;
    }else{
        //获取失败
        return false;
    }
}

//显示三元组
bool displayThreeTupleMatrix(const ThreeTupleMatrix &matrix){
    ElemType tempData;
    bool res;

    if(matrix.nums==0){
        //矩阵为空 显示失败
        return false;
    }else{
        printf("|-----------START-------------------\n");
        //矩阵非空 显示所有元素
        printf("matrix--rows:%d;cols:%d;Elements:%d\n",matrix.rows,matrix.cols,matrix.nums);
        //输出所有非零元素
        printf("------------------------------\n");
        for(int i=0;i<matrix.rows;i++) {
            for (int j = 0; j < matrix.cols; j++){
                //获取i行j列的元素
                res=assignThreeTupleMatrix(matrix,tempData,i,j);
                if(res==false){
                    //该位置没有元素
                    printf("%8d",0);
                }else{
                    //打印该位置元素
                    printf("%8d",tempData);
                }
            }
            printf("\n");
        }
        printf("|----------- END -------------------\n");
        //返回显示成功
        return true;
    }
}

//三元组矩阵转置
bool transThreeTupleMatrix(const ThreeTupleMatrix &matrix,ThreeTupleMatrix &transMatrix){
    //矩阵为空  转置失败
    if(matrix.nodes==0)
        return false;
    //记录转置矩阵节点索引
    int k_t=0;

    //设置转置矩阵
    transMatrix.rows=matrix.cols;
    transMatrix.cols=matrix.rows;
    transMatrix.nums=matrix.nums;
    //将matrix中元素转置并加入转置矩阵中
    for(int v=0;v<matrix.cols;v++){ //按照v=0,1,...,matrix.cols-1列访问每列元素
        for(int k=0;k<matrix.nums;k++){ //扫描所有节点
            if(matrix.nodes[k].c==v){
                //找到0~matrix.rows-1行上第j列的元素(如果有)，
                // 将其加入转置矩阵的i行

                //添加到转置矩阵
                transMatrix.nodes[k_t].r=matrix.nodes[k].c;
                transMatrix.nodes[k_t].c=matrix.nodes[k].r;
                transMatrix.nodes[k_t].data=matrix.nodes[k].data;
                k_t++; //转置矩阵节点索引后移
            }

        }
    }

    //转置成功
    return true;
}







