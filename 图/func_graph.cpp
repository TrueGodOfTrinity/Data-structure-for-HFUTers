#include <iostream>
#include "graph.h"
#include <queue>
using namespace std;


//visit()函数 
void visit(ALGraph G,int verID){
	cout << G.vertices[verID - 1].data << "\t";
}    //邻接表 

void visit2(MGraph G,int i){
	cout << G.vex[i - 1];
} 	//邻接矩阵 


//访问标记数组 
bool visited[MaxVertexNum];   

//广度优先搜索（BFS）
 
//邻接表实现 
void BFS(ALGraph G,int verID){
	int u;
	ArcNode *p;
	
	queue<int> Q;
	visit(G,verID);
	visited[verID - 1] = true;
	Q.push(verID);
	
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		p = G.vertices[u - 1].firstarc;
		while(p){
			if(!visited[(p->adjvex) - 1]){
				visit(G,p->adjvex);
				visited[(p->adjvex) - 1] = true;
				Q.push(p->adjvex);
			}
			p = p->nextarc;			
		}	
	
	}
} 

//邻接矩阵实现

void BFS2(MGraph G,int i){
	int u; 
	visit2(G,i);
	visited[i - 1] = true;
	
	queue<int> Q;
	Q.push(i);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		for(int w = 0;w < G.vexnum;w++){
			if(visited[w] == false && G.edge[u - 1][w] == 1){
				visit2(G,w + 1);
				visited[w] = true;
				Q.push(w + 1);
			}
		} 
	} 
}



//深度优先搜索（DFS）
//邻接表实现
void DFS(ALGraph G,int verID){
	visit(G,verID);
	visited[verID - 1] = true;
	
	ArcNode *p;
	p = G.vertices[verID-1].firstarc;             
	while(p){
		if(!visited[p->adjvex - 1]){
			DFS(G,p->adjvex);
		}
		p = p->nextarc;
	}  
} 

//邻接矩阵实现
void DFS2(MGraph G,int verID){
	visit2(G,verID);
	visited[verID - 1] = true;
	
	for(int w = 0;w < G.vexnum;w++){
		if(G.edge[verID - 1][w] == 1&& visited[w] == false){  
			DFS2(G,w+1);
		}
	}

}


/*
设计算法, 按照BFS的基本方法判断有向图G是否是一棵以v0为根的有向树 
有向树：根节点入度为0，其他结点入度为1、连通 
*/
int directedTreeTest(ALGraph G,int root){
	
	int indegree[MaxVertexNum] = {0};   //储存入度
	//计算入度 
	for(int i = 0;i < G.vexnum;i++){
		VNode *p = &G.vertices[i];
		ArcNode *q = p->firstarc;
		while(q){
			indegree[q->adjvex]++;
			q = q->nextarc;
		}
	} 
	
	//检查入度
	if(indegree[root] != 0){
		return 0;
	} 
	
	for(int j = 0;j < G.vexnum;j++){
		if(j != root && indegree[j] != 1){
			return 0;
		}
	}
	
	//用BFS检查连通性
	int u;
	ArcNode *r;
	
	queue<int> Q;
	//这里不需要visit 
	visited[root - 1] = true;
	Q.push(root);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		r = G.vertices[u - 1].firstarc;
		while(r){
			if(!visited[r->adjvex - 1]){
		        //这里不需要visit() 
				visited[r->adjvex - 1] = true;
				Q.push(r->adjvex);
			}
			r = r->nextarc;
		}
	}
	for(int i = 0;i < G.vexnum;i++){
		if(visited[i] == false){
			return 0;
		}
	}
} 

//firstAdj(G,v)和nextAdj(G,v,w)的实现和应用
//邻接矩阵 
int firstAdj(MGraph G,int v){
	for(int u = 0;u < G.vexnum;u++){
		if(G.edge[v][u] != 0){
			return u;
		}
	}
	return 0; //此时不含邻接点 
}    

//邻接表
int firstAdj2(ALGraph G,int v){
	ArcNode *p = G.vertices[v - 1].firstarc;
	if(p){
		return p->adjvex;
	}
	return 0;
} 

//邻接矩阵
int nextAdj(MGraph G,int v,int w){
	for(int u = w + 1;u < G.vexnum;u++){
		if(G.edge[v][u] != 0){
			return u;
		}
	}
	return 0;
} 

//邻接表
int nextAdj2(ALGraph G,int v,int w){
	ArcNode *p = G.vertices[v - 1].firstarc;
	while(p != NULL){
		if(p->adjvex == w){
			return p->nextarc?p->nextarc->adjvex:0;
		}
		p = p->nextarc;
	}
	return 0;
} 





int main(){
	return 0;
}





  
