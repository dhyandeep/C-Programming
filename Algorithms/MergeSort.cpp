#include <iostream>
#include <vector>
#include <string>
using namespace std;
int* Merge(int* arr, int start,int mid, int end)
{
	cout<<__FUNCTION__<<"Entered "<<" start = "<<start<<" mid = "<<mid<<" end = "<<end<<endl;
	int* result = new int[end - start - 1];
	int index = 0;
	int i,j;
	for(i = start,j = mid; (i<mid)&&(j<end); )
	{
		if(arr[i]<arr[j])
		{
			result[index] = arr[i];
			i++;
		}
		else
		{
			result[index] = arr[j];
			j++;
		}
		index++;
	}
	while(i<mid)
	{
		result[index] = arr[i];
		i++;
		index++;
	}
	while(j<end)
	{
		result[index] = arr[j];
		j++;
		index++;
	}
	for(i = 0,j = start; j < (end); i++,j++)
	{
		arr[j] = result[i];
	}
	return arr;
}
int* MergeSort(int* arr, int start,int end)
{
	cout<<__FUNCTION__<<"Entered "<<" start = "<<start<<" end = "<<end<<endl;
	int* result = nullptr;
	if(start<end)
	{
		MergeSort(arr, start, (start+end)/2);
		MergeSort(arr, (1+(start+end))/2,end);
		arr = Merge(arr,start,(start+end)/2, end);
	}

	return arr;
}
void main()
{
	int arr[] = {10, 5, 18, 9, 110, 17, 7, 20};
	int size = sizeof(arr)/sizeof(arr[0]);
	int* result = nullptr;
	result = MergeSort(arr,0,size);
	for(int i = 0;i<size;i++)
	{
		cout<<result[i]<<"\t";
	}
}