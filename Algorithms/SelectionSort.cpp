#include <iostream>
#include <vector>
#include <string>
using namespace std;

int FindMinimumIndex(int* arr,int start, int size)
{
	int min = INT_MAX;
	int minIndex = 0;
	for(int i = start;i<size;i++)
	{
		if(arr[i]<min)
		{
			min = arr[i];
			minIndex = i;
		}

	}
	return minIndex;
}
int* swap(int* arr, int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
	return arr;
}
int* SelectionSort(int* arr, int size)
{
	for(int i = 0;i<size;i++)
	{
		int minIndex = FindMinimumIndex(arr,i,size);
		swap(arr, i,minIndex );
	}
	return arr;
}
void main()
{
	int arr[] = {10, 5, 18, 9, 110, 17, 7, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
	int* result = nullptr;
	result = SelectionSort(arr,size);
	for(int i = 0;i<size;i++)
	cout<<result[i]<<"\t";
	
}