#include <iostream>
using namespace std;

void KnapSackDP(int W, int* wt, int* val, int n)
{
	int arr[100][100];
	for(int i=0;i<=n;i++)
	{
		for(int j=0; j<=W; j++)
		{
			if((i==0)||(j==0))
				arr[i][j] = 0;
			else if (wt[i-1]>W)
				arr[i][j] = arr[i-1][j];
			else
			{
				int excl = arr[i-1][j];
				int incl = arr[i-1][j-wt[i-1]]+val[i-1];
				if(excl>incl)
				{
					arr[i][j] = excl;
				}
				else
				{
					arr[i][j] = incl;
				}
			}
		}
	}
	cout<<arr[n][W];
}
void main()
{
	int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
	KnapSackDP(W, wt, val, 3);
}