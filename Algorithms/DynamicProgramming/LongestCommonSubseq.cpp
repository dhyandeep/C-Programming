#include <iostream>
using namespace std;
int LCSRecursive(char* arr1, int curr1, char* arr2, int curr2)
{
	if((curr1<0)||(curr2<0))
	{
		return 0;
	}
	if(arr1[curr1]==arr2[curr2])
	{
		return 1+LCSRecursive(arr1, curr1-1, arr2, curr2-1);
	}
	else
	{
		int firstexcl = LCSRecursive(arr1, curr1, arr2, curr2-1);
		int secondexcl = LCSRecursive(arr1, curr1-1, arr2, curr2);
		if(firstexcl>secondexcl)
			return firstexcl;
		else
			return secondexcl;
	}
}
int LCSDP(char* arr1, int size1, char* arr2, int size2)
{
	int **dp = new int*[size1+1];
	for(int i = 0; i<=size1; i++)
	{
		dp[i] = new int[size2+1];
	}
	for(int i = 0;i<=size1;i++)
	{
		for(int j = 0; j<=size2; j++)
		{
			if((i==0)||(j==0))
			{
				dp[i][j] = 0;
			}
			else
			{
				if(arr1[i]==arr2[j])
				{
					dp[i][j] = 1+dp[i-1][j-1];
				}
				else
				{
					int inclfirst = dp[i][j-1];
					int inclsecond = dp[i-1][j];
					if(inclfirst>inclsecond)
						dp[i][j]  = inclfirst;
					else
						dp[i][j] = inclsecond;
				}
			}
		}
	}
	return dp[size1][size2];
}
void main()
{
	char X[] = "AGGTAB"; 
	char Y[] = "GXTXAYB"; 
  
	int m = strlen(X); 
	int n = strlen(Y); 
	int result = LCSDP(X,m,Y,n);
	cout<<"Length of LCS = "<<result;
	getchar();
}