#include <cstdio>
#include <cstdlib>
#include "def_seq_link_list.h"
#include <iostream>

//�ÿձ���ʼ����
void init(sequence_list *slt){
	slt->size = 0;
}


//�������(��β)
void append(sequence_list *slt,Elemtype x){
	if(slt->size = MAXSIZE){
		printf("full/n");
		exit(1); 
	}
	slt->a[slt->size] = x;
	slt->size++;
} 


//����ֵΪx�Ľڵ�λ�� 
int find(sequence_list slt,Elemtype x){
	int i = 0;
	while(i < slt.size && slt.a[i] != x){
		return (i < slt.size?i:-1);
	}
} 

//���м����Ԫ��
void insert(sequence_list *slt,Elemtype x,int position){
	if(slt->size == MAXSIZE){
		printf("full/n");
		exit(1);
	}
	if(position < 0||position > slt->size){
		printf("error/n");
		exit(1);
	}
	for(int i = slt->size; i > position;i--){
		slt->a[i] = slt->a[i - 1];
	}
	slt->a[position] = x; 
	slt->size++;
}


//ɾ�����е�positionλ�õ�Ԫ��
void dele(sequence_list *slt, int position){
	if(slt->size == 0){
		printf("empty/n");
		exit(1);
	}
	if(position < 0||position >= slt->size){
		printf("error/n");
		exit(1);
	}
	for(int i = position; i < slt->size-1;i++){
		slt->a[i] = slt->a[i+1];
	}
	slt->size--;
}















































































int main(){

	return 0;
}
