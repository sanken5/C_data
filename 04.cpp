/**
*	动态数组下的按位查找 
*/

#include<stdio.h>
#include<stdlib.h>	//malloc、free函数的头文件 
#define InitSize 10 //默认的最大长度
typedef int ElemType;
typedef struct{
	int  *data;		//指示动态分配数组的指针
	int MaxSize; 	//顺序表的最大容量
	int length;  	//顺序表的当前长度 
}SeqList; 

void InitList(SeqList &L){
	//用malloc 函数申请一片连续的存储空间
	L.data =(int*)malloc(InitSize*sizeof(int)) ;
	L.length=0;
	L.MaxSize=InitSize;
}
bool ListInsert(SeqList &L, int i, int e){ 
    //判断i的范围是否有效
    if(i<1||i>L.length+1) 
        return false;
    if(L.length>L.MaxSize) //当前存储空间已满，不能插入  
        return false;

    for(int j=L.length; j>=i; j--){    //将第i个元素及其之后的元素后移
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;  //在位置i处放入e
    L.length++;      //长度加1
    return true;
} 
//按位查找 
ElemType GetElem(SeqList L, int i){
    // ...判断i的值是否合法
    return L.data[i-1];      //注意是i-1
}
void print(SeqList &L){
	for(int i=0;i<L.length;i++)		//L.length -> MaxSize 会产生脏数据
		printf("data[%d]=%d\n",i,L.data[i]);	
}


int main(void){
	SeqList L; //声明一个顺序表
	InitList(L);//初始化顺序表
	
	ListInsert(L,1,7);
	ListInsert(L,2,4);
	ListInsert(L,3,2);
	
	print(L);
	printf("%d\n",GetElem(L,3)); 
	return 0; 
}