#include <cstdio>
#include <cstdlib>
#include "def_seq_link_list.h"
#include <iostream>

using namespace std;

//建立一个空的单链表 
node *init(){
	return NULL;
}

//带头节点
node *init_(){
	node *head;
	head = new node;
	head ->next = NULL;
	return head;
} 

//在单链表中查找第i个节点
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
	
//单链表中的插入(第i个节点后)
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


//单链表的删除操作 
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
/*如果只需要访问指针指向的内容，使用node *L
如果要修改指针本身的指向，使用 node *&L或者node **L 
*/ 

                               
//尾插法建立单链表
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



//头插法建立单链表
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
 

//双链表的初始化(带头节点)
void init_dlinklist(dnode *&head){
	head = new dnode;
	head->next = NULL;
}

 

int main(){
	return 0;
}
















 
