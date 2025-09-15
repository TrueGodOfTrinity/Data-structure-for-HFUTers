#include <iostream>
#include "graph.h"
#include <queue>
using namespace std;


//visit()���� 
void visit(ALGraph G,int verID){
	cout << G.vertices[verID - 1].data << "\t";
}    //�ڽӱ� 

void visit2(MGraph G,int i){
	cout << G.vex[i - 1];
} 	//�ڽӾ��� 


//���ʱ������ 
bool visited[MaxVertexNum];   

//�������������BFS��
 
//�ڽӱ�ʵ�� 
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

//�ڽӾ���ʵ��

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



//�������������DFS��
//�ڽӱ�ʵ��
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

//�ڽӾ���ʵ��
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
����㷨, ����BFS�Ļ��������ж�����ͼG�Ƿ���һ����v0Ϊ���������� 
�����������ڵ����Ϊ0������������Ϊ1����ͨ 
*/
int directedTreeTest(ALGraph G,int root){
	
	int indegree[MaxVertexNum] = {0};   //�������
	//������� 
	for(int i = 0;i < G.vexnum;i++){
		VNode *p = &G.vertices[i];
		ArcNode *q = p->firstarc;
		while(q){
			indegree[q->adjvex]++;
			q = q->nextarc;
		}
	} 
	
	//������
	if(indegree[root] != 0){
		return 0;
	} 
	
	for(int j = 0;j < G.vexnum;j++){
		if(j != root && indegree[j] != 1){
			return 0;
		}
	}
	
	//��BFS�����ͨ��
	int u;
	ArcNode *r;
	
	queue<int> Q;
	//���ﲻ��Ҫvisit 
	visited[root - 1] = true;
	Q.push(root);
	while(!Q.empty()){
		u = Q.front();
		Q.pop();
		r = G.vertices[u - 1].firstarc;
		while(r){
			if(!visited[r->adjvex - 1]){
		        //���ﲻ��Ҫvisit() 
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

//firstAdj(G,v)��nextAdj(G,v,w)��ʵ�ֺ�Ӧ��
//�ڽӾ��� 
int firstAdj(MGraph G,int v){
	for(int u = 0;u < G.vexnum;u++){
		if(G.edge[v][u] != 0){
			return u;
		}
	}
	return 0; //��ʱ�����ڽӵ� 
}    

//�ڽӱ�
int firstAdj2(ALGraph G,int v){
	ArcNode *p = G.vertices[v - 1].firstarc;
	if(p){
		return p->adjvex;
	}
	return 0;
} 

//�ڽӾ���
int nextAdj(MGraph G,int v,int w){
	for(int u = w + 1;u < G.vexnum;u++){
		if(G.edge[v][u] != 0){
			return u;
		}
	}
	return 0;
} 

//�ڽӱ�
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





  
