#include <string>
#include <iostream>
#include <math.h>
using namespace std;

string convertToTitle(int columnNumber) 
{
  string res = "";
  while(columnNumber > 26)
  {
    int index = 0;
    int i = columnNumber;
    while(i > 26)
    {
      i /= 26;
      ++index;
    }
    if(i % 26 == 0) i -= 1;
    res += static_cast<char>(64 + i);
    unsigned long long a = pow(26, index) * i;
    columnNumber -= a;
    
  }
  res += static_cast<char>(64 + columnNumber);
  return res;
}
int main()
{
  cout << convertToTitle(676);
  return 0;
}
