#include <iostream>
using namespace std;
int min(int a, int b, int c)
{
	int min = a;
	if(min>b)
	{
		min = b;
	}
	if(min>c)
	{
		min = c;
	}
	return min;
}
int EditDist(string str1, string str2,int len1, int len2)
{
	if(len1==0)
	{
		return len2;
	}
	else if(len2 == 0)
	{
		return len1;
	}
	else
	{
		if(str1[len1-1] == str2[len2-1])
		return EditDist(str1,str2, len1-1,len2-1);
		else
		{
			return 1+ min(EditDist(str1, str2, len1-1, len2), EditDist(str1, str2, len1, len2-1),EditDist(str1,str2, len1-1,len2-1));
		}
	}
}
int EditDistDP(string str1, string str2,int len1, int len2)
{
	int ** arr = (int**)malloc((len1+1)*sizeof(int*));
	for(int i =0;i<=len1;i++)
		arr[i] = (int*)malloc((len2+1) * sizeof(int*));
	for(int i=0;i<=len1;i++)
	{
		for(int j=0;j<=len2;j++)
		{
			if(i==0)
				arr[i][j] = j;
			else if(j==0)
				arr[i][j] = i;
			else
			{
				if(str1[i] == str2[j])
				{
					arr[i][j] = arr[i-1][j-1];
				}
				else
				{
					arr[i][j] = 1+min(arr[i-1][j],arr[i][j-1],arr[i-1][j-1]);
				}
			}
		}
	}
	return arr[len1][len2];
}

int main() 
{ 
    string str1 = "dhyan"; 
    string str2 = "deep"; 
    cout << EditDistDP( str1 , str2 , str1.length(), str2.length()); 
    return 0; 
} 
