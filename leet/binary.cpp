#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
//fail
//
string binary(string &h, string &l)
{
  int hL = h.length(), lL = l.length();
  int lIndex = 0;
  int overload = 0;
  while(lIndex < lL)
  {
    char &numH = h[hL-1-lIndex], 
         &numL = l[lL-1-lIndex];
    if((numH == '0' || numL == '0') && overload == 0)
    {
      numH > numL ? numH = numH : numH = numL;
    }
    else if((numH == '0' || numL == '0') && overload == 1)
    {
      numH = (numH - '0') + (numL - '0') + overload;
      if(numH > 1)
      {
        numH = 0;
      }
      else overload = 0;
    }
    else
    {
      numH = '0';
      overload = 1;
    }

    lIndex += 1;
  }
  
  if(overload == 1)
  {
    cout << "result " << h[0] << "\n";
    if(h[hL-lIndex-1] == '1')  h[hL-lIndex-1] = '0'; 
    reverse(h.begin(), h.end()); 
    h+= '1';
    reverse(h.begin(),h.end());
  }
  return h;
}

string addBinary(string a, string b)
{
  int aL = a.length(), bL = b.length();
  string res = "";
  
  if(aL > bL) res = binary(a,b);
  else res = binary(b,a);

  return res;

  
}

int main()
{
  string a = "11", b = "1";
  string res = addBinary(a,b);
  cout << "\n" << res;
  return 0;
}


