#include<iostream>
using namespace std;
int *tbl;
bool SubSum(int* arr, int size,int curr, int sum)
{
	if(sum == 0)
	{
		tbl[curr] = 1;
		return true; 
	}
	if(curr>=size)
	{
		tbl[curr] = false;
		return false;
	}
	if(tbl[curr]!= INT_MAX)
		return tbl[curr];
	//int incl = 0;
	if(arr[curr]>sum)
	{
		return SubSum(arr, size, curr+1, sum);
	}
	return (SubSum(arr, size, curr+1, sum - arr[curr])||SubSum(arr, size, curr+1, arr[curr]));
}
void main()
{
	int arr[] = {36,12,3 };
	int size = sizeof(arr)/sizeof(int);
	tbl = new int(size+1);
	for(int i=0;i<=size;i++)
	{
		tbl[i] = INT_MAX;
	}
	cout<<SubSum(arr, size, 0, 1541)<<endl;
}