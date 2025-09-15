#ifndef SEQUENCE_lINK_lIST


#define SEQUENCE_lINK_lIST

#define MAXSIZE 100

//顺序表 
typedef int Elemtype;
typedef struct{
	Elemtype a[MAXSIZE];
	int size;
}sequence_list;

//动态数组形 
typedef struct{
	Elemtype *a;
	int size;
}sequence_list2;

//单链表 
typedef struct link_node{
	Elemtype info;
	struct link_node *next;
}node,*linklist;

//双链表
typedef struct  Dlnode{
	Elemtype info;
	struct Dlnode *prior;
	struct Dlnode *next;
}dnode, *dlinklist; 






#endif
