#include <cstdio>
#include <cstdlib>
#include "def_seq_link_list.h"
#include <iostream>

using namespace std;

//����һ���յĵ����� 
node *init(){
	return NULL;
}

//��ͷ�ڵ�
node *init_(){
	node *head;
	head = new node;
	head ->next = NULL;
	return head;
} 

//�ڵ������в��ҵ�i���ڵ�
node *find(node *head,int i){
	int j = 0;
	node *p = head;
	if(i < 1){
		printf("error/n");
		return NULL;
	}
	while(p && j != i){
		p = p->next;
		j++;
	}	
	return p;
}
	
//�������еĲ���(��i���ڵ��)
node *insert(node *head,Elemtype x,int i){
	node *p ,*q;
	q = find(head,i);
	if(!q && i != 0){
		cout << "error" << endl;
	}else{
		p = new node;
		p->info = x;
		if(i == 0){
		    p->next = head;
		    head = p;
	    }else{
		    p->next = q->next;
		    q->next = p;
	    }
}
	return head;	
} 


//�������ɾ������ 
node *dele(node *head, Elemtype x){
	node *pre = head, *q;	q = head->next;
	while(q && q->info != x){
		pre = q;
		q = q->next;
	}
	if(q){	
		pre->next = q->next;
		delete q;
	}
	return head;
}
/*���ֻ��Ҫ����ָ��ָ������ݣ�ʹ��node *L
���Ҫ�޸�ָ�뱾���ָ��ʹ�� node *&L����node **L 
*/ 

                               
//β�巨����������
void tail_insert(node *&head){
	Elemtype x;
	node *p,*rear;
	head = new node;
	rear = head;
	cin >> x;
	while(x != 999){
		p = new node;
		p->info = x;
		p->next = NULL;
		rear->next = p;
		rear = p;
		cin >>x;
	}
}



//ͷ�巨����������
void head_insert(node *&head){
	node *p;
	Elemtype x;
	head = new node;
	head->next = NULL;
	cin >> x;
	while(x != 999){
		p = new node;
		p->info = x;
		p->next = head->next;
		head->next = p;
		cin >> x;
	}
} 
 

//˫����ĳ�ʼ��(��ͷ�ڵ�)
void init_dlinklist(dnode *&head){
	head = new dnode;
	head->next = NULL;
}

 

int main(){
	return 0;
}
















 
