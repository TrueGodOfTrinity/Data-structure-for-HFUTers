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

//简单插入排序
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
//二分插入排序 
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


//希尔排序 
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


//冒泡排序
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


//快速排序
void quickSort(table *tab,int left,int right){
	int i,j;
	if(left < right){
		i = left;j = right;
		//划分 
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
		//递归（左右半部分） 
		quickSort(tab,left,i - 1);
		quickSort(tab,i + 1,right);
	}
} 

//方法二 
int partition(int arr[], int low, int high) {
    int pivot = arr[low];  // 选择第一个元素作为pivot
    int i = low;           // 小于pivot的元素的索引，从low开始

    for (int j = low + 1; j <= high; j++) {
        if (arr[j] < pivot) {
            i++;
            // 交换arr[i]和arr[j]
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    // 将pivot放到正确的位置（交换arr[i]和arr[low]）
    int temp = arr[i];
    arr[i] = arr[low];
    arr[low] = temp;
    return i;  // 返回pivot的新位置
}
// 快速排序函数
void quicksort(int arr[], int low, int high) {
    if (low < high) {
        // 分区索引
        int pi = partition(arr, low, high);

        // 递归排序左半部分
        quicksort(arr, low, pi - 1);
        // 递归排序右半部分
        quicksort(arr, pi + 1, high);
    }
}


//简单选择排序 
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
 
 
//堆排序
//调整为大根堆 
void heapify(int arr[], int n, int i) {
    int largest = i;    // 初始化根节点为最大
    int left = 2 * i + 1;  // 左子节点
    int right = 2 * i + 2; // 右子节点

    // 如果左子节点存在且大于根节点
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // 如果右子节点存在且大于当前最大
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // 如果最大不是根节点，则交换并递归调整
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        heapify(arr, n, largest);  // 递归调整受影响的子堆
    }
} 
// 堆排序函数
void heapSort(int arr[], int n) {
    // 构建最大堆（从最后一个非叶子节点开始）
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // 逐个提取元素（从堆尾开始）
    for (int i = n - 1; i > 0; i--) {
        // 交换堆顶和堆尾
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // 调整缩小后的堆
        heapify(arr, i, 0);
    }
}


int main(){
	return 0;
}














