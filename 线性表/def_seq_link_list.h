#ifndef SEQUENCE_lINK_lIST


#define SEQUENCE_lINK_lIST

#define MAXSIZE 100

//˳��� 
typedef int Elemtype;
typedef struct{
	Elemtype a[MAXSIZE];
	int size;
}sequence_list;

//��̬������ 
typedef struct{
	Elemtype *a;
	int size;
}sequence_list2;

//������ 
typedef struct link_node{
	Elemtype info;
	struct link_node *next;
}node,*linklist;

//˫����
typedef struct  Dlnode{
	Elemtype info;
	struct Dlnode *prior;
	struct Dlnode *next;
}dnode, *dlinklist; 






#endif
