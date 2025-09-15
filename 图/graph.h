#ifndef _GRAPH_
#define _GRAPH_

//图的邻接矩阵表示法
#define MaxVertexNum 100		//顶点数目的最大值
typedef char VertexType;     	//顶点对应的数据类型 
typedef int EdgeType;			//边对应的数据类型
typedef struct{
	VertexType vex[MaxVertexNum];	//顶点表 
	EdgeType edge[MaxVertexNum][MaxVertexNum];	//邻接矩阵 
	int vexnum;     //顶点数 
	int arcnum;		//边数
}MGraph;

//图的邻接表法
typedef struct ArcNode{     //边表结点 
	int adjvex;				//该弧指向的顶点的位置 
	struct ArcNode *nextarc; //指向下一条弧的指针 
	//InfoType info;
}ArcNode;

typedef struct VNode{       //顶点表节点 
	int data;		//该弧指向的顶点的位置 //vertextype
	ArcNode *firstarc;		//指向第一条依附该弧的指针 
}VNode,AdjList[MaxVertexNum];

typedef struct{        
	AdjList vertices;		//邻接表 
	int vexnum;				//图的顶点数 
	int arcnum;				//图的弧数 
}ALGraph;					//ALGraph是以邻接表储存的类型 

#endif
