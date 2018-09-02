#include <iostream>
using namespace std;
int **visited = nullptr;
int** ReadMatrix(int m, int n)
{
	int** mat;
	mat = new int*[n];
	visited = (int**) malloc(n*sizeof(int*));
	for(int i=0;i<m;i++)
	{
		visited[i] = (int*)malloc(n*sizeof(int*));
	}
	for(int i=0;i<m;i++)
	{
		mat[i] = new int[m];
	}
	for(int i = 0;i < m;i++)
	{
		for(int j =0;j < n;j++)
		{
			visited[i][j] = 0;
			cin>>mat[i][j];
		}
	}
	return mat;
}
void PrintMatrix(int ** mat,int m,int n)
{
	for(int i=0;i<m;i++)
	{
		for(int j = 0; j<n; j++)
		{
			cout<<mat[i][j]<<"\t";
		}
		cout<<"\n";
	}
}

bool isValid(int** mat, int m_max, int n_max, int m, int n)
{
	if ((m>=0)&&(n>=0)&&(m<m_max)&&(n<n_max)&&(mat[m][n])&&!(visited[m][n]))
	{
		return true;
	}
	return false;
}
int FindLargestCluster(int** mat, int max_m, int max_n, int curr_m, int curr_n)
{
	int count = 0;
	if(isValid(mat,max_m,max_n,curr_m,curr_n))
	{
			visited[curr_m][curr_n] = 1;
			count = 1;
			if(isValid(mat,max_m,max_n,curr_m+1,curr_n+1))
			count += FindLargestCluster(mat,max_m,max_n,curr_m+1,curr_n+1);
			if(isValid(mat,max_m,max_n,curr_m+1,curr_n-1))
			count += FindLargestCluster(mat,max_m,max_n,curr_m+1,curr_n-1);
			if(isValid(mat,max_m,max_n,curr_m-1,curr_n+1))
			count += FindLargestCluster(mat,max_m,max_n,curr_m-1,curr_n+1);
			if(isValid(mat,max_m,max_n,curr_m-1,curr_n-1))
			count += FindLargestCluster(mat,max_m,max_n,curr_m-1,curr_n-1);
			if(isValid(mat,max_m,max_n,curr_m,curr_n+1))
			count += FindLargestCluster(mat,max_m,max_n,curr_m,curr_n+1);
			if(isValid(mat,max_m,max_n,curr_m,curr_n-1))
			count += FindLargestCluster(mat,max_m,max_n,curr_m,curr_n-1);
			if(isValid(mat,max_m,max_n,curr_m+1,curr_n))
			count += FindLargestCluster(mat,max_m,max_n,curr_m+1,curr_n);
			if(isValid(mat,max_m,max_n,curr_m-1,curr_n))
			count += FindLargestCluster(mat,max_m,max_n,curr_m-1,curr_n);
			return count;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int m,n;
	cout<<"Enter the number of rows and columns"<<endl;
	cin>>m>>n;

	int ** mat = ReadMatrix(m,n);
	PrintMatrix(mat,m,n);


	int max = -1;
	for(int i=0;i<m;i++)
	{
		for(int j = 0; j<n; j++)
		{

			int res = FindLargestCluster(mat,m,n,i,j);
			if(res>max)
				max = res;
		}
		cout<<"\n";
	}
	cout<<"max"<<max;
	return 0;
}

