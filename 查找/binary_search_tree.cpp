#include <iostream>
typedef int Elemtype;
typedef struct node{
	Elemtype key;
	struct node *lChild;
	struct node *rChild;
}Bnode; 

//BST的查找(迭代)
Bnode *Search(Bnode *T,Elemtype x){
	Bnode *p = T;
	while(p != NULL){
		if(p->key == x){
			return p; 
		}
		if(p->key > x){
			p = p->lChild;
		}else{
			p = p->rChild;
		}
	}
	return p;
}


//BST的查找（递归）
Bnode *SearchRecursion(Bnode *T,Elemtype x){
	if(T == NULL || T->key == x){
		return T;
	}
	if(T->key > x){
		return SearchRecursion(T->lChild,x);
	}else{
		return SearchRecursion(T->rChild,x);
	}
}


//BST的插入 
void insertBST(Bnode *&T,Bnode *S){
	if(T == NULL){
		T = S;
		return;
	}
	if(S == NULL){
		return;
	}
	if (S->key == T->key) {
        return;
	}
	if(S->key < T->key){
		insertBST(T->lChild,S);
	}else{
		insertBST(T->rChild,S);
	}
} 



int main(){
	return 0;
}

















