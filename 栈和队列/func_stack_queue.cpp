#include <iostream>
#include "def_stack_queue.h" 
#include <cstdio>
#include <cstdlib>
using namespace std;

//˳��ջ��ʼ�� 
void initStack(sequence_stack &S){
	S.top = -1;
}


//�ж�ջ��
bool stackEmpty(sequence_stack &S){
	if(S.top == -1){
		return true;
	}else{
		return false;
	}
}


//�ж�ջ��
bool stackFull(sequence_stack &S){
	if(S.top == MAXSZIE - 1){
		return true;
	}else{
		return false;
	}
} .


//��ջ
bool stackPush(sequence_stack &S,Elemtype s){
	if(stackFull(S)){
		return false;
} else {
	S.top++;
	S.a[S.top] = x;
	return ture;
}


//��ջ
bool stackPop(sequence_stack &S,Elemtype x){
	if(stackEmtpy(S)){
		retuen false;
	}else{
		x = S.a[S.top];
		S.top--;
		return true;
	}
} 


//ȡջ��Ԫ��
bool stackTop(sequence_stack &S,Elemtype &x){
	if(stackEmpty(S)){
		return false;
	}else{
		x = S.a[S.top];
		return true;
	}

}


//��ʽջ�ĳ�ʼ��
void initLStack(node_stack *&top){
	top = NULL;
}


//��ջ
void pushLStack(node_stack *&top,Elemtype &X){
	node_stack *s;
	s = new node_stack;
	s->info = X;
	s->next = top;
	s = top;
} 


//��ջ
bool popLStack(node_stack *&top,Elemtype &X){
	node_stack *u;
	if(top == NULL){
		return false;
	}
	X = top->info;
	u = top;             //u����ջ��ָ�룬X����ջ��Ԫ�� 
	top = top->next;
	delete u;
	return true;
}


//˳����еĳ�ʼ�� 
void init_queue(sequence_queue *Q){
	Q->front = 0;
	Q->rear = 0;
} 


//�ж϶ӿ�
bool queueEmpty(sequence_queue *Q){
	if(Q.front == Q.rear){
		return true;
	}else{
		return false;
	}
} 


//�ж϶���
bool queueFull(sequence_queue *Q){
	if(Q.front == (Q.rear + 1) % MAXSIZE){
		return true;
	}else{
		return false;
	}
} 


//ȡ��ͷԪ��
void queueFront(sequence_queue &Q,Elemtype &x){
	if(queueEmpty(Q)){
		cout<< "empty" <<endl;	
	}else{
		x = Q.a[(Q.front+1) % MAXSIZE];
	}
} 


//���
void enQueue(sequence_queue *Q,Elemtype x){
	if(queueFull(Q)){
		cout<< "full" <<endl;
	}else{
		Q->rear = (Q.rear + 1) % MAXSIZE;
		Q->data[Q->rear] = x;
	}
} 	


//����
void outQueue(sequence_Queue *Q){
	if(queueEmpty(*Q)){
		cout <<"empty" <<endl;	
	}else{
		Q->front = (Q->front + 1) % MAXSIZE; 
	}
} 


//��ʽ���еĳ�ʼ��
void initLQueue(linkQueue &Q){
	Q.front = new node_queue;
	Q.rear = Q.front;
	Q.front->next = NULL;
} 


//�ж϶ӿ�
void LQueueEmpty(linkQueue &Q){
	return (Q.rear == Q.front);
} 


//ȡ��ͷԪ��
void LQueueFront(linkQueue &Q,Elemtype &x){
	if(LQueueEmpty(Q)){
		cout << "empty" <<endl;
	}else{
		x = ((Q.front)->next)->info;
	}
}


//��ʽ�������
void enLQueue(linkQueue &Q,Elemtype x){
	node_queue *p = new node_queue;
	p->info = x;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
} 
 

//��ʽ���г��� 
void outLQueue(linkQueue &Q,Elemtype &x){
	node_queue *u;
	if(LQueueEmpty(Q)){
		cout << "empty" <<endl;
	}else{
		x = Q.front->next->info;
		u = Q.front->next;
		Q.front->next = u->next;
		delete u;
		if(Q.front->next == NULL){    //ɾ���ڵ�����ӿգ����޸�rearָ�� 
			Q.rear = Q.front;
		}
	}
} 








 

