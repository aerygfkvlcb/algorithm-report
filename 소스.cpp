//201935288 안지훈


#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BinaryTree.h"
using namespace std;
#define SIZE 20


void printArr(int* arr);
void selectionSort(int*);
void bubbleSort(int*);
void insertionSort(int*);
void mergeSort(int* arr, int start, int end);
void merge(int* arr, int start, int mid, int end);
void quickSort(int* arr, int start, int end);
int partition(int* arr, int start, int end);
void heapSort(int* arr, int n);
void buildHeap(int* arr, int n);
void heapify(int* arr, int k, int n);


int main()
{
	//nums[20] rand(1~100) array
	srand((unsigned int)time(NULL));
	int nums[SIZE] = { 0 };
	for (int i = 0; i < SIZE; i++) {
		int temp = rand() % 100 + 1;
		nums[i] = temp;
		for (int j = 0; j < i; j++) {
			if (nums[j] == temp) {
				i--;
			}
		}
	}
	cout << "난수배열" << endl;
	printArr(nums);

	//binary tree
	Node* rootNode = new Node;
	BinaryTree tree = BinaryTree(nums[0], rootNode);
	for (int i = 1; i < 20; i++)
		tree.AddNode(nums[i], rootNode);
	tree.DeleteNode(nums[15], rootNode);
	tree.SearchNode(nums[1], rootNode);
	tree.SearchNode(nums[15], rootNode);

	cout << endl;


	//Selection sort
	int selArr[SIZE];
	copy_n(nums, SIZE, selArr);
	selectionSort(selArr);
	cout << "선택정렬" << endl;
	printArr(selArr);


	//Bubble sort
	int bubArr[SIZE];
	copy_n(nums, SIZE, bubArr);
	bubbleSort(bubArr);
	cout << "버블정렬" << endl;
	printArr(bubArr);


	//Insertion sort
	int insertArr[SIZE];
	copy_n(nums, SIZE, insertArr);
	insertionSort(insertArr);
	cout << "삽입정렬" << endl;
	printArr(insertArr);


	//merge sort
	int mergeArr[SIZE];
	copy_n(nums, SIZE, mergeArr);
	mergeSort(mergeArr,0,SIZE-1);
	cout << "병합정렬" << endl;
	printArr(mergeArr);


	//quick sort
	int quickArr[SIZE];
	copy_n(nums, SIZE, quickArr);
	quickSort(quickArr, 0, SIZE - 1); 
	cout << "퀵정렬" << endl;
	printArr(quickArr);
	
	
	//heap sort
	int heapArr[SIZE];
	copy_n(nums, SIZE, heapArr);
	heapSort(heapArr, SIZE - 1); 
	cout << "힙정렬" << endl;
	printArr(heapArr);





	return 0;
}

//arr 출력
void printArr(int* arr) 
{
	for (int i = 0; i < SIZE; i++)
	{
		cout << "[" << i << "]" << ":" << arr[i] << "\t";
	}
	cout << endl << endl;
	return;
}



//선택정렬
void selectionSort(int* arr)
{	
	for (int i = SIZE-1; i > 0; i--) //19~1
	{
		int max = 0;
		for (int j = 1; j < i+1; j++) //1~19
		{
			if (arr[j] > arr[max]){
				max = j;
			}
		}		
		int tmp = arr[i];
		arr[i] = arr[max];
		arr[max] = tmp;
	}

	return;
}

//버블정렬
void bubbleSort(int* arr) 
{
	for (int i = 0; i < SIZE - 1; i++) //0~18
	{
		for (int j = 0; j < SIZE - 1 - i; j++) //0~19-i
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//삽입정렬
void insertionSort(int* arr) 
{
	for (int i = 1; i < SIZE; i++) //1,2,3,..,18,19
	{
		int insertValue = arr[i];
		for (int j = i-1; j>=0; j--) // 0,10,210,3210,..
		{
			if (arr[j] > insertValue){
				arr[j + 1] = arr[j];
				arr[j] = insertValue;
			}
		}
	}
}

//병합정렬
void mergeSort(int* arr, int start, int end) 
{
	if (start < end) {
		int mid = (start + end) / 2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid + 1, end);
		merge(arr, start, mid, end);
	}
}
void merge(int* arr, int start, int mid, int end)
{
	int i = start, j = mid + 1, t = start;
	int *tmp = new int[end + 1];
	while (i <= mid && j <= end) {
		if (arr[i] < arr[j]) {
			tmp[t++] = arr[i++];
		}
		else {
			tmp[t++] = arr[j++];
		}
	}
	
	while (i <= mid) {
		tmp[t++] = arr[i++];
	}

	while (j <= end) {
		tmp[t++] = arr[j++];
	}
	
	for (int k = start; k < end+1; k++) {
		arr[k] = tmp[k];
	}
}

//퀵정렬
void quickSort(int* arr, int start, int end) //배열, 시작0, 끝19
{
	if (start < end) {
		int mid = partition(arr, start, end);
		quickSort(arr, start, mid - 1);
		quickSort(arr, mid, end);
	}
}
int partition(int* arr, int start, int end)
{
	int x = arr[end];
	int i = start - 1;
	for (int j = start; j < end; j++) {
		if (arr[j] <= x) {
			int tmp = arr[++i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}
	}
	int tmp = arr[i + 1];
	arr[i + 1] = arr[end];
	arr[end] = tmp;
	return (i+1);
}

//힙정렬
void heapSort(int* arr, int n) 
{
	buildHeap(arr, n);
	for (int i = n; i > 0; i--) {
		int tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heapify(arr, 0, i - 1);
	}
}
void buildHeap(int* arr, int n)
{
	for (int i = (n / 2); i >= 0; i--) {
		heapify(arr, i, n);
	}
}
void heapify(int* arr, int k, int n) {
	int left = 2*k;
	int	right = 2*k + 1;
	int smaller;
	if (right <= n) {
		if (arr[left] < arr[right]) {
			smaller = left;
		}
		else {
			smaller = right;
		}
	}
	else if (left <= n) {
		smaller = left;
	}
	else return;
	if (arr[smaller] < arr[k]) {
		int tmp = arr[k];
		arr[k] = arr[smaller];
		arr[smaller] = tmp;
		heapify(arr, smaller, n);
	}
}