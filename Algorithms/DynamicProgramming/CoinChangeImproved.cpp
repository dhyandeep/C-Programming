#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <map>
using namespace std;
pair<int,vector<int>> *table ;

vector<int> FindChange(int coins[], int m, int V)
{
	cout<<__FUNCTION__<<" Entered"<<endl;
   vector<int> solVector;
   if (V == 0)
   {
	   table[V].first = 0;
	   table[V].second = solVector;
	   return table[V].second;
   }
   if(table[V].first != INT_MAX)
	   return table[V].second;
   else
   {
	   vector<int>* solArr = new vector<int>[m];
	   for (int i=0; i<m; i++)
	   {
		 if (coins[i] <= V)
		 {
			 solArr[i] = FindChange(coins, m, V-coins[i]);
		 
			 solArr[i].push_back(coins[i]);
		 }
	   }
	   int minSize = INT_MAX;
	   int minIndex = 0;
	   for(int i = 0;i<m;i++)
	   {
		   if(!solArr[i].empty())
		   {
			   if(solArr[i].size()<minSize)
			   {
					minSize = solArr[i].size();
					minIndex = i;
			   }
		   }
	   }
	   table[V].first = solArr[minIndex].size();
	   table[V].second = (solArr[minIndex]);
	   delete[] solArr;
   }
   
   return table[V].second;
}


int main()
{
	int coins[] =  {100, 36, 10,2};
	int V = 8;
	table = new pair<int,vector<int>>[V+1];
	for(int i = 0;i <= V;i++)
		table[i].first = INT_MAX;
    int m = sizeof(coins)/sizeof(coins[0]);
    
    vector<int> result =  FindChange(coins, m, V);
    cout << "Change = "<< result.size()<<endl;
    for(auto i:result)
    	cout<<i<<" ";
    return 0;
}
