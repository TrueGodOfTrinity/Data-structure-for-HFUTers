#include <iostream>
#include "binary_tree.h" 
#include <cmath>

using namespace std;
//访问节点
void visit(BiNode *T){
	if(T != nullptr){
		cout << T->data <<endl;
	}else{
		cout <<"nullptr"<<endl; 
	}
} 


//二叉树的遍历
//先序遍历
void preOrderTraverse(BiNode *T){
	if(T){
		visit(T);   //访问根节点 
		preOrderTraverse(T->lChild);     //递归调用先序遍历左子树 
		preOrderTraverse(T->rChild);	 //递归调用先序遍历右子树 
	}
} 

 
//中序遍历 
void inOrderTraverse(BiNode *T){
	if(T){
		inOrderTraverse(T->lChild);
		visit(T);
		inOrderTraverse(T->rChild);	
	}
}


//后序遍历
void postOrderTraverse(BiNode *T){
	if(T){
		postOrderTraverse(T->lChild);
		postOrderTraverse(T->rChild);
		visit(T);
	}
}


//二叉树的建立（基于“二叉链表”） 
//创建子树
void creatSubTree(BiNode *q,int k){
	BiNode *u;
	Elemtype x;
	cin >> x;
	if(x != '/'){
		u = new BiNode;
		u->data = x;
		u->lChild = NULL;
		u->rChild = NULL;
		if(k == 1){
			q->lChild = u;
		}
		if(k == 2){
			q->rChild = u;
		}
		creatSubTree(u,1);  //递归创建u的左子树 
		creatSubTree(u,2);	//递归创建u的右子树 
	}
} 

//创建根节点 
void creatBiTree(BiNode *& BT){
	BiNode *p;
	char x;
	cout <<"creat Bitree with previous order:" <<endl;
	cin >> x;
	if(x == '/'){
		return;
	}
	BT = new BiNode;
	BT->data = x;
	BT->lChild = NULL;
	BT->rChild = NULL;
	p = BT;
	creatSubTree(p,1);
	creatSubTree(p,2);
} 


//二叉树的销毁
void destroyBiTree(BiNode *pBT){
	if(pBT){
		destroyBiTree(pBT->lChild); 
		destroyBiTree(pBT->rChild);
		delete pBT;
	}
} 


//求二叉树的节点数(中序遍历法)
void getNodeNum(BiNode *pBT,int &num){
	if(pBT != NULL){
		getNodeNum(pBT->lChild,num);
		num++;
		getNodeNum(pBT->rChild,num);
	}
} 


//求二叉树高度
int getBiTreeHeight(BiNode *pBT){
	int m,n;
	if(pBT == NULL){
		return 0;
	}
	m = getBiTreeHeight(pBT->lChild);
	n = getBiTreeHeight(pBT->rChild);
	if(m > n){
		return m + 1;
	}else{
		return n + 1;
	} 
}



/*线索二叉树 
求先序后继 
*/

TBiNode* preSuc(TBiNode *P){
	if(P->ltag == 0){
		return P->lChild;
	}else{
		return P->rChild;
	}
} 	

//求中序后继
TBiNode* inSuc(TBiNode *P){
	TBiNode *q = P->rChild;
	if(P->rtag == 1){
		return P->rChild;
	}else{
		while(q->ltag == 0){
			q = q->lChild; 
		}
		return q;
	}
}
//注：求先序前驱和后续后继是难以实现的


//先序遍历线索二叉树(非递归)
void preOrder(TBiNode *T){
	BiNode *p = T;
	while(p != NULL){
		visit(p);
		p = preSuc(p);
	}
}


//algorithms
//输出二叉树的所有叶子结点的值
void visit2(BiNode *T){
	if(T != NULL && T->lChild == NULL && T->rChild == NULL){
		cout << T->data <<endl; 
	}
} 

void leaf_node(BiNode *T){
	if(T){
		visit2(T);
		leaf_node(T->lChild);
		leaf_node(T->rChild);
	}
}

//输出二叉树中所有结点值及其对应层次/序号

void visit3(int num,int level){
	cout << "level: "<<level<<endl;
	cout << "num: " <<num<<endl;
}

void nodeLevelInfo(BiNode *T,int &num,int level){
	if(T){
		num++;	
		visit3(num,level);
		nodeLevelInfo(T->lChild,num,level + 1);
		nodeLevelInfo(T->rChild,num,level + 1);
	}
}


                                                                                                                                                                                                                                                                                                                                                                                                                                                            
int main(){
	
	//测试用例 
	BiNode *BT;
	creatBiTree(BT);
	preOrderTraverse(BT);
	
	return 0;

}



