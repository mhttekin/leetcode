#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;


vector<int> plusOne(vector<int>& digits) 
{
  int length = digits.size();
  for(int i = length - 1; i >= 0; --i)
  {
    if(digits[i] < 9)
    {
      digits[i] += 1;
      return digits;
    }
    digits[i] = 0;
  }
  digits.insert(digits.begin(), 1);
  return digits;
}


int main() 
{
  vector<int> digit = {6,1,4,5,3,9,0,1,9,5,1,8,6,7,0,5,0,0};
  digit = plusOne(digit);
  for(int c : digit) cout << c << " "; 
  return 0;
}
