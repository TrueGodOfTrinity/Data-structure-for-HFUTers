#include <iostream>

#define MAXSIZE 100
typedef int keytype;
typedef struct {
	keytype key;
	int other;
}recordtype; 

typedef struct {
	recordtype r[MAXSIZE + 1];
	int length;
}table;

using namespace std;

//�򵥲�������
void insertSort(table *tab){
	int i,j;
	for(i = 2;i <= tab->length;i++){
		j = i - 1; 
		tab->r[0] = tab->r[i];
		while(tab->r[0].key < tab->r[j].key){
			tab->r[j + 1] = tab->r[j];
			j--;
		}
		tab->r[j + 1] = tab->r[0];
	}
} 
//���ֲ������� 
void binarySort(table *tab){
	int i,j,left,right,mid;
	for(i = 2;i <= tab->length;i++){
		tab->r[0] = tab->r[i];
		left = 1,right = i - 1;
		while(left <= right){
			mid = (left + right)/2;
			if(tab->r[i].key < tab->r[mid].key){
				right = mid - 1;
			}else{
				left = mid + 1;
			}
		}
		for(j = i - 1;j >= left;j--){
			tab->r[j + 1] = tab->r[j];
		}
		tab->r[left] = tab->r[0];
	}
} 


//ϣ������ 
void shellSorting(table *tab){
	int i,j,d;
	d = tab->length/2;
	while(d >= 1){
		for(i = d + 1;i <= tab->length;i++){
			tab->r[0] = tab->r[i];
			j = i - d;
			while(j > 0&& tab->r[0].key < tab->r[j].key){
				tab->r[j + d] = tab->r[j];
				j = j - d;
			}
			tab->r[j + d] = tab->r[0];
		}
		d = d/2;
	}
}


//ð������
void bubbleSort(table *tab){
	int i,j,done;
	done = 1,i = 1;
	while(i <= tab->length && done){
		done = 0;
		for(j = 1;j <= tab->length - 1;j++){
			if(tab->r[j + 1].key < tab->r[j].key){
				tab->r[0] = tab->r[j];
				tab->r[j] = tab->r[j + 1];
				tab->r[j + 1] = tab->r[0];
				done = 1;
			}
		}
		i++;
	}
}


//��������
void quickSort(table *tab,int left,int right){
	int i,j;
	if(left < right){
		i = left;j = right;
		//���� 
		tab->r[0] = tab->r[i]; 
		do{
			while(tab->r[j].key > tab->r[0].key&&i < j){
				j--;
			}
			if(i < j){
				tab->r[i].key = tab->r[j].key;
				i++;
			}    
			while(tab->r[i].key < tab->r[0].key&&i < j){
				i++;
			}
			if(i < j){
				tab->r[j].key = tab->r[i].key;
				j--;
			}
		}while(i != j);    
		tab->r[i] = tab->r[0];    
		//�ݹ飨���Ұ벿�֣� 
		quickSort(tab,left,i - 1);
		quickSort(tab,i + 1,right);
	}
} 

//������ 
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // ѡ���һ��Ԫ����Ϊpivot
    int i = low;           // С��pivot��Ԫ�ص���������low��ʼ

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            // ����arr[i]��arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // ��pivot�ŵ���ȷ��λ�ã�����arr[i]��arr[low]��
    int temp = arr[i];
    arr[i] = arr[low];
    arr[low] = temp;
    return i;  // ����pivot����λ��
}
// ����������
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // ��������
        int pi = partition(arr, low, high);

        // �ݹ�������벿��
        quicksort(arr, low, pi - 1);
        // �ݹ������Ұ벿��
        quicksort(arr, pi + 1, high);
    }
}


//��ѡ������ 
void selectSort(table *tab){
	int i,j,min;
	for(i = 1;i <= tab->length - 1;i++){
		min = i;
		for(j = i + 1;j <= tab->length;j++){
			if(tab->r[j].key < tab->r[min].key){
				min = j;
			}
		} 
		if(min != i){
			tab->r[0] = tab->r[min];
			tab->r[min] = tab->r[i];
			tab->r[i] = tab->r[0];
		} 
	}	
}
 
 
//������
//����Ϊ����� 
void heapify(int arr[], int n, int i) {
    int largest = i;    // ��ʼ�����ڵ�Ϊ���
    int left = 2 * i + 1;  // ���ӽڵ�
    int right = 2 * i + 2; // ���ӽڵ�

    // ������ӽڵ�����Ҵ��ڸ��ڵ�
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // ������ӽڵ�����Ҵ��ڵ�ǰ���
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // �������Ǹ��ڵ㣬�򽻻����ݹ����
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);  // �ݹ������Ӱ����Ӷ�
    }
} 
// ��������
void heapSort(int arr[], int n) {
    // �������ѣ������һ����Ҷ�ӽڵ㿪ʼ��
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // �����ȡԪ�أ��Ӷ�β��ʼ��
    for (int i = n - 1; i > 0; i--) {
        // �����Ѷ��Ͷ�β
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // ������С��Ķ�
        heapify(arr, i, 0);
    }
}


int main(){
	return 0;
}














