#ifndef BINARY_TREE


#define BINARY_TREE
typedef char Elemtype;

//二叉树的储存结构 
typedef struct lBiNode{
	Elemtype data;
	struct lBiNode *lChild,*rChild;
}BiNode, *BiTree;

//三叉链表
typedef struct TriNode {
	Elemtype data;
	struct TriNode *lChild, *rChild, *parent;
}TriBiNode ,*TriTree;

//线索二叉树
typedef struct TBiNode{
	Elemtype data;
	struct TBiNode *rChild,*lChild;
	int ltag,rtag;
}TBiNode, *TBiTree;

#endif
