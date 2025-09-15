#include <iostream>
using namespace std;
#define MAXSIZE 100
typedef int Elemtype;
typedef struct{
	Elemtype data[MAXSIZE];
	int len;
}seqlist;

typedef struct linkNode{
	Elemtype data;
	struct linkNode *next;
}node;



//简单顺序查找
int seq_search(seqlist L,Elemtype key){
	int i = L.len;
	L.data[0] = key;
	while(L.data[i] != key){
		i--;
	}
	return i;
} 


//二分查找(递归)
int binary_search(seqlist L,datatype key,int high,int low){
	int mid;
	if(low > high){
		return -1;
	}else{
		mid = (low + high)/2;
		if(L.data[mid] == key){
			return mid;
		}
		if(L.data[mid] > key){
			return binary_search(L,key,mid - 1,low);
		}else{
			return binary_search(L,key,high,mid + 1);
			}
		}
	}	
} 


//二分查找（迭代）
int b_search(seqlist L,datatype key){
	int high = L.len - 1;
	int low = 0;
	int mid;
	
	while(low <= high){
		mid = (low + high)/2;
		if(L.data[mid] == key){
			return mid;
		}
		if(L.data[mid] > key){
			high = mid - 1;
		}else{
			low = mid + 1; 
		}	
	}
	return -1;
}














