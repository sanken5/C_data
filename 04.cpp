/**
*	��̬�����µİ�λ���� 
*/

#include<stdio.h>
#include<stdlib.h>	//malloc��free������ͷ�ļ� 
#define InitSize 10 //Ĭ�ϵ���󳤶�
typedef int ElemType;
typedef struct{
	int  *data;		//ָʾ��̬���������ָ��
	int MaxSize; 	//˳�����������
	int length;  	//˳���ĵ�ǰ���� 
}SeqList; 

void InitList(SeqList &L){
	//��malloc ��������һƬ�����Ĵ洢�ռ�
	L.data =(int*)malloc(InitSize*sizeof(int)) ;
	L.length=0;
	L.MaxSize=InitSize;
}
bool ListInsert(SeqList &L, int i, int e){ 
    //�ж�i�ķ�Χ�Ƿ���Ч
    if(i<1||i>L.length+1) 
        return false;
    if(L.length>L.MaxSize) //��ǰ�洢�ռ����������ܲ���  
        return false;

    for(int j=L.length; j>=i; j--){    //����i��Ԫ�ؼ���֮���Ԫ�غ���
        L.data[j]=L.data[j-1];
    }
    L.data[i-1]=e;  //��λ��i������e
    L.length++;      //���ȼ�1
    return true;
} 
//��λ���� 
ElemType GetElem(SeqList L, int i){
    // ...�ж�i��ֵ�Ƿ�Ϸ�
    return L.data[i-1];      //ע����i-1
}
void print(SeqList &L){
	for(int i=0;i<L.length;i++)		//L.length -> MaxSize �����������
		printf("data[%d]=%d\n",i,L.data[i]);	
}


int main(void){
	SeqList L; //����һ��˳���
	InitList(L);//��ʼ��˳���
	
	ListInsert(L,1,7);
	ListInsert(L,2,4);
	ListInsert(L,3,2);
	
	print(L);
	printf("%d\n",GetElem(L,3)); 
	return 0; 
}