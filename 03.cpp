/**
	�þ�̬����ʵ��˳���İ�λ���Ҳ��� 
*/

#include<stdio.h>
#define MaxSize 10   //�������Ա����󳤶� 
typedef int ElemType;
typedef struct{
	ElemType data[MaxSize];	//�þ�̬��"����"�������Ԫ��
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

//��λ���� 
ElemType GetElem(SqList L, int i){
    // ...�ж�i��ֵ�Ƿ�Ϸ�
    return L.data[i-1];      //ע����i-1
}

void print(SqList &L){
	for(int i=0;i<L.length;i++)		//L.length -> MaxSize �����������
		printf("data[%d]=%d\n",i,L.data[i]);	
}

int main(void){
	int e=-1; 
	SqList L;//����һ��˳���
	InitList(L);//��ʼ��һ��˳���
	
	ListInsert(L,1,7);
	ListInsert(L,2,4);
	ListInsert(L,3,2);
	print(L);
	printf("%d\n",GetElem(L,3)); 

	return 0; 
}
