/**
	�þ�̬����ʵ��˳�������Ӳ��� 
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

void print(SqList &L){
	if(ListInsert(L,2,3)){
		printf("������\n");
	}
	for(int i=0;i<L.length;i++)		//L.length -> MaxSize �����������
		printf("data[%d]=%d\n",i,L.data[i]);	
}

int main(void){
	SqList L;//����һ��˳���
	InitList(L);//��ʼ��һ��˳���
	
	ListInsert(L,1,2);
	print(L);
	return 0; 
}
