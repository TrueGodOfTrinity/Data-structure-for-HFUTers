#ifndef BINARY_TREE


#define BINARY_TREE
typedef char Elemtype;

//�������Ĵ���ṹ 
typedef struct lBiNode{
	Elemtype data;
	struct lBiNode *lChild,*rChild;
}BiNode, *BiTree;

//��������
typedef struct TriNode {
	Elemtype data;
	struct TriNode *lChild, *rChild, *parent;
}TriBiNode ,*TriTree;

//����������
typedef struct TBiNode{
	Elemtype data;
	struct TBiNode *rChild,*lChild;
	int ltag,rtag;
}TBiNode, *TBiTree;

#endif
