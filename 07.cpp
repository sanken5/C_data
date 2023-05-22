#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//初始化一个单链表（带头结点）
bool InitList(LinkList &L){  
    L = (LNode*) malloc(sizeof(LNode));  //头指针指向的结点——分配一个头结点（不存储数据）
    if (L == NULL)          //内存不足，分配失败
        return false;
    L -> next = NULL;       //头结点之后暂时还没有结点
    return true;
}

//判断单链表是否为空（带头结点）
bool Empty(LinkList L){
    return (L->next == NULL);
}
int main(void){
    LinkList L;  //声明一个指向单链表的指针: 头指针
    //初始化一个空表
    InitList(L);
    //...
    if(Empty(L))printf("链表为空"); 
}


