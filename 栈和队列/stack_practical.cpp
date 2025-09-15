#include <iostream>
#include <stack>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include "def_seq_link_list.h"
 
using namespace std;
//进制转换（十进制转八进制）
void base_conversion(int n){
	stack<int> S;
	int mod,x;
	while(n != 0){
		mod = n % 8;
		S.push(mod);
		n = n/8;
	}
	
	while(!S.empty()){
		x = S.top();
		S.pop();
		cout<< x;
	}
} 


//八进制转十进制
int octalConversion(int octalNum){
	int decimalNum = 0;
	int base = 0;
	int remainder;
	while(octalNum != 0){
		remainder = octalNum % 10;
		decimalNum += remainder *pow(8,base);
		octalNum /= 10;
		base++; 
	}
	return decimalNum;
}


//链表的逆置（用栈实现） 
void reverseLlist(node *&L){
	node *rear,*u;
	u = L;
	stack<linklist> S;
	while(u){
		S.push(u);
		u = u->next;
	}
	if(S.empty()){
		return;
	}
	u = S.top();
	L = u;
	rear = u;
	u->next = NULL;
	S.pop();
	while(!S.empty()){
		u = S.top();
		rear->next = u;
		u->next = NULL;
		rear = u;
		S.pop();
	}
	
}




//括号匹配
bool  bracket_match(char str[]){
	stack<char> S;
	for(int i = 0;i < strlen(str);i++){
		if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
			S.push(str[i]);
		}else{
			if(S.empty()){
				return false;
			}
			char elemTop = S.top();
			S.pop();
			if(elemTop == '(' && str[i] != ')'){
				return false;
			}
			if(elemTop == '{' && str[i] != '}'){
				return false;
			}
			if(elemTop == '[' && str[i] != ']'){
				return false;
			}
		}	
	}
	if(S.empty()){
		return true;
	}else{
		return false;
	}
}


int main(){
	//括号匹配测试用例
	char str1[] = {'(','{','}',')'}; 
	char str2[] = {'(',']'}; 
	cout << bracket_match(str1) <<endl;
	cout << bracket_match(str2) <<endl;
	//进制转换测试用例 
	base_conversion(88);
	cout << octalConversion(130)<<endl;
	return 0;
}
