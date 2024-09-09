//
// Created by zhouyuqing on 2024/8/14.
//

#include"sqString.h"

//建立顺序串并赋值
void assignSqString(SqString &Sq,const char *cstr){
    int i;
    //设置顺序串
    for(i=0;cstr[i]!='\0';i++)
        Sq.data[i]=cstr[i]; //data不含结束标志位'\0'
    //设置顺序串长度
    Sq.length=i; //长度不计入结束标志位
}

//将其他顺序串复制给顺序串
void copySqString(SqString &Sq,const SqString &SqOther){
    int i;
    //将字符串拷贝到顺序串中
    for(i=0;i<SqOther.length;i++)
        Sq.data[i]=SqOther.data[i];
    //设置长度
    Sq.length=SqOther.length;
}

//判断两个顺序串是否相等
bool equalSqString(SqString &Sq,const SqString &SqOther){
    if(Sq.length!=SqOther.length)
        //如果长度不等，返回false
        return false;
    else{
        //比较每个字符是否相等
        for(int i=0;i<Sq.length;i++)
            //有字符不等则顺序串不等
            if(Sq.data[i]!=SqOther.data[i])
                return false;
        return true;
    }
}

//获取顺序串长度
int lengthSqString(SqString &Sq){
    return Sq.length;
}

//串拼接
SqString concatSqString(const SqString &Sq,SqString SqOther){
    //定义结果串
    SqString result;
    //为结果串赋值
    result.length=Sq.length+SqOther.length;
    //拼接字符串
    for(int i=0;i<Sq.length;i++)
        result.data[i]=Sq.data[i];
    for(int i=0;i<SqOther.length;i++)
        result.data[i+Sq.length]=SqOther.data[i];
    //返回结果串
    return result;
}

//求子串 pos位置开始 且长度length
bool subStrSqString(const SqString &Sq,int pos,int length,SqString &result){
    //定义子串
    SqString subStr;
    subStr.length=length;
    //判断pos和length取值是否在范围内
    if(pos<=0 || pos>Sq.length || length<0 || pos+length-1>Sq.length)
        return false;
    //获取子串数据
    int index=0;
    for(int i=pos-1;i<pos+length-1;i++)
        result.data[index++]=Sq.data[i];
    result.length=index;
    return true;
}

//子串的插入 pos位置开始
bool insertStrSqString(const SqString &Sq,int pos,const SqString &subStr,SqString &result){
    //判断pos取值 正确范围(1~Sq.length+1)之间,
    // 当等于Sq.lengt+1时表示在最后一个元素后插入子串
    if(pos<=0 || pos>Sq.length+1)
        return false;
    //开始插入子串
    int index=0;
    result.length=Sq.length+subStr.length;
    for(int i=0;i<pos-1;i++) //将原字符串0~pos-2位置上的元素加入结果串
        result.data[index++]=Sq.data[i];
    for(int i=0;i<subStr.length;i++) //将要插入子串0~subStr.lenght-1位置上的元素加入结果串
        result.data[index++]=subStr.data[i];
    for(int i=pos-1;i<Sq.length;i++) //将原字符串pos-1~Sq.length-1位置上的元素加入结果串
        result.data[index++]=Sq.data[i];
    //设置子串长度
    result.length=index;
    return true;
}

//子串的删除 pos位置开始 且长度length
bool deleteStrSqString(const SqString &Sq,int pos,int length,SqString &result){
    //判断pos与length取值是否在范围内
    if(pos<=0 || pos>Sq.length || pos+length-1>Sq.length)
        return false;
    int index=0;
    for(int i=0;i<pos-1;i++)  //将0~pos-2位置上的元素 加入结果串
        result.data[index++] = Sq.data[i];
    for(int i=pos+length-1;i<Sq.length;i++) //将pos+length-1~Sq.length-1位置上的元素 加入结果串
        result.data[index++]=Sq.data[i];
    result.length=index;
    return true;
}

//顺序串的替换，将pos开始 长度为length的 元素替换为子串
bool replaceStrSqString(const SqString &Sq,int pos,int length,const SqString &subStr,SqString &result){
    //判断pos与length取值是否在范围内
    if(pos<=0 || pos>Sq.length || pos+length-1>Sq.length)
        return false;
    int index=0;
    for(int i=0;i<pos-1;i++) //将 主串 0~pos-2位置上元素 加入结果串
        result.data[index++]=Sq.data[i];
    for(int i=0;i<subStr.length;i++) //将 子串 0~subStr.length-1位置上的元素加入结果串
        result.data[index++]=subStr.data[i];
    for(int i=pos+length-1;i<Sq.length;i++) //将 主串 pos+length-1~Sq.length-1位置上的元素加入结果传
        result.data[index++]=Sq.data[i];
    result.length=index;
    return true;
}

//显示顺序串
void displayStrSqString(const SqString &Sq){
    for(int i=0;i<Sq.length;i++)
        printf("%c",Sq.data[i]);
    printf("\n");
}


//获取next数组
void getNextSqString(SqString t,int next[]){
    int j,k;
    j=0;
    k=-1;
    next[0]=-1;
    while(j<t.length-1){
        if(k==-1 || t.data[j]==t.data[k]){
            j++;
            k++;
            next[j]=k;
        }else
            k=next[k];
    }
}

//使用next数组来进行匹配
int KMPIndexSqString(const SqString &Li,const SqString &subStr){
    int next[MaxSize],i=0,j=0;
    getNextSqString(Li,next);
    while(i<Li.length && j<subStr.length){
        if(j==-1 || Li.data[i]==subStr.data[j]){
            i++; //i,j各增1
            j++;
        }else
            j=next[j]; //i不变，j后退
    }
    if(j>=subStr.length)
        return i-subStr.length; //返回子串位置
    else
        return -1; //返回匹配失败
}





