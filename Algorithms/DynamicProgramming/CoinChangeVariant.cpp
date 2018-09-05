#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

// m is size of coins array (number of different coins)
vector<int> minCoins(int coins[], int m, int V)
{
	cout<<__FUNCTION__<<" Entered"<<endl;
   // base case
   vector<int> solVector;/////
   if (V == 0)
   {
	   return solVector;
   }


   // Initialize result
   // Try every coin that has smaller value than V
   vector<int> solArr[m];/////
   for (int i=0; i<m; i++)
   {
     if (coins[i] <= V)
     {
         solArr[i] = minCoins(coins, m, V-coins[i]);
         solArr[i].push_back(coins[i]);
         // Check for INT_MAX to avoid overflow and see if
         // result can minimized
         //if (sub_res != INT_MAX && sub_res + 1 < res)
         // res = sub_res + 1;
     }
   }
   int min = solArr[0].size();
   int min_index = 0;
   for(int i = 0 ;i<m; i++)
   {
	   cout<<__FUNCTION__<<"finding minimum"<<solArr[i].size()<<endl;
	   if( (solArr[i].size()!=0) && (solArr[i].size() < min) )
	   {
		   min = solArr[i].size();
		   min_index = i;
	   }
   }
   return solArr[min_index];
}

// Driver program to test above function
int main()
{
    int coins[] =  {9, 6, 5, 1};
    int m = sizeof(coins)/sizeof(coins[0]);
    int V = 11;
    vector<int> result =  minCoins(coins, m, V);
    cout << "Minimum coins required is "<< result.size()<<endl;
    for(auto i:result)
    	cout<<i<<" ";
    return 0;
}

