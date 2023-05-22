#include<stdio.h>
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//初始化一个空的单链表
bool InitList(LinkList &L){  //注意用引用 &
    L = NULL; //空表，暂时还没有任何结点；
    return true;
}

//判断单链表是否为空
bool Empty(LinkList L){
    return (L == NULL);
}
  
int main(void){
    LinkList L;  //声明一个指向单链表的指针: 头指针
    //初始化一个空表
    InitList(L);
    if(Empty(L))printf("链表为空"); 
    //...
}
