#include <vector>
#include <iostream>
using namespace std;


int maxProfit(vector<int>& prices) 
{
  int length = prices.size();
  if(length == 1) return 0;
  int buy = 0, profit = prices[0];
  for(int i= 1; i < length; ++i)
  {
    if(prices[i] < profit && i < length - 1 )
    {
      profit = prices[i];
    }
    if(prices[i] - profit > buy)
    {
      buy = prices[i] - profit;
    }
  }
  return buy;
}
// time limit exceeded, look for kadane's algorithm
int main() 
{
  vector<int> price {7,1,5,3,6,4};
  cout << maxProfit(price);
  return 0;
}
