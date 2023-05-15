/**
	用静态数组实现顺序表的删除操作 
*/

#include<stdio.h>
#define MaxSize 10   //定义线性表的最大长度 
typedef struct{
	int data[MaxSize];	//用静态的"数组"存放数据元素
	int length; 		//顺序表的当前长度  
}SqList;       			//顺序表的类型定义(静态分配方式)

void InitList(SqList &L){		//没有设置数据元素的默认值
	 L.length=0;
}
//在顺序表L的第k个位置插入元素e
bool ListInsert(SqList &L, int i, int e){ 
    if(i<1||i>L.length+1) 	//判断i的范围是否有效
        return false;
    if(L.length>MaxSize) //当前存储空间已满，不能插入  
        return false;

    for(int j=L.length; j>=i; j--){    //将第i个元素及其之后的元素后移
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;		//在位置i处放入e
    L.length++;			//长度加1
    return true;
}
//删除 顺序表L的第个元素  e
bool ListDelete(SqList &L, int i, int &e){ // e--引用型参数，返回被删除的元素
    if(i<1||i>L.length)		//判断i的范围是否有效
        return false;

    e = L.data[i-1];		//将被删除的元素赋值给e

    for(int j=L.length; j>=i; j--){    //将第i个后的元素前移
        L.data[j-1]=L.data[j];
    }
    L.length--;      //长度减1
    return true;
}

void print(SqList &L){
	if(ListInsert(L,2,3)){
		printf("已增加\n");
	}
	for(int i=0;i<L.length;i++)		//L.length -> MaxSize 会产生脏数据
		printf("data[%d]=%d\n",i,L.data[i]);	
}

int main(void){
	int e=-1; 
	SqList L;//声明一个顺序表
	InitList(L);//初始化一个顺序表
	
	ListInsert(L,1,2);
	print(L);
	ListInsert(L,3,2);
	
	if(ListDelete(L,3,e))
		printf("已删除第三个元素，删除元素的值为=%d\n",e);
	else
		printf("位序i不合法，删除失败\n");
	return 0; 
}
