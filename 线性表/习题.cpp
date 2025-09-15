#include <cstdio>
#include <cstdlib>
#include "def_seq_link_list.h"
#include <iostream>
using namespace std;

//2.3��˳���ʵ�ּ��ϣ������������Ȳ���
//���������ϵĽ���
sequence_list intersection(sequence_list p,sequence_list q){
	sequence_list r;
	r.size = 0;   //���������ʹ��vector<>,�������ӷ��� 

	for(int i = 0;i < p.size;i++){
		for(int j = 0;j <= q.size;j++){
			if(p.a[i] == q.a[j]){
				r.a[r.size++] = p.a[i];
				break;   //�ҵ��������ڶ���ѭ�� 
			}
		}
	}
	return r;
}

//������	
sequence_list difference(sequence_list p,sequence_list q){
	sequence_list r;
	r.size = 0;
	for(int i = 0;i < p.size;i++){
		bool isINQ = false;
		for(int j = 0;j < q.size;j++){
			if(p.a[i] == q.a[j]){
				isINQ = true;
				break;
			}
		}
		if(!isINQ){
			r.a[r.size++] = p.a[i];   //ע������ط���r��size++����i 
		}
	}
	return r;
}

 

//2.7ɾ���ظ���Ԫ�أ�ʱ�临�Ӷ�ΪO(n^2)�� 
void delete_the_same(sequence_list &p){
	for(int i = 0;i < p.size;i++){
		for(int j = i + 1;j < p.size;){
			if(p.a[i] == p.a[j]){
				for(int k = j+1;k < p.size;k++){
					p.a[k - 1] = p.a[k]; 
				}
				p.size--; 
			}else{
				j++;
			}
		}
	}
}

//2.12������ѭ������ϳ�һ����ѭ������
//���������ָ�붼���ѽ����õ�ѭ�������� 
node *Merging_Llist(node *firstHead,node *secondHead){
	if(firstHead == NULL){
		return secondHead;
	}
	if(secondHead == NULL){
		return firstHead;
	}
	node *firstRear,*secondRear;
	while(firstRear->next != NULL){
		firstRear = firstRear->next;
	}
	while(secondRear->next != NULL){
		secondRear = secondRear->next;
	}
	firstRear->next = secondHead;
	secondRear->next = firstHead;
	return firstHead;
}
 
//2.13�����ʾ���ϣ��ж�setA�Ƿ���setB���Ӽ�
//�жϺ���
bool elem_Comprise(node *head,Elemtype data){
	node *q = head;
	while(q){
		if(q->info == data){
			return true;
		}else{
			q = q->next;
		}
	}
	return false;
}

int set_Judgement(node *setAHead,node *setBHead){
	node *p = setAHead;
	if(!p){
		return 1;
	}
	while(p){
		if(!elem_Comprise(setBHead,p->info)){
			return 0;
		}
		p = p->next;
	}
	return 1;
}


//2.20�ϲ�������������
node *merging_ordered_Llist(node *firstHead,node *secondHead){
	if(!firstHead && !secondHead){
		return NULL;
	}
	if(!firstHead){
		return secondHead;
	}
	if(!secondHead){
		return firstHead;
	}
	if(firstHead->info > secondHead->info){
		firstHead->next = merging_ordered_Llist(firstHead->next,secondHead);
		return firstHead;
	}else{
		secondHead->next = merging_ordered_Llist(firstHead,secondHead->next);
		return secondHead;
	}
}


//2.21ʵ����������
node *reverseList(node *head){
	if(!head || !head->next){
		return head;
	}
	node *pre, *cur;
	pre = NULL;
	cur = head;

	while(cur){
		node *nxt = cur->next; //�ؼ�����ǰ�ڵ�ָ��ǰһ���ڵ㣨ʵ�����ã�
		cur->next = pre;     
		pre = cur;
		cur = nxt;
	}
	return pre;
}
		
		
		
//�ݹ�ʵ��
node *reverseList2(node *head){
	if(!head || !head->next){
		return head;
	}
    
    node *new_Node = reverseList2(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_Node;
}




int main(){
	
	
	
	//2.7�������� 
	sequence_list p;
	int arr[18] = {1,1,2,2,2,3,4,5,5,5,6,6,7,7,8,8,8,9};
	for(int i = 0; i < p.size ;i++){
		p.a[i] = arr[i];
	}
	p.size = 18;
	delete_the_same(p);
	for(int i = 0; i < p.size ;i++){
		cout<< p.a[i] <<endl;
	}
	return 0;
}

