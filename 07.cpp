#include<stdio.h>
#include<stdlib.h>
typedef int ElemType;

typedef struct LNode{
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;

//��ʼ��һ����������ͷ��㣩
bool InitList(LinkList &L){  
    L = (LNode*) malloc(sizeof(LNode));  //ͷָ��ָ��Ľ�㡪������һ��ͷ��㣨���洢���ݣ�
    if (L == NULL)          //�ڴ治�㣬����ʧ��
        return false;
    L -> next = NULL;       //ͷ���֮����ʱ��û�н��
    return true;
}

//�жϵ������Ƿ�Ϊ�գ���ͷ��㣩
bool Empty(LinkList L){
    return (L->next == NULL);
}
int main(void){
    LinkList L;  //����һ��ָ�������ָ��: ͷָ��
    //��ʼ��һ���ձ�
    InitList(L);
    //...
    if(Empty(L))printf("����Ϊ��"); 
}


