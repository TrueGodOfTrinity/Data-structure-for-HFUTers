#ifndef _GRAPH_
#define _GRAPH_

//ͼ���ڽӾ����ʾ��
#define MaxVertexNum 100		//������Ŀ�����ֵ
typedef char VertexType;     	//�����Ӧ���������� 
typedef int EdgeType;			//�߶�Ӧ����������
typedef struct{
	VertexType vex[MaxVertexNum];	//����� 
	EdgeType edge[MaxVertexNum][MaxVertexNum];	//�ڽӾ��� 
	int vexnum;     //������ 
	int arcnum;		//����
}MGraph;

//ͼ���ڽӱ�
typedef struct ArcNode{     //�߱��� 
	int adjvex;				//�û�ָ��Ķ����λ�� 
	struct ArcNode *nextarc; //ָ����һ������ָ�� 
	//InfoType info;
}ArcNode;

typedef struct VNode{       //�����ڵ� 
	int data;		//�û�ָ��Ķ����λ�� //vertextype
	ArcNode *firstarc;		//ָ���һ�������û���ָ�� 
}VNode,AdjList[MaxVertexNum];

typedef struct{        
	AdjList vertices;		//�ڽӱ� 
	int vexnum;				//ͼ�Ķ����� 
	int arcnum;				//ͼ�Ļ��� 
}ALGraph;					//ALGraph�����ڽӱ�������� 

#endif
