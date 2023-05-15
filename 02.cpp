/**
	�þ�̬����ʵ��˳����ɾ������ 
*/

#include<stdio.h>
#define MaxSize 10   //�������Ա����󳤶� 
typedef struct{
	int data[MaxSize];	//�þ�̬��"����"�������Ԫ��
	int length; 		//˳���ĵ�ǰ����  
}SqList;       			//˳�������Ͷ���(��̬���䷽ʽ)

void InitList(SqList &L){		//û����������Ԫ�ص�Ĭ��ֵ
	 L.length=0;
}
//��˳���L�ĵ�k��λ�ò���Ԫ��e
bool ListInsert(SqList &L, int i, int e){ 
    if(i<1||i>L.length+1) 	//�ж�i�ķ�Χ�Ƿ���Ч
        return false;
    if(L.length>MaxSize) //��ǰ�洢�ռ����������ܲ���  
        return false;

    for(int j=L.length; j>=i; j--){    //����i��Ԫ�ؼ���֮���Ԫ�غ���
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;		//��λ��i������e
    L.length++;			//���ȼ�1
    return true;
}
//ɾ�� ˳���L�ĵڸ�Ԫ��  e
bool ListDelete(SqList &L, int i, int &e){ // e--�����Ͳ��������ر�ɾ����Ԫ��
    if(i<1||i>L.length)		//�ж�i�ķ�Χ�Ƿ���Ч
        return false;

    e = L.data[i-1];		//����ɾ����Ԫ�ظ�ֵ��e

    for(int j=L.length; j>=i; j--){    //����i�����Ԫ��ǰ��
        L.data[j-1]=L.data[j];
    }
    L.length--;      //���ȼ�1
    return true;
}

void print(SqList &L){
	if(ListInsert(L,2,3)){
		printf("������\n");
	}
	for(int i=0;i<L.length;i++)		//L.length -> MaxSize �����������
		printf("data[%d]=%d\n",i,L.data[i]);	
}

int main(void){
	int e=-1; 
	SqList L;//����һ��˳���
	InitList(L);//��ʼ��һ��˳���
	
	ListInsert(L,1,2);
	print(L);
	ListInsert(L,3,2);
	
	if(ListDelete(L,3,e))
		printf("��ɾ��������Ԫ�أ�ɾ��Ԫ�ص�ֵΪ=%d\n",e);
	else
		printf("λ��i���Ϸ���ɾ��ʧ��\n");
	return 0; 
}
