/**
	用静态数组实现顺序表的按位查找操作 
*/

#include<stdio.h>
#define MaxSize 10   //定义线性表的最大长度 
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];	//用静态的"数组"存放数据元素
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

//按位查找 
ElemType GetElem(SqList L, int i){
    // ...判断i的值是否合法
    return L.data[i-1];      //注意是i-1
}

void print(SqList &L){
	for(int i=0;i<L.length;i++)		//L.length -> MaxSize 会产生脏数据
		printf("data[%d]=%d\n",i,L.data[i]);	
}

int main(void){
	int e=-1; 
	SqList L;//声明一个顺序表
	InitList(L);//初始化一个顺序表
	
	ListInsert(L,1,7);
	ListInsert(L,2,4);
	ListInsert(L,3,2);
	print(L);
	printf("%d\n",GetElem(L,3)); 

	return 0; 
}
