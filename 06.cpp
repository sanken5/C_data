#include<stdio.h>
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//��ʼ��һ���յĵ�����
bool InitList(LinkList &L){  //ע�������� &
    L = NULL; //�ձ���ʱ��û���κν�㣻
    return true;
}

//�жϵ������Ƿ�Ϊ��
bool Empty(LinkList L){
    return (L == NULL);
}
  
int main(void){
    LinkList L;  //����һ��ָ�������ָ��: ͷָ��
    //��ʼ��һ���ձ�
    InitList(L);
    if(Empty(L))printf("����Ϊ��"); 
    //...
}
