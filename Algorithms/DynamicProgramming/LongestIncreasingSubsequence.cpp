#include<iostream>
using namespace std;
int LargestSeq(int* arr,int size, int curr, int prev)
{
	if(curr == size)
		return 0;
	int included = 0;
	if(arr[curr]>prev)
	{
		included = 1+LargestSeq(arr,size,curr+1, arr[curr]);
	}
	int excluded = LargestSeq(arr,size,curr+1, prev);
	if(included>excluded)
		return included;
	else
		return excluded;
}
void main()
{
	int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 13, 3, 11, 7, 15};
	int size = sizeof(arr)/sizeof(int);
	cout<<LargestSeq(arr, size, 0, INT_MIN)<<endl;
}