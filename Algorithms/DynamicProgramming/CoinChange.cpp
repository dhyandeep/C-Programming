#include<iostream>
using namespace std;
int CoinChange(int arr[],int m,int n)
{
	int res;
	if(n==0)
	{
		return  1;
	}
	if(n <  0)
	{
		return 0;
	}
	
	else if((m<=0)&&(n>=1))
	{
		return 0;
	}
	else
	{
		res = CoinChange(arr,m-1,n)+CoinChange(arr,m,n-arr[m-1]);
	}
	return res;

}
int main()
{
	int n, m;
	int arr[10000];
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		cin>>arr[i];
	}
	cout<<"read input complete"<<endl;
	int res = CoinChange(arr,m,n);
	cout<<res;
	return res;
}

