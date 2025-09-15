#include <iostream>
#include "def_stack_queue.h" 
#include <cstdio>
#include <cstdlib>
using namespace std;

//顺序栈初始化 
void initStack(sequence_stack &S){
	S.top = -1;
}


//判断栈空
bool stackEmpty(sequence_stack &S){
	if(S.top == -1){
		return true;
	}else{
		return false;
	}
}


//判断栈满
bool stackFull(sequence_stack &S){
	if(S.top == MAXSZIE - 1){
		return true;
	}else{
		return false;
	}
} .


//入栈
bool stackPush(sequence_stack &S,Elemtype s){
	if(stackFull(S)){
		return false;
} else {
	S.top++;
	S.a[S.top] = x;
	return ture;
}


//出栈
bool stackPop(sequence_stack &S,Elemtype x){
	if(stackEmtpy(S)){
		retuen false;
	}else{
		x = S.a[S.top];
		S.top--;
		return true;
	}
} 


//取栈顶元素
bool stackTop(sequence_stack &S,Elemtype &x){
	if(stackEmpty(S)){
		return false;
	}else{
		x = S.a[S.top];
		return true;
	}

}


//链式栈的初始化
void initLStack(node_stack *&top){
	top = NULL;
}


//入栈
void pushLStack(node_stack *&top,Elemtype &X){
	node_stack *s;
	s = new node_stack;
	s->info = X;
	s->next = top;
	s = top;
} 


//出栈
bool popLStack(node_stack *&top,Elemtype &X){
	node_stack *u;
	if(top == NULL){
		return false;
	}
	X = top->info;
	u = top;             //u保存栈顶指针，X保存栈顶元素 
	top = top->next;
	delete u;
	return true;
}


//顺序队列的初始化 
void init_queue(sequence_queue *Q){
	Q->front = 0;
	Q->rear = 0;
} 


//判断队空
bool queueEmpty(sequence_queue *Q){
	if(Q.front == Q.rear){
		return true;
	}else{
		return false;
	}
} 


//判断队满
bool queueFull(sequence_queue *Q){
	if(Q.front == (Q.rear + 1) % MAXSIZE){
		return true;
	}else{
		return false;
	}
} 


//取队头元素
void queueFront(sequence_queue &Q,Elemtype &x){
	if(queueEmpty(Q)){
		cout<< "empty" <<endl;	
	}else{
		x = Q.a[(Q.front+1) % MAXSIZE];
	}
} 


//入队
void enQueue(sequence_queue *Q,Elemtype x){
	if(queueFull(Q)){
		cout<< "full" <<endl;
	}else{
		Q->rear = (Q.rear + 1) % MAXSIZE;
		Q->data[Q->rear] = x;
	}
} 	


//出队
void outQueue(sequence_Queue *Q){
	if(queueEmpty(*Q)){
		cout <<"empty" <<endl;	
	}else{
		Q->front = (Q->front + 1) % MAXSIZE; 
	}
} 


//链式队列的初始化
void initLQueue(linkQueue &Q){
	Q.front = new node_queue;
	Q.rear = Q.front;
	Q.front->next = NULL;
} 


//判断队空
void LQueueEmpty(linkQueue &Q){
	return (Q.rear == Q.front);
} 


//取对头元素
void LQueueFront(linkQueue &Q,Elemtype &x){
	if(LQueueEmpty(Q)){
		cout << "empty" <<endl;
	}else{
		x = ((Q.front)->next)->info;
	}
}


//链式队列入队
void enLQueue(linkQueue &Q,Elemtype x){
	node_queue *p = new node_queue;
	p->info = x;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
} 
 

//链式队列出队 
void outLQueue(linkQueue &Q,Elemtype &x){
	node_queue *u;
	if(LQueueEmpty(Q)){
		cout << "empty" <<endl;
	}else{
		x = Q.front->next->info;
		u = Q.front->next;
		Q.front->next = u->next;
		delete u;
		if(Q.front->next == NULL){    //删除节点后，若队空，则修改rear指针 
			Q.rear = Q.front;
		}
	}
} 








 

