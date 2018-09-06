#include <iostream>
#include <limits.h>
#include <vector>
#include <list>
#include <map>
using namespace std;

// m is size of coins array (number of different coins)
vector<int> minCoins(int coins[], int m, int V)
{
	cout<<__FUNCTION__<<" Entered"<<endl;
   // base case
   vector<int> solVector;/////
   if (V <= 0)
   {
	   return solVector;
   }
    //map<int,vector<int>> *table = new map<int,vector<int>>;

   // Initialize result
   // Try every coin that has smaller value than V
   vector<int>* solArr = new vector<int>[m];/////
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         solArr[i] = minCoins(coins, m, V-coins[i]);
		 //if(!solArr[i].empty())
         solArr[i].push_back(coins[i]);
		 
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         //if (sub_res != INT_MAX && sub_res + 1 < res)
         // res = sub_res + 1;
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
   
   return solArr[minIndex];
}


int main()
{
    //int coins[] =  {100, 36, 10,2};
	//int V = 114;
	int coins[] =  {13, 1, 4};
	int V = 14;
    int m = sizeof(coins)/sizeof(coins[0]);
    
    vector<int> result =  minCoins(coins, m, V);
    cout << "Minimum coins required is "<< result.size()<<endl;
    for(auto i:result)
    	cout<<i<<" ";
    return 0;
}

