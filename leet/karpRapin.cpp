#include <string>
#include <cmath>
#include <iostream>
using namespace std;
unsigned long long hashValue(string s, int m) 
{
  unsigned long long hash_val = 0;
  for(int i = 0; i < m; ++i)
  {
    hash_val *= 31 + (int) s[i];
  }
  return hash_val;
}

int strStr(string haystack, string needle) 
{
  int hLength = haystack.length();
  int nLength = needle.length();
  unsigned long long pattern = hashValue(needle, nLength);
  unsigned long long patternHash = 0;
  int result = -1;
  
  for(int i = 0; i <= hLength - nLength; ++i)
  {
    patternHash = hashValue(haystack.substr(i,nLength), nLength);
    if(pattern == patternHash && needle == haystack.substr(i,nLength)) return i;
  }
  return result;
}

int main() 
{
  string text = "edabsabcdfld";
  string patter = "abc";

  cout << strStr(text,patter) << "\n";
  return 0;
}

