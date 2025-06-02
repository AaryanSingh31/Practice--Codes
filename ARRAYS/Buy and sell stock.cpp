#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int> &price) //fn to perform operations.
{
  int minPrice = INT_MAX;         //initialising the minimum price for best buy
  int maxProfit = 0;

  for (int val : price)
  {    //finding the minimum price
    minPrice = min(minPrice, val);              
       //finding the maximum profit
    maxProfit = max(maxProfit, val - minPrice); 
  }
  cout << "Best buy value of stocks is : " << minPrice << endl; 
  cout << "Best sell value of stocks is : " << (minPrice + maxProfit) << endl; 
       //returning the maximum profit
  return maxProfit;    
}
int main()
{
  vector<int> price = {7, 1, 3, 5, 6, 4};  //initialising the price vector
  int result = maxProfit(price);           
  cout << "The Max Profit is : " << result << endl; 
  // output :-
  // Best buy value of stocks is : 1
  // Best sell value of stocks is : 6
  // The Max Profit is : 5
  return 0;
}
