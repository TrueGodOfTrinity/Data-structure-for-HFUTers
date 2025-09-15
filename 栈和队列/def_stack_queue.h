#ifndef  DEF_STACK_QUEUE
#define  DEF_STACK_QUEUE


#define MAXSIZE 100
typedef int Elemtype;
//˳��ջ
typedef struct {
	Elemtype a[MAXSIZE];
	int top;
}sequence_stack;

//˳�����
typedef struct {
	Elemtype a[MAXSIZE];
	int front;
	int rear;
}sequence_queue;

//��ջ
typedef struct link_stack{ 
	Elemtype info;
	struct link_stack *next;
}node_stack,*link_stack; 

//��ʽ����
typedef struct link_queue{
	Elemtype info;
	struct link_queue *next;
}node_queue;

typedef struct{
	node_queue *front,*rear;
}linkQueue;

#endif
